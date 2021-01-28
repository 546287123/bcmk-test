
#ifndef PARSER_DOACTION_H
#define PARSER_DOACTION_H
#include "parser_base.h"

class ParserDoaction : public ParserBase{
public:
ParserDoaction(){};
virtual ~ParserDoaction(){};
public:
virtual bool DoParser(string cmd, cmd_info &info);
private:
bool CkeckActionCmd(string cmd, cmd_info &info);
};

#endif