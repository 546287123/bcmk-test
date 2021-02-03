
#ifndef CMD_PLUG_MGR_H
#define CMD_PLUG_MGR_H

#include "../common/action_def.h"
#include <string>
#include <memory>

using namespace std;

class CmdPlugMgr
{
public:
    CmdPlugMgr(){};
    ~CmdPlugMgr(){};
    static CmdPlugMgr &GetInstance();
public:
    bool AnalyseCmd(string cmd, cmd_info &info);
    bool ExecuteCmd(cmd_info &info);
    bool Exit();
};

#endif