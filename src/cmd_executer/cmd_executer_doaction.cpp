
#include "cmd_executer_doaction.h"
#include "../cmd_task/cmd_task_mgr.h"

bool ExecuterDoAction::DoAction(cmd_info &info) {
    bool ret = false;
    if(info.type==cmd_type::cmd_do_action) {
        info.description = "bool ExecuterDoAction::DoAction(cmd_info &info) starting";
        cmd_task_info task_info;
        task_info.task_id = task_info.GetNewTaskID();
        task_info.info = info;
        task_info.status = cmd_task_status::cmd_task_ready;
        CmdTaskMgr::GetInstance().AddOne(task_info);
        ret = true;
        
    }
    return ret;
}