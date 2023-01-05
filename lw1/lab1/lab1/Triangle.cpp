#include "Triangle.h"

using namespace std;

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

int OwnershipWidth(CPoint vertex1, CPoint vertex2, CPoint vertex3)
{
	int max = vertex1.x();
	int min = vertex1.x();

	if (vertex2.x() > max)
	{
		max = vertex2.x();
	}
	if (vertex3.x() > max)
	{
		max = vertex3.x();
	}
	if (vertex2.x() < min)
	{
		min = vertex2.x();
	}
	if (vertex3.x() < min)
	{
		min = vertex3.x();
	}
	return max - min;
}
int OwnershipHeight(CPoint vertex1, CPoint vertex2, CPoint vertex3)
{
	int max = vertex1.y();
	int min = vertex1.y();

	if (vertex2.y() > max)
	{
		max = vertex2.y();
	}
	if (vertex3.y() > max)
	{
		max = vertex3.y();
	}
	if (vertex2.y() < min)
	{
		min = vertex2.y();
	}
	if (vertex3.y() < min)
	{
		min = vertex3.y();
	}
	return max - min;
}
CPoint OwnershipLeftTopPoint(CPoint vertex1, CPoint vertex2, CPoint vertex3)
{
	int minX = vertex1.x();
	int minY = vertex1.y();
	if (vertex2.x() < minX)
	{
		minX = vertex2.x();
	}
	if (vertex3.x() < minX)
	{
		minX = vertex3.x();
	}
	if (vertex2.y() < minY)
	{
		minY = vertex2.y();
	}
	if (vertex3.y() < minY)
	{
		minY = vertex3.y();
	}
	return CPoint(minX, minY);
}

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, std::string const& outlineColor, std::string const& fillColor, sf::RenderWindow& window)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_window(window)
{
	SetOutlineColor(stoul(outlineColor, 0, 16));
	SetFillColor(stoul(fillColor, 0, 16));
	int height = OwnershipHeight(m_vertex1, m_vertex2, m_vertex3);
	int width = OwnershipWidth(m_vertex1, m_vertex2, m_vertex3);
	CPoint leftTopPoint = OwnershipLeftTopPoint(m_vertex1, m_vertex2, m_vertex3);
	m_ownership = COwnership(leftTopPoint, height, width);
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

void CTriangle::Draw(sf::RenderWindow& window) const
{
	if (m_select)
	{
		window.draw(m_ownership.getOwnershape());
	}
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
	shape.setOutlineThickness(GetBorder());
	shape.setFillColor(GetValidateColor(GetFillColor()));
	shape.setOutlineColor(GetValidateColor(GetOutlineColor()));
	window.draw(shape);
}

double Perimeter(CPoint vertex1, CPoint vertex2, CPoint vertex3)
{
	return hypot(vertex2.x() - vertex1.x(), vertex2.y() - vertex1.y())
		+ hypot(vertex3.x() - vertex2.x(), vertex3.y() - vertex2.y())
		+ hypot(vertex3.x() - vertex1.x(), vertex3.y() - vertex1.y());
}
double Square(CPoint vertex1, CPoint vertex2, CPoint vertex3)
{
	double halfPerimeter = Perimeter(vertex1, vertex2, vertex3) / 2;

	return sqrt(halfPerimeter * (halfPerimeter - hypot(vertex2.x() - vertex1.x(), vertex2.y() - vertex1.y()))
		* (halfPerimeter - hypot(vertex3.x() - vertex2.x(), vertex3.y() - vertex2.y()))
		* (halfPerimeter - hypot(vertex3.x() - vertex1.x(), vertex3.y() - vertex1.y())));
}

void CTriangle::SetSelect(sf::Vector2i point, bool select)
{
	CPoint newVertex = CPoint(point.x, point.y);
	int getSquare = Square(m_vertex1, m_vertex2, m_vertex3);
	int setSquare1 = Square(newVertex, m_vertex2, m_vertex3);
	int setSquare2 = Square(m_vertex1, newVertex, m_vertex3);
	int setSquare3 = Square(m_vertex1, m_vertex2, newVertex);
	if (getSquare >= setSquare1 + setSquare2 + setSquare3)
	{
		m_select = true;
	}
	else if (!select)
	{
		m_select = false;
	}
}

bool CTriangle::GetSelect()
{
	return m_select;
}

void CTriangle::SetPosition(CPoint newPosition)
{
	m_vertex1.setX(m_vertex1.x() - newPosition.x());
	m_vertex1.setY(m_vertex1.y() - newPosition.y());
	m_vertex2.setX(m_vertex2.x() - newPosition.x());
	m_vertex2.setY(m_vertex2.y() - newPosition.y());
	m_vertex3.setX(m_vertex3.x() - newPosition.x());
	m_vertex3.setY(m_vertex3.y() - newPosition.y());
	m_ownership.SetLeftTopPoint(newPosition);
}

COwnership CTriangle::GetOwnership()
{
	return m_ownership;
}

std::vector<std::shared_ptr<ShapeDecorator>> CTriangle::GetGroup()
{
	return std::vector<std::shared_ptr<ShapeDecorator>>();
}

void CTriangle::SetSelect(bool select)
{
	m_select = select;
}