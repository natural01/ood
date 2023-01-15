#include "GetInfoLineStrategy.h"

GetInfoLineStrategy::GetInfoLineStrategy(const CLineSegment& line)
    : m_lineSegment(line)
{
}

string GetInfoLineStrategy::GetInfo()
{
    int startX = int(m_lineSegment.GetStartPoint().x());
    int StartY = int(m_lineSegment.GetStartPoint().y());
    int finishX = int(m_lineSegment.GetEndPoint().x());
    int finishY = int(m_lineSegment.GetEndPoint().y());
    string answer = "LineSegment " + to_string(startX) + " " + to_string(StartY)
        + " " + to_string(finishX) + " " + to_string(finishY) + " " + to_string(m_lineSegment.GetOutlineColor());
    return answer;
}
