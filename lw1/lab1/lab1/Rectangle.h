#pragma once
#include "Point.h"
#include "SolidShape.h"
#include <iostream>
#include <sstream>
#include "ShapeDecorator.h"
#include "Ownership.h"

class CRectangle final : public ShapeDecorator
{
public:
	CRectangle(CPoint const& leftTopPoint, double const& width, double const& height, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window);
	~CRectangle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	void SetSelect(sf::Vector2i point, bool select);
	bool GetSelect();
	void SetSelect(bool select);

	CPoint GetLeftTopPoint() const;
	CPoint GetRightBottomPoint() const;
	double GetWidth() const;
	double GetHeight() const;

	void SetPosition(CPoint newPosition);
	COwnership GetOwnership();
	std::vector<std::shared_ptr<ShapeDecorator>> GetGroup();

private:
	sf::RenderWindow& m_window;
	CPoint m_leftTopPoint = CPoint(0, 0);
	double m_width = 0;
	double m_height = 0;
	bool m_select = false;
	COwnership m_ownership;
};