
#ifndef PARSER_ERROR_H
#define PARSER_ERROR_H

#include "parser_base.h"

class ParserError : public ParserBase{
public:
ParserError(){};
virtual ~ParserError(){};
public:
virtual bool DoParser(string cmd, cmd_info &info);
};

#endif