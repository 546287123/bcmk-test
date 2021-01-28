
#ifndef EXECUTER_DOACTION_H
#define EXECUTER_DOACTION_H

#include "cmd_executer_base.h"

class ExecuterDoAction : public ExecuterBase {
public:
ExecuterDoAction(){};
~ExecuterDoAction(){};
public:
virtual bool DoAction(cmd_info &info);
};

#endif