#ifndef PARSER_EXIT_H
#define PARSER_EXIT_H

#include "parser_base.h"

class ParserExit : public ParserBase{
public:
ParserExit(){};
virtual ~ParserExit(){};
public:
virtual bool DoParser(string cmd, cmd_info &info);
};

#endif