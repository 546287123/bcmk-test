
#include "cmd_task_runner.h"
#include "cmd_task_list.h"

CmdTaskRunner &CmdTaskRunner::GetInstance() {
    static CmdTaskRunner instance;
    return instance;
}

bool CmdTaskRunner::SetActionCB(TaskMgrCB action_cb) {
    bool bRet = false;
    if(action_cb) {
        _action_cb = action_cb;
        bRet = true;
    }
    return bRet;
}

bool CmdTaskRunner::Start() {
    _thread = thread(&CmdTaskRunner::run, this);
    _thread.detach();
    return true;
}

bool CmdTaskRunner::Stop() {
    _over = true;
    return true;
}

bool CmdTaskRunner::SkipCur() {
    return true;
}

shared_ptr<cmd_task_info> CmdTaskRunner::GetTask() {
    return _task;
}

bool CmdTaskRunner::SetTask(shared_ptr<cmd_task_info> task) {
    _task = task;
    return true;
}

void CmdTaskRunner::run() {
    
    return;
}