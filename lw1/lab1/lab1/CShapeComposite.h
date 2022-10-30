#pragma once
#include "IShapeComposite.h"
#include "ShapeDecorator.h"

class CShapeComposite : public IShapeComposite
{
public:
	CShapeComposite(std::vector<std::shared_ptr<ShapeDecorator>> shapes, CPoint leftTopPoint);
	~CShapeComposite() = default;

	void insertShape(std::shared_ptr<ShapeDecorator> shape);
	std::shared_ptr<ShapeDecorator> GetShape(int index);
	void RemoutShapeAtIndex(int index);
	void ClearShapeList();
	std::vector<std::shared_ptr<ShapeDecorator>> GetGroup();

	void SetOwnership(sf::Vector2i point);
	bool GetOwnership();
	int GetOwnershipWidth();
	int GetOwnershipHeight();
	CPoint GetOwnershipLeftTopPoint();
	bool EntryShape(std::shared_ptr<ShapeDecorator> shape, bool select);
	void SetPosition(CPoint newPosition);

private:
	std::vector<std::shared_ptr<ShapeDecorator>> m_shapes;
	bool m_ownership = false;
	CPoint m_leftTopPoint;
};