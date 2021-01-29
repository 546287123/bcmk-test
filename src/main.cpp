#include <iostream>
#include <string>
#include "cmd_parser/cmd_parser_interface.h"
#include "cmd_executer/cmd_executer_interface.h"

using namespace std;

int main(int argc, char *argv[])
{
	while (true) {
		string cmd;
		cin >> cmd;
		cmd_info info = CmdParser::GetInstance().DoParser(cmd);
		cout << info.description << endl;
		bool ret = CmdExecuter::GetInstance().DoAction(info);
		cout << info.description << endl;
		if(ret) {
			if(info.type==cmd_type::cmd_exit) {
				break;
			}
		}
	}
	std::cout << "AllStopped!" << std::endl;
}