#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>
#include "ShapeDecorator.h"
#include "Ownership.h"


class CTriangle final : public ShapeDecorator
{
public:
	CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window);
	~CTriangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetSelect(sf::Vector2i point, bool select);
	bool GetSelect();
	void SetSelect(bool select);

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	void SetPosition(CPoint newPosition);
	COwnership GetOwnership();
	std::vector<std::shared_ptr<ShapeDecorator>> GetGroup();

private:
	sf::RenderWindow& m_window;
	CPoint m_vertex1 = CPoint(0, 0);
	CPoint m_vertex2 = CPoint(0, 0);
	CPoint m_vertex3 = CPoint(0, 0);
	bool m_select = false;
	COwnership m_ownership;
};