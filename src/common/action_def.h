
#ifndef ACTION_DEF_H
#define ACTION_DEF_H

#include <string>
#include <vector>

using namespace std;

enum cmd_type {
    cmd_exit,
    cmd_do_action,
    cmd_error,
    cmd_end,
};

struct cmd_info {
    cmd_type type;
    vector<string> cmd_vec;
    string dscription;
};

enum cmd_task_status {
    cmd_task_empty,
    cmd_task_ready,
    cmd_task_running,
    cmd_task_done,
    cmd_task_outputting,
    cmd_task_over,
    cmd_task_end,
};

struct task_result {
    string description;
    string throughput;
    string latency;
};

struct cmd_task_info {
    int task_id;
    cmd_info info;
    cmd_task_status status;
    task_result result;
};

#endif