
#include "parser_doaction.h"
#include "../cmd_plugin/cmd_plug_mgr.h"

bool ParserDoaction::CkeckActionCmd(string cmd, cmd_info &info) {
    bool ret = false;
    if(cmd.length()) {
        if(CmdPlugMgr::GetInstance().AnalyseCmd(cmd, info)){
            ret = true;
        }
    }
    return ret;
}

bool ParserDoaction::DoParser(string cmd, cmd_info &info) {
    bool ret = true;
    info.description = "this is a DoAction cmd";
    info.type = cmd_type::cmd_do_action;
    if(!CkeckActionCmd(cmd, info)) {
        ret = false;
    }
    return ret;
}