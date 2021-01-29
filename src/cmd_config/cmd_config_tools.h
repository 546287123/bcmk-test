
#ifndef CMD_CONFIG_TOOLS_H
#define CMD_CONFIG_TOOLS_H

#include "cmd_config.h"

using namespace shine;

class ParamGenerBase {
public:
    ParamGenerBase(){};
    virtual ~ParamGenerBase(){};
public:
    virtual std::shared_ptr<std::vector<std::string>> GeneratePars(param par) = 0;
};

class ParamGenerFixed : public ParamGenerBase {
public:
    ParamGenerFixed(){};
    virtual ~ParamGenerFixed(){};
public:
    virtual std::shared_ptr<std::vector<std::string>> GeneratePars(param par);
};

class ParamGenerEnumed : public ParamGenerBase {
public:
    ParamGenerEnumed(){};
    virtual ~ParamGenerEnumed(){};
public:
    virtual std::shared_ptr<std::vector<std::string>> GeneratePars(param par);
};

class ParamGenerFromTo : public ParamGenerBase {
public:
    ParamGenerFromTo(){};
    virtual ~ParamGenerFromTo(){};
public:
    virtual std::shared_ptr<std::vector<std::string>> GeneratePars(param par);
};

class CmdConfigTools
{
public:
    CmdConfigTools(){};
    ~CmdConfigTools(){};
    static CmdConfigTools &GetInstance();
public:
    std::shared_ptr<std::vector<std::string>> GeneratePars(param par);
    std::shared_ptr<std::vector<std::string>> GenerateCmds(task_config task_cfg);
    
};



#endif