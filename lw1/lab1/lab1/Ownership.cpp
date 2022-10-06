#include "Ownership.h"

using namespace std;

COwnership::COwnership(CPoint const& leftTopPoint, double const& width, double const& height, sf::RenderWindow& window)
	: m_leftTopPoint(leftTopPoint)
	, m_width(width)
	, m_height(height)
	, m_window(window)
{
}

CPoint COwnership::GetLeftTopPoint() const
{
	return m_leftTopPoint;
}

CPoint COwnership::GetRightBottomPoint() const
{
	return CPoint(m_leftTopPoint.x() + m_width, m_leftTopPoint.y() + m_height);
}

double COwnership::GetWidth() const
{
	return m_width;
}

double COwnership::GetHeight() const
{
	return m_height;
}

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

void COwnership::Draw(sf::RenderWindow& window) const
{
	CPoint rightBottomPoint = GetRightBottomPoint();
	std::vector<CPoint> points = {
		{ rightBottomPoint.x(), rightBottomPoint.y() },
		{ m_leftTopPoint.x(), m_leftTopPoint.y() + m_height },
		{ m_leftTopPoint.x(), m_leftTopPoint.y() },
		{ m_leftTopPoint.x() + m_width, m_leftTopPoint.y() }
	};
	sf::ConvexShape shape;
	shape.setPointCount(points.size());
	for (size_t i = 0; i < points.size(); i++)
	{
		shape.setPoint(i, sf::Vector2f((float)points[i].x(), (float)points[i].y()));
	}
	shape.setFillColor(sf::Color(0, 0, 0, 0));
	shape.setOutlineThickness(3);
	shape.setOutlineColor(GetValidateColor(000000));
	window.draw(shape);
}