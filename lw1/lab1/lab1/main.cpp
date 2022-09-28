#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "ConsoleCommand.h"
#include <fstream> 

using namespace std;

string const Input_File = "test.txt";
string const Output_File = "output.txt";

int main()
{
	ifstream inputFile(Input_File);
	ofstream outputFile(Output_File);
	CConsoleCommand consoleCommand;
	consoleCommand.DoCommand(inputFile, outputFile);

	consoleCommand.DrawShapes();

	return 0;
}