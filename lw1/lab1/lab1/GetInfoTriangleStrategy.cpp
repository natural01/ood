#include "GetInfoTriangleStrategy.h"

GetInfoTriangleStrategy::GetInfoTriangleStrategy(const CTriangle& triangle)
	: m_triangle(triangle)
{
}

string GetInfoTriangleStrategy::GetInfo()
{
	int vertex1X = int(m_triangle.GetVertex1().x());
	int vertex1Y = int(m_triangle.GetVertex1().y());
	int vertex2X = int(m_triangle.GetVertex2().x());
	int vertex2Y = int(m_triangle.GetVertex2().y());
	int vertex3X = int(m_triangle.GetVertex3().x());
	int vertex3Y = int(m_triangle.GetVertex3().y());
	string answer = "Triangle " + to_string(vertex1X) + " " + to_string(vertex1Y) + " "
		+ to_string(vertex2X) + " " + to_string(vertex2Y) + " " + to_string(vertex3X) + " " + to_string(vertex3Y) + " "
		+ to_string(m_triangle.GetOutlineColor()) + " " + to_string(m_triangle.GetFillColor());
	return answer;
}
