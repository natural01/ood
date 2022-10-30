#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>
#include "ShapeDecorator.h"

class CRectangle final : public ShapeDecorator
{
public:
	CRectangle(CPoint const& leftTopPoint, double const& width, double const& height, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window);
	~CRectangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetOwnership(sf::Vector2i point, bool select);
	bool GetOwnership();
	void SetOwnership();

	CPoint GetLeftTopPoint() const;
	CPoint GetRightBottomPoint() const;
	double GetWidth() const;
	double GetHeight() const;

	int GetOwnershipWidth();
	int GetOwnershipHeight();
	CPoint GetOwnershipLeftTopPoint();
	void SetPosition(CPoint newPosition);

private:
	sf::RenderWindow& m_window;
	CPoint m_leftTopPoint = CPoint(0, 0);
	double m_width = 0;
	double m_height = 0;
	bool m_ownership = false;
};