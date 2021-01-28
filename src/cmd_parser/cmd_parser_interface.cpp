
#include "cmd_parser_interface.h"
#include "parser_mgr.h"

CmdParser &CmdParser::GetInstance() {
    static CmdParser instance;
    return instance;
}

cmd_info CmdParser::DoParser(string cmd){
    cmd_info info;
    for(int i=0; i<cmd_type::cmd_end; i++) {
        cmd_type t = cmd_type(i);
        shared_ptr<ParserBase> parser = ParserMgr::GetInstance().GetOneParser(t);
        if(parser->DoParser(cmd, info)) {
            break;
        }
    }
    return info;
}