
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

bool CmdTaskMgr::TraceTask() {
    return true;
}

bool CmdTaskMgr::AddOne(cmd_task_info info) {
    return true;
}

bool CmdTaskMgr::RemoveOne(cmd_task_info info) {
    return true;
}

bool CmdTaskMgr::ReadyOne(cmd_task_info info) {
    return true;
}

bool CmdTaskMgr::StopCurrent() {
    return true;
}


bool CmdTaskMgr::TraceReadyTask() {
    return true;
}

bool CmdTaskMgr::TraceRunningTask() {
    return true;
}

bool CmdTaskMgr::TraceOverTask() {
    return true;
}

bool CmdTaskMgr::TraceDoneTask() {
    return true;
}