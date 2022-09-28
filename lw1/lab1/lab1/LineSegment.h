#pragma once
#include <iostream>
#include <sstream>
#include "Shape.h"
#include "Point.h"
#include "CanvasDecorator.h"

class CLineSegment final : public CanvasDecorator
{
public:
	CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& color, sf::RenderWindow& window);
	~CLineSegment() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	sf::RenderWindow& m_window;
	CPoint m_startPoint = CPoint(0, 0);
	CPoint m_endPoint = CPoint(0, 0);
};