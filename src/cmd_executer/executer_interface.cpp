
#include "executer_interface.h"
#include "executer_mgr.h"

ExecuterInterface &ExecuterInterface::GetInstance() {
    static ExecuterInterface instance;
    return instance;
}

bool ExecuterInterface::DoAction(cmd_info &info) {
    shared_ptr<ExecuterBase> executer = ExecuterMgr::GetInstance().GetExecuter(info);
    bool ret = executer->DoAction(info);
    return ret;
}