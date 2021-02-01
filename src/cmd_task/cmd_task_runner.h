
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
    CmdTaskRunner(){};
    virtual ~CmdTaskRunner(){};
public:
    bool Start();
    bool Stop();
    bool SkipCur();
    shared_ptr<cmd_task_info> GetTask();
    bool SetTask(shared_ptr<cmd_task_info> task);
protected:
    void run();
protected:
    shared_ptr<cmd_task_info> _task;
    thread _thread;
    volatile int _over = false;
};

#endif