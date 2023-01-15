#include "GetInfoRectangleStrategy.h"

GetInfoRectangleStrategy::GetInfoRectangleStrategy(const CRectangle& rectangle)
	: m_rectangle(rectangle)
{
}

string GetInfoRectangleStrategy::GetInfo()
{
	int leftTopPointX = int(m_rectangle.GetLeftTopPoint().x());
	int leftTopPointY = int(m_rectangle.GetLeftTopPoint().y());
	int width = int(m_rectangle.GetWidth());
	int height = int(m_rectangle.GetHeight());
	string answer = "Rectangle " + to_string(leftTopPointX) + " " + to_string(leftTopPointY) + " "
		+ to_string(width) + " " + to_string(height) + " " + to_string(m_rectangle.GetOutlineColor()) + " "
		+ to_string(m_rectangle.GetFillColor());
	return answer;
}
