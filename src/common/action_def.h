
#ifndef ACTION_DEF_H
#define ACTION_DEF_H

#include <string>
#include <vector>
#include <memory>
#include <map>

enum cmd_type {
    cmd_exit,
    cmd_do_action,
    cmd_error,
    cmd_end,
};

enum plug_type {
    plug_type_shell,
    plug_type_python,
    plug_type_end,
};

static std::string plug_type_desp[plug_type_end] = {
    "shell",
    "python",
};

struct res_boult {
    std::string key;
    std::string sep;
    std::string end;
};

struct cmd_info {
    cmd_type type;
    plug_type p_type;
    std::string cmd_json;
    std::shared_ptr<std::vector<std::string>> cmds;
    std::string env;
    std::string description;
    //
    std::vector<res_boult> boults;
    std::vector<std::string> results;
    std::string result_file;
    //
    bool ResetPlugType(std::string run_type) {
        bool ret = false;
        for(int i=0; i<plug_type::plug_type_end; i++) {
            if(plug_type_desp[i]==run_type) {
                p_type = plug_type(i);
                ret = true;
            }
        }
        return ret;
    }

};

enum cmd_task_status {
    cmd_task_ready,
    cmd_task_running,
    cmd_task_done,
    cmd_task_end,
};

struct cmd_task_info {
    int task_id;
    cmd_info info;
    cmd_task_status status;

    int GetNewTaskID() {
        static int nTaskId = 0;
        nTaskId++;
        return nTaskId;
    }
};

typedef bool (*TaskMgrCB)(std::string str);

#endif