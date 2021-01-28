
#ifndef EXECUTER_INTERFACE_H
#define EXECUTER_INTERFACE_H

#include "../common/action_def.h"

class ExecuterInterface{
public:
ExecuterInterface(){};
~ExecuterInterface(){};
static ExecuterInterface &GetInstance();
public:
bool DoAction(cmd_info &info);
};
#endif