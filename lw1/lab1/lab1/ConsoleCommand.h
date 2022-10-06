#pragma once
#include "Shape.h"
#include <string>
#include "CanvasDecorator.h"
#include "Ownership.h"

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(std::ifstream& file, std::ofstream& outputFile);
	void DrawShapes();

private:
	std::vector<std::unique_ptr<CanvasDecorator>> m_shapes;
	std::vector<std::unique_ptr<COwnership>> m_ownerships;
};