#include "CShapeComposite.h"

CShapeComposite::CShapeComposite(std::vector<std::shared_ptr<ShapeDecorator>> shapes, CPoint leftTopPoint)
	: m_leftTopPoint(leftTopPoint)
	, m_shapes(shapes)
{
}

void CShapeComposite::insertShape(std::shared_ptr<ShapeDecorator> shape)
{
	m_shapes.push_back(shape);
}

void CShapeComposite::RemoutShapeAtIndex(int index)
{
	m_shapes.erase(m_shapes.begin() + index);
}

void CShapeComposite::ClearShapeList()
{
	m_shapes.clear();
}

std::vector<std::shared_ptr<ShapeDecorator>> CShapeComposite::GetGroup()
{
	return m_shapes;
}

void CShapeComposite::SetOwnership(sf::Vector2i point)
{
	for (auto& shape : m_shapes)
	{
		if (shape->GetOwnership())
		{
			m_ownership = true;
			break;
		}
	}
}

bool CShapeComposite::GetOwnership()
{
	return m_ownership;
}

int CShapeComposite::GetOwnershipWidth()
{
	double start = m_leftTopPoint.x();
	double finish = -999, width = 0;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetOwnershipLeftTopPoint().x() > finish)
		{
			finish = shape->GetOwnershipLeftTopPoint().x();
			width = shape->GetOwnershipWidth();
		}
	}
	return fabs(start - finish) + width;
}

int CShapeComposite::GetOwnershipHeight()
{
	double start = m_leftTopPoint.y();
	double finish = -999, height = 0;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetOwnershipLeftTopPoint().y() > finish)
		{
			finish = shape->GetOwnershipLeftTopPoint().y();
			height = shape->GetOwnershipWidth();
		}
	}
	return fabs(start - finish) + height;
}

CPoint CShapeComposite::GetOwnershipLeftTopPoint()
{
	double xPosition = 999, yPosition = 999;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetOwnershipLeftTopPoint().x() < xPosition)
		{
			xPosition = shape->GetOwnershipLeftTopPoint().x();
		}
		if (shape->GetOwnershipLeftTopPoint().y() < yPosition)
		{
			yPosition = shape->GetOwnershipLeftTopPoint().y();
		}
	}
	m_leftTopPoint = CPoint(xPosition, yPosition);
	return CPoint(xPosition, yPosition);
}

bool CShapeComposite::EntryShape(std::shared_ptr<ShapeDecorator> shape, bool select)
{
	if (std::find(m_shapes.begin(), m_shapes.end(), shape) != m_shapes.end())
	{
		m_ownership = true;
		return true;
	}
	else
	{
		if (!select)
		{ 
			m_ownership = false;
		}
		return false;
	}
}