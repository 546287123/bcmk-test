
#include "cmd_task_runner.h"

bool CmdTaskRunner::Start() {
    bool ret = false;
    if(_task_info.status==cmd_task_status::cmd_task_ready) {
        //todo 任务执行
        _task_info.status = cmd_task_running;
        ret = true;
    }
    return ret;
}

bool CmdTaskRunner::Stop() {
    bool ret = false;
    if(_task_info.status==cmd_task_status::cmd_task_running) {
        //todo 任务停止
        _task_info.status = cmd_task_ready;
        ret = true;
    }
    return ret;
}

bool CmdTaskRunner::Quit() {
    bool ret = false;
    if(true) {
        //todo 任务取消
        _task_info.status = cmd_task_empty;
        ret = true;
    }
    return ret;
}

shared_ptr<cmd_task_info> CmdTaskRunner::GetTaskInfo() {
    shared_ptr<cmd_task_info> info;
    info.reset(new cmd_task_info(_task_info));
    return info;
}

void CmdTaskRunner::run() {
    //todo execute cmd using poen
//     cmd_task_info _task_info;
// shared_ptr<thread> _runner;
}