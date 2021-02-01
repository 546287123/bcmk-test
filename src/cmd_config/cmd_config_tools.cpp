
#include "cmd_config_tools.h"
#include <iostream>
#include <fstream>

std::shared_ptr<std::vector<std::string>> ParamGenerFixed::GeneratePars(param par) {
    std::shared_ptr<std::vector<std::string>> ret(new std::vector<std::string>());
    ret->push_back(par.fixed.value);
    return ret;
}

std::shared_ptr<std::vector<std::string>> ParamGenerEnumed::GeneratePars(param par) {
    std::shared_ptr<std::vector<std::string>> ret(new std::vector<std::string>());
    for(auto enum_v : par.enumed.values) {
        ret->push_back(enum_v);
    }
    return ret;
}

std::shared_ptr<std::vector<std::string>> ParamGenerFromTo::GeneratePars(param par) {
    std::shared_ptr<std::vector<std::string>> ret(new std::vector<std::string>());
    for(int i=par.fromto.from; i<par.fromto.to; i+=par.fromto.step) {
        ret->push_back(std::to_string(i));
    }
    return ret;
}

CmdConfigTools &CmdConfigTools::GetInstance() {
    static CmdConfigTools instance;
    return instance;
}

std::shared_ptr<std::vector<std::string>> CmdConfigTools::GeneratePars(param par) {
    //
    std::shared_ptr<std::vector<std::string>> pars;
    std::shared_ptr<ParamGenerBase> par_gener;
    //
    switch (par.par_mod)
    {
    case PARAM_CHG_M_FIXED:
        par_gener.reset(new ParamGenerFixed);
        break;
    case PARAM_CHG_M_ENUM:
        par_gener.reset(new ParamGenerEnumed);
        break;
    case PARAM_CHG_M_FROMTO:
        par_gener.reset(new ParamGenerFromTo);
        break;
    case PARAM_CHG_M_END:
        break;
    default:
        break;
    }
    //
    if(par_gener) {
        pars = par_gener->GeneratePars(par);
    }
    return pars;
}

std::shared_ptr<std::vector<std::string>> CmdConfigTools::GenerateCmds(task_config task_cfg) {
    std::shared_ptr<std::vector<std::string>> cmds(new std::vector<std::string>());
    std::vector<std::shared_ptr<std::vector<std::string>>> par_mat;
    std::vector<int> counts;
    int total = 1;
    for(auto par : task_cfg.params) {
        std::shared_ptr<std::vector<std::string>> pars = GeneratePars(par);
        par_mat.push_back(pars);
        total *= pars->size();
        counts.push_back(pars->size());
    }
    //
    while(total--) {
        std::string cmd = task_cfg.program;
        bool chg = false;
        for(int i=0; i<counts.size(); i++) {
            cmd += " ";
            if(!chg) {
                if(counts.at(i)>1) {
                    chg = true;
                }
            }
            cmd += par_mat.at(i)->at(counts.at(i)-1);
        }
        cmds->push_back(cmd);
    }
    //
    return cmds;
}

bool CmdConfigTools::LoadFromJson(std::string file, task_config &task_cfg) {
    //
    // DoOneSaveTest(file);
    //
    bool ret = false;
    std::string str;
    std::ifstream ifs(file.c_str(), std::ios::in);
    std::string line;
    while (ifs>>line) {
        str += line;
    }
    ifs.close();
    if(str.length()) {
        task_cfg.json_decode(str);
        ret = true;
    }
    return ret;
}

bool CmdConfigTools::SaveToJson(std::string file, task_config task_cfg) {
    bool ret = false;
    std::string str = task_cfg.json_encode();
    std::ofstream ofs(file.c_str(), std::ios::out);
    if(ofs.is_open()) {
        ofs << str;
        ret = true;
    }
    ofs.close();
    return ret;
}

bool CmdConfigTools::DoOneSaveTest(std::string file) {
    bool ret = false;
    task_config task_cfg;
    param par[5];
    for(int i=0; i<5; i++) {
        task_cfg.params.push_back(par[i]);
    }
    ret = SaveToJson(file, task_cfg);
    return true;
}