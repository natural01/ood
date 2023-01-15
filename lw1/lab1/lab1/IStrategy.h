#pragma once
#include <string>
#include "ShapeDecorator.h"

using namespace std;

class IStrategy
{
public:
	IStrategy() = default;
	virtual string GetInfo() = 0;
};