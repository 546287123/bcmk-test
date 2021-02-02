
#include "cmd_task_mgr.h"
#include "cmd_task_list.h"
#include "cmd_task_runner.h"

CmdTaskMgr &CmdTaskMgr::GetInstance() {
    static CmdTaskMgr instance;
    return instance; 
}

bool CmdTaskMgr::Start() {
    CmdTaskRunner::GetInstance().Start();
    return true;
}

bool CmdTaskMgr::Stop() {
    CmdTaskRunner::GetInstance().Stop();
    return true;
}

bool CmdTaskMgr::Quit() {
    CmdTaskRunner::GetInstance().Stop();
    CmdTaskList::GetInstance().Clear();
    return true;
}

bool CmdTaskMgr::SkipCur() {
    CmdTaskRunner::GetInstance().SkipCur();
    return true;
}

bool CmdTaskMgr::AddOne(cmd_task_info info) {
    CmdTaskList::GetInstance().Add(info);
    return true;
}

bool CmdTaskMgr::SetCallback(TaskMgrCB log_cb, TaskMgrCB cb) {
    CmdTaskList::GetInstance().SetLogCB(log_cb);
    CmdTaskRunner::GetInstance().SetActionCB(cb);
    return true;
}