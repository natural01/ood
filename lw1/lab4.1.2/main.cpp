#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "ConsoleCommand.h"

using namespace std;

int main()
{
	CConsoleCommand consoleCommand;
	consoleCommand.DoCommand(cin);
	consoleCommand.GetShapeInfo(consoleCommand);

	return 0;
}