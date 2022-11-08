#include "Rectangle.h"

using namespace std;

CRectangle::CRectangle(CPoint const& leftTopPoint, double const& width, double const& height, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window)
	: m_leftTopPoint(leftTopPoint)
	, m_width(width)
	, m_height(height)
	, m_window(window)
{
	SetOutlineColor(stoul(outlineColor, 0, 16));
	SetFillColor(stoul(fillColor, 0, 16));
}

double CRectangle::GetArea() const
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
	return 2 * (m_width + m_height);
}

string CRectangle::ToString() const
{
	stringstream info;
	CPoint rightBottomPoint = GetRightBottomPoint();
	info << "Name: rectangle;\n"
		<< "Left top point: " << m_leftTopPoint.x() << ", " << m_leftTopPoint.y() << ";\n"
		<< "Right bottom point: " << rightBottomPoint.x() << ", " << rightBottomPoint.y() << ";\n"
		<< "Width: " << GetWidth() << ";\n"
		<< "Height: " << GetHeight() << ";\n"
		<< "Area: " << GetArea() << ";\n"
		<< "Perimeter: " << GetPerimeter() << ";\n"
		<< "Outline color: " << GetOutlineColor() << ";\n"
		<< "Fill color: " << GetFillColor() << ";" << endl;
	return info.str();
}

CPoint CRectangle::GetLeftTopPoint() const
{
	return m_leftTopPoint;
}

CPoint CRectangle::GetRightBottomPoint() const
{
	return CPoint(m_leftTopPoint.x() + m_width, m_leftTopPoint.y() + m_height);
}

double CRectangle::GetWidth() const
{
	return m_width;
}

double CRectangle::GetHeight() const
{
	return m_height;
}

int CRectangle::GetOwnershipWidth()
{
	return m_width;
}

int CRectangle::GetOwnershipHeight()
{
	return m_height;
}

CPoint CRectangle::GetOwnershipLeftTopPoint()
{
	return m_leftTopPoint;
}

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

void CRectangle::Draw(sf::RenderWindow& window) const
{
	CPoint rightBottomPoint = GetRightBottomPoint();
	std::vector<CPoint> points = {
		{ m_leftTopPoint.x(), m_leftTopPoint.y() },
		{ m_leftTopPoint.x() + m_width, m_leftTopPoint.y() },
		{ rightBottomPoint.x(), rightBottomPoint.y() },
		{ m_leftTopPoint.x(), m_leftTopPoint.y() + m_height }
	};
	sf::ConvexShape shape;
	shape.setPointCount(points.size());
	for (size_t i = 0; i < points.size(); i++)
	{
		shape.setPoint(i, sf::Vector2f((float)points[i].x(), (float)points[i].y()));
	}
	shape.setOutlineThickness(1);
	shape.setOutlineColor(GetValidateColor(GetOutlineColor()));
	shape.setFillColor(GetValidateColor(GetFillColor()));
	window.draw(shape);
}

void CRectangle::SetOwnership(sf::Vector2i point, bool select)
{
	if ((point.x < m_leftTopPoint.x() + m_width && point.x > m_leftTopPoint.x()) && (point.y < m_leftTopPoint.y() + m_height && point.y > m_leftTopPoint.y()))
	{
		m_ownership = true;
	}
	else if (!select)
	{
		m_ownership = false;
	}
}

bool CRectangle::GetOwnership()
{
	return m_ownership;
}

void CRectangle::SetPosition(CPoint newPosition)
{
	m_leftTopPoint.setX(m_leftTopPoint.x() - newPosition.x());
	m_leftTopPoint.setY(m_leftTopPoint.y() - newPosition.y());
}

void CRectangle::SetOwnership()
{
	m_ownership = true;
}