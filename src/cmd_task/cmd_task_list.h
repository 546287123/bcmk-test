
#ifndef CMD_TASK_LIST_H
#define CMD_TASK_LIST_H

#include "../common/action_def.h"
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <condition_variable>

class CmdTaskList {
public:
    CmdTaskList(){};
    ~CmdTaskList(){};
    static CmdTaskList &GetInstance();
public:
    bool SetLogCB(TaskMgrCB log_cb);
    bool Add(cmd_task_info info);
    bool GetCur(cmd_task_info &info);
    bool GetNext(cmd_task_info &info);
    bool UpdateTask(cmd_task_info info);
    //
    bool TraceAll();
    bool Clear();
    //
    bool WaitforNewTask();
private:
    TaskMgrCB _log_cb = NULL;
    std::mutex _task_mutex;
    //
    std::condition_variable _cv_run;
    std::mutex _mt_run;
    volatile int _ready_task_count = 0;
    volatile int _wait_over = 0;
    //
private:
    std::map<int, cmd_task_info> _task_map;
    std::vector<int> _ready_list;
    std::vector<int> _done_list;
    int _cur_task_id;
};

#endif