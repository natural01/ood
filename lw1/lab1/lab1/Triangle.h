#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>
#include "CanvasDecorator.h"


class CTriangle final : public CanvasDecorator
{
public:
	CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window);
	~CTriangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetOwnership(sf::Vector2i point);
	bool GetOwnership(sf::Vector2i point);

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	int GetOwnershipWidth();
	int GetOwnershipHeight();
	CPoint GetOwnershipLeftTopPoint();

private:
	sf::RenderWindow& m_window;
	CPoint m_vertex1 = CPoint(0, 0);
	CPoint m_vertex2 = CPoint(0, 0);
	CPoint m_vertex3 = CPoint(0, 0);
	bool m_ownership = false;
};