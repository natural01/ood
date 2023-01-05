#include "Circle.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

CCircle::CCircle(CPoint const& centerPoint, double const& radius, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window)
	: m_center(centerPoint)
	, m_radius(radius)
	, m_window(window)
{
	SetOutlineColor(stoul(outlineColor, 0, 16));
	SetFillColor(stoul(fillColor, 0, 16));
	double height = m_radius * 2;
	double width = m_radius * 2;
	CPoint leftTopPoint = CPoint(m_center.x() - m_radius, m_center.y() - m_radius);
	m_ownership = COwnership(leftTopPoint, height, width);
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

string CCircle::ToString() const
{
	stringstream info;
	info << "Name: circle;\n"
		<< "Center point: " << m_center.x() << ", " << m_center.y() << ";\n"
		<< "Radius: " << m_radius << ";\n"
		<< "Area: " << GetArea() << ";\n"
		<< "Perimeter: " << GetPerimeter() << ";\n"
		<< "Outline color: " << GetOutlineColor() << ";\n"
		<< "Fill color: " << GetFillColor() << ";" << endl;
	return info.str();
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::Draw(sf::RenderWindow& window) const
{
	if (m_select)
	{
		window.draw(m_ownership.getOwnershape());
	}
	sf::CircleShape circle((float)m_radius);
	circle.setFillColor(GetValidateColor(GetFillColor()));
	circle.setOutlineThickness(GetBorder());
	circle.setOutlineColor(GetValidateColor(GetOutlineColor()));
	circle.move((float)(m_center.x() - m_radius), (float)(m_center.y() - m_radius));
	window.draw(circle);
}

void CCircle::SetSelect(sf::Vector2i point, bool select)
{
	int setRadius = sqrt(pow(abs(point.x - m_center.x()), 2) + pow(abs(point.y - m_center.y()), 2));
	if (setRadius <= m_radius)
	{
		m_select = true;
	}
	else if (!select)
	{
		m_select = false;
	}
}

bool CCircle::GetSelect()
{
	return m_select;
}

void CCircle::SetPosition(CPoint newPosition)
{
	m_center.setX(m_center.x() - newPosition.x());
	m_center.setY(m_center.y() - newPosition.y());
	m_ownership.SetLeftTopPoint(newPosition);
}

COwnership CCircle::GetOwnership()
{
	return m_ownership;
}

std::vector<std::shared_ptr<ShapeDecorator>> CCircle::GetGroup()
{
	return std::vector<std::shared_ptr<ShapeDecorator>>();
}

void CCircle::SetSelect(bool select)
{
	m_select = select;
}

void CCircle::SetBorder(int borderSize)
{

}