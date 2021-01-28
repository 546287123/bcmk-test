
#include "parser_exit.h"

bool ParserExit::DoParser(string cmd, cmd_info &info) {
    bool ret = true;
    info.dscription = "this is an Exit cmd";
    info.type = cmd_type::cmd_exit;
    if(cmd != "exit") {
        info.dscription = "this is not an Exit cmd";
        info.type = cmd_type::cmd_error;
        ret  = false;
    }
    return ret;
}