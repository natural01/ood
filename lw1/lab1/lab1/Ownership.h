#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

class COwnership
{
public:
	COwnership(CPoint const& leftTopPoint, double const& width, double const& height);
	COwnership();
	~COwnership() = default;

	sf::ConvexShape getOwnershape() const;

	void SetStartpoint(CPoint start);
	CPoint GetLeftTopPoint() const;
	void SetLeftTopPoint(CPoint newPosition);
	CPoint GetRightBottomPoint() const;
	double GetWidth() const;
	void SetWidth(double width);
	double GetHeight() const;
	void SetHeight(double height);

private:
	CPoint m_leftTopPoint = CPoint(0, 0);
	double m_width = 0;
	double m_height = 0;
};