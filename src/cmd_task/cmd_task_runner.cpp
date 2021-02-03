
#include "cmd_task_runner.h"
#include "cmd_task_list.h"
#include "../cmd_plugin/cmd_plug_mgr.h"
#include "../cmd_config/cmd_config_tools.h"

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
    CmdTaskList::GetInstance().Clear();
    CmdPlugMgr::GetInstance().Exit();
    return true;
}

bool CmdTaskRunner::SkipCur() {
    return true;
}

void CmdTaskRunner::run() {
    while (true) {
        if(!CmdTaskList::GetInstance().WaitforNewTask()) {
            break;
        }
        cmd_task_info info;
        if(CmdTaskList::GetInstance().GetNext(info)) {
            info.status = cmd_task_status::cmd_task_running;
            CmdTaskList::GetInstance().UpdateTask(info);
            std::string str;
            if(CmdPlugMgr::GetInstance().ExecuteCmd(info.info)) {
                if(CmdConfigTools::GetInstance().JuiceResult(info.info)) {
                   std::cout << info.info.cmd_json << "\tDone!" << std::endl;
                }
            }
        }
    }
    return;
}