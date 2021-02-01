
#ifndef CMD_TASK_LIST_H
#define CMD_TASK_LIST_H

#include "../common/action_def.h"
#include <string>
#include <vector>
#include <map>
#include <mutex>

typedef bool (*TraceCB)(std::string str);

class CmdTaskList {
public:
    CmdTaskList(){};
    ~CmdTaskList(){};
    static CmdTaskList &GetInstance();
public:
    bool SetCB(TraceCB trace_cb);
    bool Add(cmd_task_info info);
    bool GetCur(cmd_task_info &info);
    bool GetNext(cmd_task_info &info);
    bool UpdateTask(cmd_task_info info);
    bool TraceAll();
private:
    TraceCB _trace_cb = NULL;
    std::mutex _task_mutex;
private:
    std::map<int, cmd_task_info> _task_map;
    std::vector<int> _ready_list;
    std::vector<int> _done_list;
    int _cur_task_id;
};

#endif