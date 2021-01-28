
#include "cmd_executer_mgr.h"
#include "cmd_executer_exit.h"
#include "cmd_executer_doaction.h"
#include "cmd_executer_error.h"

ExecuterMgr &ExecuterMgr::GetInstance() {
    static ExecuterMgr instance;
    return instance;
}

shared_ptr<ExecuterBase> ExecuterMgr::GetExecuter(cmd_info info) {
    shared_ptr<ExecuterBase> executer;
    switch (info.type)
    {
    case cmd_exit:
        executer.reset(new ExecuterExit());
        break;
    case cmd_do_action:
        executer.reset(new ExecuterDoAction());
        break;
    default:
        executer.reset(new ExecuterError());
        break;
    }
    return executer;
}
