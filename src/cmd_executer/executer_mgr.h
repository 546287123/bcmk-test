
#ifndef EXECUTER_MGR_H
#define EXECUTER_MGR_H

#include "executer_base.h"
#include <memory>

using namespace std;

class ExecuterMgr {
public:
ExecuterMgr(){};
~ExecuterMgr(){};
static ExecuterMgr &GetInstance();

public:
shared_ptr<ExecuterBase> GetExecuter(cmd_info info);

};

#endif