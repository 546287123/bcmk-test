#include <iostream>
#include <string>
#include "cmd_parser/cmd_parser_interface.h"

using namespace std;

int main(int argc, char *argv[])
{
	while (true) {
		string cmd;
		cin >> cmd;
		cmd_info info = CmdParser::GetInstance().DoParser(cmd);
		cout << info.dscription << endl;
	}
	std::cout << "Hello world!" << std::endl;
}