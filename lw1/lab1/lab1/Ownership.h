#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>

class COwnership
{
public:
	COwnership(CPoint const& leftTopPoint, double const& width, double const& height, sf::RenderWindow& window);
	~COwnership() = default;

	void Draw(sf::RenderWindow& window) const;

	CPoint GetLeftTopPoint() const;
	CPoint GetRightBottomPoint() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	sf::RenderWindow& m_window;
	CPoint m_leftTopPoint = CPoint(0, 0);
	double m_width = 0;
	double m_height = 0;
};