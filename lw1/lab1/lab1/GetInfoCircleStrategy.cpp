#include "GetInfoCircleStrategy.h"

GetInfoCircleStrategy::GetInfoCircleStrategy(const CCircle& circle)
	: m_circle(circle)
{
}

string GetInfoCircleStrategy::GetInfo()
{
	int radius = int(m_circle.GetRadius());
	int centerX = int(m_circle.GetCenter().x());
	int centerY = int(m_circle.GetCenter().y());
	string answer = "Circle " + to_string(centerX) + " " + to_string(centerY) + " " + to_string(radius) + " "
		+ to_string(m_circle.GetOutlineColor()) + " " + to_string(m_circle.GetFillColor());
	return answer;
}
