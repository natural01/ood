#pragma 
#define _USE_MATH_DEFINES

#include "Point.h"
#include "SolidShape.h"
#include "CanvasDecorator.h"

class CCircle final : public CanvasDecorator
{
public:
	CCircle(CPoint const& centerPoint, double const& radius, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window);
	~CCircle() = default;

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	void Draw(sf::RenderWindow& window) const override;
	CPoint GetCenter() const;
	double GetRadius() const;
	void SetOwnership(sf::Vector2i point);
	bool GetOwnership(sf::Vector2i point);

	int GetOwnershipWidth();
	int GetOwnershipHeight();
	CPoint GetOwnershipLeftTopPoint();
	void SetPosition(CPoint newPosition);

private:
	sf::RenderWindow& m_window;
	CPoint m_center = CPoint(0, 0);
	double m_radius = 0;
	bool m_ownership = false;
};