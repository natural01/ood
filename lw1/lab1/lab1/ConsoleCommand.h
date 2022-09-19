#pragma once
#include "Shape.h"
#include <string>

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(std::ifstream& file, std::ofstream& outputFile);
	std::vector<std::unique_ptr<IShape>>::const_iterator GetShapeWithMaxArea() const;
	std::vector<std::unique_ptr<IShape>>::const_iterator GetShapeWithMinPerimeter() const;
	std::string SetShapeInfo(std::vector<std::unique_ptr<IShape>>::const_iterator shape) const;
	void GetShapeInfo(CConsoleCommand& consoleCommand) const;
	void DrawShapes() const;

private:
	std::vector<std::unique_ptr<IShape>> m_shapes;
};