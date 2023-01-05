#pragma 
#define _USE_MATH_DEFINES

#include "Point.h"
#include "SolidShape.h"
#include "ShapeDecorator.h"
#include "Ownership.h"

class CCircle final : public ShapeDecorator
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
	void SetSelect(sf::Vector2i point, bool select);
	bool GetSelect();
	void SetSelect(bool select);
	void SetBorder(int borderSize);

	void SetPosition(CPoint newPosition);
	COwnership GetOwnership();
	std::vector<std::shared_ptr<ShapeDecorator>> GetGroup();

private:
	sf::RenderWindow& m_window;
	CPoint m_center = CPoint(0, 0);
	double m_radius = 0;
	bool m_select = false;
	COwnership m_ownership;
};