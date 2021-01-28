
#include "parser_doaction.h"

bool ParserDoaction::CkeckActionCmd(string cmd, cmd_info &info) {
    bool ret = true;
    if(cmd.length()) {
        ret = true;
    }
    return ret;
}

bool ParserDoaction::DoParser(string cmd, cmd_info &info) {
    bool ret = true;
    info.dscription = "this is a DoAction cmd";
    info.type = cmd_type::cmd_do_action;
    if(!CkeckActionCmd(cmd, info)) {
        ret = false;
    }
    return ret;
}