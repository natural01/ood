#include <iostream>
#include <string>
#include "ShapeDecorator.h"

CPoint ShapeDecorator::GetSelectLeftTopPoint()
{
	return m_ownershipLeftTopPoint;
}

int ShapeDecorator::GetSelectWidth()
{
	return m_ownershipWidth;
}

int ShapeDecorator::GetSelectHeight()
{
	return m_ownershipHeight;
}

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
