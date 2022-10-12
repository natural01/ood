#include <iostream>
#include <string>
#include "CanvasDecorator.h"

void CanvasDecorator::SetFillColor(uint32_t const& color)
{
	m_fillColor = color;
}

uint32_t CanvasDecorator::GetFillColor() const
{
	return m_fillColor;
}

void CanvasDecorator::SetOutlineColor(uint32_t const& color)
{
	CShape::SetOutlineColor(color);
}

uint32_t CanvasDecorator::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

void CanvasDecorator::SetOwnershipWidth(double width)
{
	m_ownershipWidth = width;
}
void CanvasDecorator::SetOwnershipHeight(double height)
{
	m_ownershipHeight = height;
}
void CanvasDecorator::SetOwnershipLeftTopPoint(CPoint leftTopPoint)
{
	m_ownershipLeftTopPoint = leftTopPoint;
};
