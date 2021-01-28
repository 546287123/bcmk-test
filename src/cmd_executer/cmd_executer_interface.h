
#ifndef EXECUTER_INTERFACE_H
#define EXECUTER_INTERFACE_H

#include "../common/action_def.h"

class CmdExecuter{
public:
CmdExecuter(){};
~CmdExecuter(){};
static CmdExecuter &GetInstance();
public:
bool DoAction(cmd_info &info);
};
#endif