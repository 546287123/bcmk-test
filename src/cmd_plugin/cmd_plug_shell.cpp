
#include "cmd_plug_shell.h"
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <string.h>

bool CmdPlugShell::AnalyseCmd(std::string cmd, cmd_info &info) {
    return true;
}

bool CmdPlugShell::ExecuteCmd(cmd_info info) {
    int count = info.cmds->size();
    for(int i=0; i<count; i++) {
        std::string cmd = info.cmds->at(i);
        FILE *pp = popen((char*)cmd.c_str(), "r");
        if (!pp) {
            return -1;
        }
        std::vector<std::string> vec;
        char tmp[1024] = {"0"};
        while (fgets(tmp, sizeof(tmp), pp) != NULL) {
            if (tmp[strlen(tmp)-1] == '\n') {
                tmp[strlen(tmp)-1] = '\0';
            }
            vec.push_back(std::string(tmp));
        }
        //
        pclose(pp); //关闭管道
        //
        for(auto it=vec.begin(); it!=vec.end(); it++) {
            std::cout << *it << std::endl;
        }
        //
    }

    return true;
}

bool CmdPlugShell::Exit() {
    
    return true;
}