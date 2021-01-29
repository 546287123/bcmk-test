
#include "parser_error.h"

bool ParserError::DoParser(std::string cmd, cmd_info &info) {
    info.description = "this is an Error cmd";
    info.type = cmd_type::cmd_error;
    return true;
}