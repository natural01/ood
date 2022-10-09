#pragma once

class CPoint
{
public:
	CPoint(double x = 0, double y = 0)
		: m_x(x)
		, m_y(y)
	{
	}
	~CPoint() = default;

	double x() const;
	double y() const;
	void setX(double x);
	void setY(double y);

private:
	double m_x = 0;
	double m_y = 0;
};