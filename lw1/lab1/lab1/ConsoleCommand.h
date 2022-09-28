#pragma once
#include "Shape.h"
#include <string>
#include "CanvasDecorator.h"

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(std::ifstream& file, std::ofstream& outputFile);
	void DrawShapes() const;

private:
	std::vector<std::unique_ptr<CanvasDecorator>> m_shapes;
};