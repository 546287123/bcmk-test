
#ifndef PARSER_BASE_H
#define PARSER_BASE_H

#include <string>

using namespace std;

enum cmd_type {
    cmd_exit,
    cmd_do_action,
    cmd_error,
    cmd_end,
};

struct cmd_info {
    cmd_type type;
    string dscription;
};

class ParserBase{
public:
ParserBase(){};
virtual ~ParserBase(){};
public:
virtual bool DoParser(string cmd, cmd_info &info) = 0;
};

#endif