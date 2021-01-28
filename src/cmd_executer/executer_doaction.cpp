
#include "executer_doaction.h"

bool ExecuterDoAction::DoAction(cmd_info &info) {
    bool ret = false;
    if(info.type==cmd_type::cmd_do_action) {
        info.dscription = "bool ExecuterDoAction::DoAction(cmd_info &info) starting";
        ret = true;
        //todo start a thread to do the work
    }
    return ret;
}