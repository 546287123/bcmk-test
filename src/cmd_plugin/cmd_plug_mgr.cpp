
#include "cmd_plug_mgr.h"
#include "cmd_plug_shell.h"
#include "cmd_plug_python.h"
#include "../cmd_config/cmd_config_tools.h"

CmdPlugMgr &CmdPlugMgr::GetInstance() {
    static CmdPlugMgr instance;
    return instance;
}

bool CmdPlugMgr::AnalyseCmd(std::string cmd, cmd_info &info) {
    bool ret = true;
    task_config task_cfg;
    CmdConfigTools::GetInstance().LoadFromJson(cmd, task_cfg);
    // info.type = ;
    info.cmds = CmdConfigTools::GetInstance().GenerateCmds(task_cfg);
    info.env = task_cfg.env;
    info.cmd_json = cmd;
    info.description = task_cfg.description;
    if(!info.ResetPlugType(task_cfg.run_type)){
        cout << "run_type error " << task_cfg.run_type << std::endl;
        ret = false;
    }
    return ret;
}

bool CmdPlugMgr::ExecuteCmd(cmd_info info) {

    return true;
}