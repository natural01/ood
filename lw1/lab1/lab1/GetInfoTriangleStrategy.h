#pragma once
#include "IStrategy.h"
#include "Triangle.h"

class GetInfoTriangleStrategy : public IStrategy
{
public:
	GetInfoTriangleStrategy(const CTriangle& triangle);
	string GetInfo() override;

private:
	const CTriangle& m_triangle;
};