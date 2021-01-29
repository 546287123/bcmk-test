
#ifndef CMD_PARSER_INTERFACE_H
#define CMD_PARSER_INTERFACE_H
#include "parser_base.h"

class CmdParser{
public:
CmdParser(){};
~CmdParser(){};
static CmdParser &GetInstance();
public:
cmd_info DoParser(std::string cmd);
};

#endif