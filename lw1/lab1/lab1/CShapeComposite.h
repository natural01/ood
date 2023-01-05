#pragma once
#include "ShapeDecorator.h"
#include "IShapeComposite.h"
#include "Ownership.h"

class CShapeComposite : public IShapeComposite
{
public:
	CShapeComposite();
	~CShapeComposite() = default;

	void insertShape(std::shared_ptr<ShapeDecorator> shape);
	std::shared_ptr<ShapeDecorator> GetShape(int index);
	void RemoutShapeAtIndex(int index);
	void ClearShapeList();
	std::vector<std::shared_ptr<ShapeDecorator>> GetGroup();

	void CreateOwnership();
	void SetSelect(sf::Vector2i point);
	bool GetSelect();
	int GetSelectWidth();
	int GetSelectHeight();
	CPoint GetSelectLeftTopPoint();
	bool EntryShape(std::shared_ptr<ShapeDecorator> shape, bool select);
	void SetPosition(CPoint newPosition);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetSelect(sf::Vector2i point, bool select);
	void SetSelect(bool select);
	COwnership GetOwnership();


private:
	std::vector<std::shared_ptr<ShapeDecorator>> m_shapes;
	bool m_select = false;
	CPoint m_leftTopPoint;
	COwnership m_ownership;
};