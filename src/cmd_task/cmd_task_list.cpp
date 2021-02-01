
#include "cmd_task_list.h"
#include <strstream>

CmdTaskList &CmdTaskList::GetInstance() {
    static CmdTaskList instance;
    return instance;
}

bool CmdTaskList::SetCB(TraceCB trace_cb) {
    _trace_cb = trace_cb;
    return true;
}

bool CmdTaskList::Add(cmd_task_info info) {
    std::unique_lock<std::mutex> lock(_task_mutex);
    _ready_list.push_back(info.task_id);
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
    if(_trace_cb) {
        _trace_cb(ss.str());
    }
    return true;
}