
#include "cmd_task_list.h"
#include <strstream>

CmdTaskList &CmdTaskList::GetInstance() {
    static CmdTaskList instance;
    return instance;
}

bool CmdTaskList::SetLogCB(TaskMgrCB log_cb) {
    bool bRet = false;
    if(_log_cb) {
        _log_cb = log_cb;
        bRet = true;
    }
    return bRet;
}

bool CmdTaskList::Add(cmd_task_info info) {
    std::unique_lock<std::mutex> lock(_task_mutex);
    _ready_list.push_back(info.task_id);
    _task_map[info.task_id] = info;
    _ready_task_count++;
    _wait_over = 1;
    _cv_run.notify_all();
    return true;
}

bool CmdTaskList::GetCur(cmd_task_info &info) {
    std::unique_lock<std::mutex> lock(_task_mutex);
    bool bRet = false;
    auto it = _task_map.find(_cur_task_id);
    if(it!=_task_map.end()) {
        info = it->second;
        bRet = true;
    }
    return bRet;
}

bool CmdTaskList::GetNext(cmd_task_info &info) {
    std::unique_lock<std::mutex> lock(_task_mutex);
    bool bRet = false;
    int id = _ready_list.front();
    auto it = _task_map.find(id);
    if(it!=_task_map.end()) {
        info = it->second;
        bRet = true;
        _ready_list.erase(std::begin(_ready_list));
        _ready_task_count--;
    }
    return bRet;
}

bool CmdTaskList::UpdateTask(cmd_task_info info) {
    std::unique_lock<std::mutex> lock(_task_mutex);
    bool bRet = false;
    auto it = _task_map.find(info.task_id);
    if(it!=_task_map.end()) {
        bRet = true;
        switch (info.status) {
            case cmd_task_running:
                _task_map[info.task_id] = info;
                _done_list.push_back(_cur_task_id);
                _cur_task_id = info.task_id;
                break;
            case cmd_task_done:
                _task_map[info.task_id] = info;
                break;
            default:
                bRet = false;
                break;
        }
    }
    return bRet;
}

bool CmdTaskList::TraceAll() {
    std::strstream ss;
    {
        std::unique_lock<std::mutex> lock(_task_mutex);
        ss << "total task count:\t" << _task_map.size() << std::endl;
        ss << "ready task count:\t" << _ready_list.size() << std::endl;
        ss << "current task id:\t" << _cur_task_id << std::endl;
        ss << "done task count:\t" << _done_list.size() << std::endl;
    }
    if(_log_cb) {
        _log_cb(ss.str());
    }
    return true;
}

bool CmdTaskList::Clear() {
    std::unique_lock<std::mutex> lock(_task_mutex);
    _task_map.clear();
    _ready_list.clear();
    _done_list.clear();
    _ready_task_count = 0;
    _cur_task_id = -1;
    _wait_over = 1;
    _cv_run.notify_all();
    return true;
}

bool CmdTaskList::WaitforNewTask() {
    bool bRet = false;
    std::unique_lock<std::mutex> lock(_mt_run);
    _cv_run.wait(lock, [&]{ return _wait_over;});
    _wait_over = 0;
    if(_ready_task_count>0){
        bRet = true;
    }
    return bRet;
}