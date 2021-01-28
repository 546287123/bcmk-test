
#ifndef PARSER_MGR_H
#define PARSER_MGR_H

#include "parser_base.h"
#include <memory>

using namespace std;

class ParserMgr {
public:
ParserMgr(){};
~ParserMgr(){};
static ParserMgr &GetInstance();
public:
shared_ptr<ParserBase> GetOneParser(cmd_type type);
};

#endif