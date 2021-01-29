
#pragma once

#include <fstream>
#include <string>

bool ReadAllIn(std::string path, std::string &str) {
    bool bRet = false;
    str.clear();
    std::ifstream ifs(path, std::ios::in);
    if(ifs) {
        std::string s;
        while(!ifs.eof()) {
            ifs >> s;
            str += s;
        }
        bRet = true;
    }
    ifs.close();
    return bRet;
}
