
#include "cmd_executer_exit.h"
#include "../cmd_task/cmd_task_mgr.h"

bool ExecuterExit::DoAction(cmd_info &info){
    bool ret = false;
    if(info.type==cmd_type::cmd_exit) {
        info.description = "bool ExecuterExit::DoAction(cmd_info &info) starting";
        ret = true;
        CmdTaskMgr::GetInstance().Stop();
    }
    return ret;
}