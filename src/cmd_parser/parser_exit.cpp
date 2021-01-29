
#include "parser_exit.h"

bool ParserExit::DoParser(std::string cmd, cmd_info &info) {
    bool ret = true;
    info.description = "this is an Exit cmd";
    info.type = cmd_type::cmd_exit;
    if(cmd != "exit") {
        info.description = "this is not an Exit cmd";
        info.type = cmd_type::cmd_error;
        ret  = false;
    }
    return ret;
}