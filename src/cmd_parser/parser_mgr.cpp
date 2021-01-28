
#include "parser_mgr.h"
#include "parser_exit.h"
#include "parser_error.h"
#include "parser_doaction.h"

ParserMgr &ParserMgr::GetInstance() {
    static ParserMgr instance;
    return instance;
}

shared_ptr<ParserBase> ParserMgr::GetOneParser(cmd_type type) {
    shared_ptr<ParserBase> parser;
    switch (type)
    {
    case cmd_type::cmd_exit:
        parser.reset(new ParserExit());
        break;
    case cmd_type::cmd_do_action:
        parser.reset(new ParserDoaction());
        break;
    default:
        parser.reset(new ParserError());
        break;
    }
    return parser;
}