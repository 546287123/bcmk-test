
#ifndef EXECUTER_EXIT_H
#define EXECUTER_EXIT_H

#include "cmd_executer_base.h"

class ExecuterExit : public ExecuterBase
{
public:
ExecuterExit(){};
~ExecuterExit(){};
public:
virtual bool DoAction(cmd_info &info);
};


#endif