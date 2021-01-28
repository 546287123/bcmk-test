
#ifndef CMD_TASK_BASE_H
#define CMD_TASK_BASE_H

#include "../common/action_def.h"
#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

using namespace std;

class CmdTaskRunner {
public:
    CmdTaskRunner();
    virtual ~CmdTaskRunner();
public:
    virtual bool Start();
    virtual bool Stop();
    virtual bool Quit();
    virtual shared_ptr<cmd_task_info> GetTaskInfo();
protected:
    void run();
protected:
    cmd_task_info _task_info;
    shared_ptr<thread> _runner;
};

#endif