
#include "parser_error.h"

bool ParserError::DoParser(string cmd, cmd_info &info) {
    info.dscription = "this is a Error cmd";
    return true;
}