#pragma once
#include "Shape.h"
#include <string>
#include "ShapeDecorator.h"
#include "Ownership.h"
#include "CShapeComposite.h"
#include "Application.h"
#include "States.h"

class CConsoleCommand
{
public:
	CConsoleCommand() = default;
	~CConsoleCommand() = default;

	void DoCommand(std::ifstream& file, std::ofstream& outputFile);
	void DrawShapes(std::ofstream& outputFile);

	void updateFromMenu(ColorState state);

	void addShapes(figures newFigure, sf::RenderWindow& window);
	std::vector<std::shared_ptr<ShapeDecorator>> getShapes();

private:
	std::vector<std::shared_ptr<ShapeDecorator>> m_shapes;
	std::vector<std::unique_ptr<COwnership>> m_ownerships;
	std::vector<std::shared_ptr<CShapeComposite>> m_groups;
};