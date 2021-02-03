
#include "cmd_plug_mgr.h"
#include "cmd_plug_shell.h"
#include "cmd_plug_python.h"
#include "../cmd_config/cmd_config_tools.h"
#include "../common/action_def.h"

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
    info.boults.clear();
    for(auto res : task_cfg.results) {
        res_boult boult;
        boult.key = res.key;
        boult.sep = res.sep;
        boult.end = res.end;
        info.boults.push_back(boult);
    }
    if(!info.ResetPlugType(task_cfg.run_type)){
        cout << "run_type error " << task_cfg.run_type << std::endl;
        ret = false;
    }
    return ret;
}

bool CmdPlugMgr::ExecuteCmd(cmd_info &info) {
    std::shared_ptr<CmdPlugBase> plug;
    switch (info.p_type)
    {
    case plug_type_shell:
        plug.reset(new CmdPlugShell());
        break;
    case plug_type_python:
        plug.reset(new CmdPlugPython());
        break;
    default:
        break;
    }

    if(plug) {
        plug->ExecuteCmd(info);
    }

    return true;
}

bool CmdPlugMgr::Exit() {
    
    return true;
}