#include "Point.h"

double CPoint::x() const
{
	return m_x;
}

double CPoint::y() const
{
	return m_y;
}

void CPoint::setX(double x)
{
	m_x = x;
}

void CPoint::setY(double y)
{
	m_y = y;
}