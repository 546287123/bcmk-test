
#include "cmd_executer_exit.h"

bool ExecuterExit::DoAction(cmd_info &info){
    bool ret = false;
    if(info.type==cmd_type::cmd_exit) {
        info.dscription = "bool ExecuterExit::DoAction(cmd_info &info) starting";
        ret = true;
        //todo start a thread to do the work
    }
    return ret;
}