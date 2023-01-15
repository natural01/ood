#pragma once
#include "ShapeDecorator.h"
#include "Ownership.h"
#include "CShapeComposite.h"

class Mementro
{
public:

	Mementro() = default;

	void addHitory(std::vector<std::shared_ptr<ShapeDecorator>> shape);

	bool Undo();
	bool Redo();
	int getIndex();
	std::vector<std::shared_ptr<ShapeDecorator>> getHistory();
	bool Emty();
private:
	int m_index = -1;
	std::vector<std::vector<std::shared_ptr<ShapeDecorator>>> m_history;
};