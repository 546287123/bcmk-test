
#ifndef CMD_TADK_MGR_H
#define CMD_TADK_MGR_H

#include "../common/action_def.h"
#include <vector>
#include <map>
#include <thread>
#include <mutex>

using namespace std;

typedef bool (*TaskMgrCBLog)(std::string str);
typedef bool (*TaskMgrCB)(std::string str);

class CmdTaskMgr {
public:
    CmdTaskMgr(){};
    ~CmdTaskMgr(){};
    static CmdTaskMgr &GetInstance();
public:
    bool Start();
    bool Stop();
    bool Quit();
    bool SkipCur();
    bool AddOne(cmd_task_info info);
    //
    bool SetCallback(TaskMgrCBLog log_cb, TaskMgrCB cb);
    //
};

#endif