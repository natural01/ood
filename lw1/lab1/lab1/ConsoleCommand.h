#pragma once
#include "Shape.h"
#include <string>
#include "ShapeDecorator.h"
#include "CShapeComposite.h"
#include "Application.h"
#include "Figures.h"
#include "Mementro.h"
#include "IStrategy.h"

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(std::ifstream& file, std::ofstream& outputFile);
	void DrawShapes(std::ofstream& outputFile);

	void addShapes(figures newFigure, sf::RenderWindow& window);
	std::vector<std::shared_ptr<ShapeDecorator>> getShapes();
	void SetShapes(std::vector<std::shared_ptr<ShapeDecorator>> shapes);

	string GetInfo(IStrategy& strategy);

private:
	std::vector<std::shared_ptr<ShapeDecorator>> m_shapes;
	Mementro m_history;
};