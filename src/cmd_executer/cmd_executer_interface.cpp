
#include "cmd_executer_interface.h"
#include "executer_mgr.h"

CmdExecuter &CmdExecuter::GetInstance() {
    static CmdExecuter instance;
    return instance;
}

bool CmdExecuter::DoAction(cmd_info &info) {
    shared_ptr<ExecuterBase> executer = ExecuterMgr::GetInstance().GetExecuter(info);
    bool ret = executer->DoAction(info);
    return ret;
}