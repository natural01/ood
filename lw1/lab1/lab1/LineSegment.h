#pragma once
#include <iostream>
#include <sstream>
#include "Shape.h"
#include "Point.h"
#include "ShapeDecorator.h"
#include "Ownership.h"

class CLineSegment final : public ShapeDecorator
{
public:
	CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& color, sf::RenderWindow& window);
	~CLineSegment() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetSelect(sf::Vector2i point, bool select);
	bool GetSelect();
	void SetSelect(bool select);

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	void SetPosition(CPoint newPosition);
	COwnership GetOwnership();
	std::vector<std::shared_ptr<ShapeDecorator>> GetGroup();

private:
	sf::RenderWindow& m_window;
	CPoint m_startPoint = CPoint(0, 0);
	CPoint m_endPoint = CPoint(0, 0);
	bool m_select = false;
	COwnership m_ownership;
};