
#ifndef CMD_PLUG_SHELL_H
#define CMD_PLUG_SHELL_H

#include "cmd_plug_base.h"

class CmdPlugShell : public CmdPlugBase
{
public:
    CmdPlugShell(){};
    ~CmdPlugShell(){};
public:
    virtual bool AnalyseCmd(std::string cmd, cmd_info &info);
    virtual bool ExecuteCmd(cmd_info &info);
    virtual bool Exit();

};


#endif

