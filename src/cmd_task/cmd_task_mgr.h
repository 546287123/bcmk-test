
#ifndef CMD_TADK_MGR_H
#define CMD_TADK_MGR_H

#include "../common/action_def.h"
#include <vector>
#include <map>

using namespace std;

class CmdTaskMgr {
public:
    CmdTaskMgr(){};
    ~CmdTaskMgr(){};
    static CmdTaskMgr &GetInstance();
public:
    bool Start();
    bool Stop();
    bool Quit();
    bool TraceTask();
    bool AddOne(cmd_task_info info);
    bool RemoveOne(cmd_task_info info);     
    bool ReadyOne(cmd_task_info info);
    bool StopCurrent();
private:
    bool TraceReadyTask();
    bool TraceRunningTask();
    bool TraceOverTask();
    bool TraceDoneTask();
private:
    map<int, cmd_task_info> _all_task;
    vector<int> _ready_task;
    vector<int> _running_task;
    vector<int> _over_task;
};

#endif