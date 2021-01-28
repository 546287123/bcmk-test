
#ifndef EXECUTER_BASE_H
#define EXECUTER_BASE_H

#include "../common/action_def.h"

class ExecuterBase {
public:
ExecuterBase(){};
virtual ~ExecuterBase(){};
public:
virtual bool DoAction(cmd_info &info) = 0;
};

#endif