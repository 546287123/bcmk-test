
#include "cmd_executer_error.h"

bool ExecuterError::DoAction(cmd_info &info) {
    bool ret = false;
    if(info.type==cmd_type::cmd_error) {
        info.description = "bool ExecuterExit::DoAction(cmd_info &info) starting";
        ret = true;
        //todo start a thread to do the work
    }
    return ret;
}