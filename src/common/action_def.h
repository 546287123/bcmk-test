
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

#endif