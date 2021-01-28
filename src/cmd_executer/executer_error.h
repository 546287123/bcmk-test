
#ifndef EXECUTER_ERROR_H
#define EXECUTER_ERROR_H

#include "executer_base.h"

class ExecuterError : public ExecuterBase
{
public:
    ExecuterError(){};
    ~ExecuterError(){};
public:
    virtual bool DoAction(cmd_info &info);
};


#endif