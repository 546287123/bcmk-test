
#include "cmd_task_mgr.h"

CmdTaskMgr &CmdTaskMgr::GetInstance() {
    static CmdTaskMgr instance;
    return instance; 
}

bool CmdTaskMgr::Start() {
    return true;
}

bool CmdTaskMgr::Stop() {
    return true;
}

bool CmdTaskMgr::Quit() {
    return true;
}
    
bool CmdTaskMgr::SkipCur() {
    return true;
}

bool CmdTaskMgr::AddOne(cmd_task_info info) {
    return true;
}

//
bool CmdTaskMgr::SetCallback(TaskMgrCBLog log_cb, TaskMgrCB cb) {
    return true;
}
//