
#ifndef CMD_CONFIG_H
#define CMD_CONFIG_H

#include "../../include/json.hpp"
#include <vector>
#include <string>
#include <memory>

using namespace shine;

enum param_type {
    PARAM_TYPE_STR,
    PARAM_TYPE_INT,
    PARAM_TYPE_END,
};

enum param_chg_mod {
    PARAM_CHG_M_FIXED,
    PARAM_CHG_M_ENUM,
    PARAM_CHG_M_FROMTO,
    PARAM_CHG_M_END,
};

struct Fixed {
    std::string value = "FixedValue";
    SHINE_JSON_MODEL(Fixed, value);
}

struct Enumed {
    std::vector<std::string> values = {"EnumedValue0","EnumedValue1"};
    SHINE_JSON_MODEL(Enumed, values);
};

struct FromTo {
    int from = 0;
    int to = 520;
    int step = 1;
    SHINE_JSON_MODEL(FromTo, from, to, step);
};

struct param {
    int par_type = param_type::PARAM_TYPE_STR;
    int par_mod = param_chg_mod::PARAM_CHG_M_FIXED;
    Fixed fixed;
    Enumed enumed;
    FromTo fromto;
    std::string description = "Param Description";
    SHINE_JSON_MODEL(param, par_type, par_mod, fixed, enumed, fromto, description);
};

struct task_config {
	std::string program = "./benchmark/localmemory";
    std::string run_type = "shell"; //shell or python
    std::vector<param> params;
    std::string env = "env";
    std::string description = "Task Config Description";
	SHINE_JSON_MODEL(task_config, program, run_type, params, env, description);
};

#endif