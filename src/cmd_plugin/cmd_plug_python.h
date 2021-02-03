
#ifndef CMD_PLUG_PYTHON_H
#define CMD_PLUG_PYTHON_H

#include "cmd_plug_base.h"

class CmdPlugPython : public CmdPlugBase
{
public:
    CmdPlugPython(){};
    ~CmdPlugPython(){};
public:
    virtual bool AnalyseCmd(std::string cmd, cmd_info &info);
    virtual bool ExecuteCmd(cmd_info &info);
    virtual bool Exit();
};

#endif