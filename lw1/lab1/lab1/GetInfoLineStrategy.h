#pragma once
#include "IStrategy.h"
#include "LineSegment.h"

class GetInfoLineStrategy : public IStrategy
{
public:
	GetInfoLineStrategy(const CLineSegment& line);
	string GetInfo() override;

private:
	const CLineSegment& m_lineSegment;
};