
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
    std::string value;
    SHINE_JSON_MODEL(Fixed, value);
}

struct Enumed {
    std::vector<std::string> values;
    SHINE_JSON_MODEL(Enumed, values);
};

struct FromTo {
    int from;
    int to;
    int step;
    SHINE_JSON_MODEL(FromTo, from, to, step);
};

struct param {
    int par_type;
    int par_mod;
    Fixed fixed;
    Enumed enumed;
    FromTo fromto;
    std::string dscription;
    SHINE_JSON_MODEL(param, par_type, par_mod, fixed, enumed, fromto, dscription);
};

struct task_config {
	std::string program;
    std::vector<param> params;
    std::string env;
    std::string dscription;
	SHINE_JSON_MODEL(task_config, program, params, env, dscription);
};

#endif