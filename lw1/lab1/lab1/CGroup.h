#pragma once
#include "IGroup.h"

class CGroup : public CanvasDecorator
{
private:
	virtual ~CGroup() = default;

	int GetShapeAtIndex(int index) const;
	void insertShape(CanvasDecorator shape);
	void RemoutShapeAtIndex(int index);
	std::vector<std::unique_ptr<CanvasDecorator>> GetGroup();

	void SetOwnership(sf::Vector2i point);
	bool GetOwnership(sf::Vector2i point);
	int GetOwnershipWidth();
	int GetOwnershipHeight();
	CPoint GetOwnershipLeftTopPoint();

private:
	std::vector<std::unique_ptr<CanvasDecorator>> m_shapes;
	bool m_ownership = false;
};