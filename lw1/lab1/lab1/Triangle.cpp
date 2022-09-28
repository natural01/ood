#include "Triangle.h"

using namespace std;

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_window(window)
{
	SetOutlineColor(stoul(outlineColor, 0, 16));
	SetFillColor(stoul(fillColor, 0, 16));
}

double CTriangle::GetArea() const
{
	double halfPerimeter = GetPerimeter() / 2;

	return sqrt(halfPerimeter * (halfPerimeter - hypot(m_vertex2.x() - m_vertex1.x(), m_vertex2.y() - m_vertex1.y()))
		* (halfPerimeter - hypot(m_vertex3.x() - m_vertex2.x(), m_vertex3.y() - m_vertex2.y()))
		* (halfPerimeter - hypot(m_vertex3.x() - m_vertex1.x(), m_vertex3.y() - m_vertex1.y())));
}

double CTriangle::GetPerimeter() const
{
	return hypot(m_vertex2.x() - m_vertex1.x(), m_vertex2.y() - m_vertex1.y())
		+ hypot(m_vertex3.x() - m_vertex2.x(), m_vertex3.y() - m_vertex2.y())
		+ hypot(m_vertex3.x() - m_vertex1.x(), m_vertex3.y() - m_vertex1.y());
}

string CTriangle::ToString() const
{
	stringstream info;
	info << "Name: triangle;\n"
		<< "Vertex 1: " << m_vertex1.x() << ", " << m_vertex1.y() << ";\n"
		<< "Vertex 2: " << m_vertex2.x() << ", " << m_vertex2.y() << ";\n"
		<< "Vertex 3: " << m_vertex3.x() << ", " << m_vertex3.y() << ";\n"
		<< "Area: " << GetArea() << ";\n"
		<< "Perimeter: " << GetPerimeter() << ";\n"
		<< "Outline color: " << GetOutlineColor() << ";\n"
		<< "Fill color: " << GetFillColor() << ";" << endl;
	return info.str();
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

void CTriangle::Draw(sf::RenderWindow& window) const
{
	std::vector<CPoint> points = {
		{ m_vertex1.x(), m_vertex1.y() },
		{ m_vertex2.x(), m_vertex2.y() },
		{ m_vertex3.x(), m_vertex3.y() }
	};

	sf::ConvexShape shape;
	shape.setPointCount(points.size());
	for (size_t i = 0; i < points.size(); i++)
	{
		shape.setPoint(i, sf::Vector2f((float)points[i].x(), (float)points[i].y()));
	}
	shape.setFillColor(GetValidateColor(GetFillColor()));
	shape.setOutlineThickness(1);
	shape.setOutlineColor(GetValidateColor(GetOutlineColor()));
	window.draw(shape);
}