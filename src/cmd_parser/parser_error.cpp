
#include "parser_error.h"

bool ParserError::DoParser(string cmd, cmd_info &info) {
    info.dscription = "this is an Error cmd";
    info.type = cmd_type::cmd_error;
    return true;
}