#pragma once
#include "IStrategy.h"
#include "Rectangle.h"

class GetInfoRectangleStrategy : public IStrategy
{
public:
	GetInfoRectangleStrategy(const CRectangle& rectangle);
	string GetInfo() override;

private:
	const CRectangle& m_rectangle;
};