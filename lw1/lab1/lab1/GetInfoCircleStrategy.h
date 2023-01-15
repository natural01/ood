#pragma once
#include "IStrategy.h"
#include "Circle.h"

class GetInfoCircleStrategy : public IStrategy
{
public:
	GetInfoCircleStrategy(const CCircle& circle);
	string GetInfo() override;

private:
	const CCircle& m_circle;
};