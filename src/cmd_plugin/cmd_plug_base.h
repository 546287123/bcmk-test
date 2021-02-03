
#ifndef CMD_PLUG_BASE_H
#define CMD_PLUG_BASE_H

#include "../common/action_def.h"

class CmdPlugBase
{
public:
    CmdPlugBase(){};
    ~CmdPlugBase(){};
public:
    virtual bool AnalyseCmd(std::string cmd, cmd_info &info) = 0;
    virtual bool ExecuteCmd(cmd_info &info) = 0;
    virtual bool Exit() = 0;
};

#endif