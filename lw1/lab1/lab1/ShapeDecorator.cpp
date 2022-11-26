#include <iostream>
#include <string>
#include "ShapeDecorator.h"

void ShapeDecorator::SetFillColor(uint32_t const& color)
{
	m_fillColor = color;
}

uint32_t ShapeDecorator::GetFillColor() const
{
	return m_fillColor;
}

void ShapeDecorator::SetOutlineColor(uint32_t const& color)
{
	CShape::SetOutlineColor(color);
}

void ShapeDecorator::SetBorder(int borderSize)
{
	m_borederSize = borderSize;
}

int ShapeDecorator::GetBorder() const
{
	return m_borederSize;
}

uint32_t ShapeDecorator::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

void ShapeDecorator::SetOwnershipWidth(double width)
{
	m_ownershipWidth = width;
}
void ShapeDecorator::SetOwnershipHeight(double height)
{
	m_ownershipHeight = height;
}
void ShapeDecorator::SetOwnershipLeftTopPoint(CPoint leftTopPoint)
{
	m_ownershipLeftTopPoint = leftTopPoint;
};
