#include "LineSegment.h"

using namespace std;

CLineSegment::CLineSegment(CPoint const& startPoint, CPoint const& endPoint, std::string const& color, sf::RenderWindow& window)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_window(window)
{
	SetOutlineColor(stoul(color, 0, 16));
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return hypot(m_endPoint.x() - m_startPoint.x(), m_endPoint.y() - m_startPoint.y());
}

string CLineSegment::ToString() const
{
	stringstream info;
	info << "Name: line segment;\n"
		<< "Start point: " << m_startPoint.x() << ", " << m_startPoint.y() << ";\n"
		<< "End point: " << m_endPoint.x() << ", " << m_endPoint.y() << ";\n"
		<< "Area: " << GetArea() << ";\n"
		<< "Perimeter: " << GetPerimeter() << ";\n"
		<< "Outline color: " << GetOutlineColor() << ";" << endl;
	return info.str();
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

void CLineSegment::Draw(sf::RenderWindow& window) const
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f((float)m_startPoint.x(), (float)m_startPoint.y())),
		sf::Vertex(sf::Vector2f((float)m_endPoint.x(), (float)m_endPoint.y()))
	};
	line[0].color = GetValidateColor(GetFillColor());
	line[1].color = GetValidateColor(GetOutlineColor());
	window.draw(line, 2, sf::Lines);
}

int CLineSegment::GetOwnershipWidth()
{
	return abs(m_startPoint.x() - m_endPoint.x());
}
int CLineSegment::GetOwnershipHeight()
{
	return abs(m_startPoint.y() - m_endPoint.y());
}
CPoint CLineSegment::GetOwnershipLeftTopPoint()
{
	int minX = m_startPoint.x();
	int minY = m_startPoint.y();
	if (m_endPoint.x() < minX)
	{
		minX = m_endPoint.x();
	}
	if (m_endPoint.y() < minY)
	{
		minY = m_endPoint.y();
	}
	return CPoint(minX, minY);
	return CPoint(minX, minY);
}

void CLineSegment::SetOwnership(sf::Vector2i point, bool select)
{
	if (((point.x - m_startPoint.x()) * (m_endPoint.y() - m_startPoint.y())) - ((point.y - m_startPoint.y()) * (m_endPoint.x() - m_startPoint.x())) == 0)
	{
		m_ownership = true;
	}
	else if (!select)
	{
		m_ownership = false;
	}
}

bool CLineSegment::GetOwnership()
{
	return m_ownership;
}

void CLineSegment::SetOwnership()
{
	m_ownership = true;
}

void CLineSegment::SetPosition(CPoint newPosition)
{
	m_startPoint.setX(m_startPoint.x() - newPosition.x());
	m_startPoint.setY(m_startPoint.y() - newPosition.y());
	m_endPoint.setX(m_endPoint.x() - newPosition.x());
	m_endPoint.setY(m_endPoint.y() - newPosition.y());
}