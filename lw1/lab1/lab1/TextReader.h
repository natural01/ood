#pragma once
#include <vector>
#include "ShapeDecorator.h"
#include "TextConverter.h"+
#include <fstream>


using namespace std;

class TextReader
{
public:
	vector<shared_ptr<ShapeDecorator>> Read(ifstream& inputfile, TextConverter& testConverter);
};