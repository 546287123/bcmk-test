
#ifndef PARSER_BASE_H
#define PARSER_BASE_H

#include <string>
#include "../common/action_def.h"

class ParserBase{
public:
ParserBase(){};
virtual ~ParserBase(){};
public:
virtual bool DoParser(std::string cmd, cmd_info &info) = 0;
};

#endif