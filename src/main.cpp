#include <iostream>
#include <string>
#include "cmd_parser/cmd_parser_interface.h"
#include "cmd_executer/cmd_executer_interface.h"
#include "cmd_task/cmd_task_mgr.h"

using namespace std;

bool log_cb(std::string str) {
	std::cout << str << endl;
	return true;
}

bool action_cb(std::string str) {
	std::cout << str << endl;
	return true;
}

int main(int argc, char *argv[])
{
	//
	CmdTaskMgr::GetInstance().SetCallback(log_cb, action_cb);
	CmdTaskMgr::GetInstance().Start();
	//

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

	//
	CmdTaskMgr::GetInstance().Stop();
	//

	std::cout << "AllStopped!" << std::endl;
}