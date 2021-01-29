
#include "cmd_plug_mgr.h"

CmdPlugMgr &CmdPlugMgr::GetInstance() {
    static CmdPlugMgr instance;
    return instance;
}

bool CmdPlugMgr::AnalyseCmd(string cmd, cmd_info &info) {
    return true;
}

bool CmdPlugMgr::ExecuteCmd(cmd_info info) {
    return true;
}