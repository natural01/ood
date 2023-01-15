#include "TextReader.h"

vector<shared_ptr<ShapeDecorator>> TextReader::Read(ifstream& inputfile, TextConverter& testConverter)
{
	vector<shared_ptr<ShapeDecorator>> shapes;
	string commandLine;
	while (getline(inputfile, commandLine))
	{
		shapes.push_back(testConverter.ConvertText(commandLine));
	}
	return shapes;
}
