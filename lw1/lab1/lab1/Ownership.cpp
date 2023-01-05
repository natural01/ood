#include "Ownership.h"

using namespace std;

COwnership::COwnership(CPoint const& leftTopPoint, double const& width, double const& height)
	: m_leftTopPoint(leftTopPoint)
	, m_width(width)
	, m_height(height)
{
}

COwnership::COwnership()
	: m_leftTopPoint(CPoint(0, 0))
	, m_width(0)
	, m_height(0)
{
}

void COwnership::SetStartpoint(CPoint start)
{
	m_leftTopPoint.setX(start.x());
	m_leftTopPoint.setY(start.y());
}

CPoint COwnership::GetLeftTopPoint() const
{
	return m_leftTopPoint;
}

CPoint COwnership::GetRightBottomPoint() const
{
	return CPoint(m_leftTopPoint.x() + m_width, m_leftTopPoint.y() + m_height);
}

void COwnership::SetLeftTopPoint(CPoint newPosition)
{
	m_leftTopPoint.setX(m_leftTopPoint.x() - newPosition.x());
	m_leftTopPoint.setY(m_leftTopPoint.y() - newPosition.y());
}

double COwnership::GetWidth() const
{
	return m_width;
}

void COwnership::SetWidth(double width)
{
	m_width = width;
}

double COwnership::GetHeight() const
{
	return m_height;
}

void COwnership::SetHeight(double height)
{
	m_height = height;
}

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

sf::ConvexShape COwnership::getOwnershape() const
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
	return shape;
}