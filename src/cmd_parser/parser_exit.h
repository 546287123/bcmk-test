#ifndef PARSER_EXIT_H
#define PARSER_EXIT_H

#include "parser_base.h"
#include <thread>

class ParserExit : public ParserBase{
public:
    ParserExit(){};
    virtual ~ParserExit(){};
public:
    virtual bool DoParser(std::string cmd, cmd_info &info);
private:
    void Do(cmd_info &info);
};

#endif