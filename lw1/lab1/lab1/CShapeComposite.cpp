#include "CShapeComposite.h"

CShapeComposite::CShapeComposite()
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

void CShapeComposite::CreateOwnership()
{
	double left = 0, right = 0, top = 0, down = 0;
	for (int index = 0; index < m_shapes.size(); index++)
	{
		if (index == 0)
		{
			left = m_shapes[index]->GetOwnership().GetLeftTopPoint().x();
			right = m_shapes[index]->GetOwnership().GetRightBottomPoint().x();
			top = m_shapes[index]->GetOwnership().GetLeftTopPoint().y();
			down = m_shapes[index]->GetOwnership().GetRightBottomPoint().y();
			continue;
		}
		if (left > m_shapes[index]->GetOwnership().GetLeftTopPoint().x())
			left = m_shapes[index]->GetOwnership().GetLeftTopPoint().x();
		if (right < m_shapes[index]->GetOwnership().GetRightBottomPoint().x())
			right = m_shapes[index]->GetOwnership().GetRightBottomPoint().x();
		if (top > m_shapes[index]->GetOwnership().GetLeftTopPoint().y())
			top = m_shapes[index]->GetOwnership().GetLeftTopPoint().y();
		if (down < m_shapes[index]->GetOwnership().GetRightBottomPoint().y())
			down = m_shapes[index]->GetOwnership().GetRightBottomPoint().y();
	}
	m_ownership.SetStartpoint(CPoint(left, top));
	m_ownership.SetHeight(down - top);
	m_ownership.SetWidth(right - left);
}

void CShapeComposite::SetSelect(sf::Vector2i point)
{
	for (auto& shape : m_shapes)
	{
		if (shape->GetSelect())
		{
			m_select = true;
			break;
		}
	}
}

bool CShapeComposite::GetSelect()
{
	return m_select;
}

int CShapeComposite::GetSelectWidth()
{
	double start = m_leftTopPoint.x();
	double finish = -999, width = 0;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetSelectLeftTopPoint().x() > finish)
		{
			finish = shape->GetSelectLeftTopPoint().x();
			width = shape->GetSelectWidth();
		}
	}
	return fabs(start - finish) + width;
}

int CShapeComposite::GetSelectHeight()
{
	double start = m_leftTopPoint.y();
	double finish = -999, height = 0;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetSelectLeftTopPoint().y() > finish)
		{
			finish = shape->GetSelectLeftTopPoint().y();
			height = shape->GetSelectHeight();
		}
	}
	return fabs(start - finish) + height;
}

CPoint CShapeComposite::GetSelectLeftTopPoint()
{
	double xPosition = 999, yPosition = 999;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetSelectLeftTopPoint().x() < xPosition)
		{
			xPosition = shape->GetSelectLeftTopPoint().x();
		}
		if (shape->GetSelectLeftTopPoint().y() < yPosition)
		{
			yPosition = shape->GetSelectLeftTopPoint().y();
		}
	}
	m_leftTopPoint = CPoint(xPosition, yPosition);
	return CPoint(xPosition, yPosition);
}

bool CShapeComposite::EntryShape(std::shared_ptr<ShapeDecorator> shape, bool select)
{
	if (std::find(m_shapes.begin(), m_shapes.end(), shape) != m_shapes.end())
	{
		for (const auto& shape : m_shapes)
		{
			shape->SetSelect(true);
		}
		m_select = true;
		return true;
	}
	else
	{
		if (!select)
		{ 
			m_select = false;
		}
		return false;
	}
}

void CShapeComposite::SetPosition(CPoint newPosition)
{
	for (const auto& shape : m_shapes)
	{
		shape->SetPosition(newPosition);
	}
	m_ownership.SetLeftTopPoint(newPosition);
}

double CShapeComposite::GetArea() const
{
	double area = 0;
	for (const auto& shape : m_shapes)
	{
		area += shape->GetArea();
	}
	return area;
}

double CShapeComposite::GetPerimeter() const
{
	double perimeter = 0;
	for (const auto& shape : m_shapes)
	{
		perimeter += shape->GetPerimeter();
	}
	return perimeter;
}

std::string CShapeComposite::ToString() const
{
	std::string answer = "";
	for (const auto& shape : m_shapes)
	{
		answer += shape->ToString();
	}
	return answer;
}

void CShapeComposite::Draw(sf::RenderWindow& window) const
{
	if (m_select)
	{
		window.draw(m_ownership.getOwnershape());
	}
	for (const auto& shape : m_shapes)
	{
		shape->Draw(window);
	}
}

void CShapeComposite::SetSelect(sf::Vector2i point, bool select)
{
	for (const auto& shape : m_shapes)
	{
		shape->SetSelect(point, select);
		if (shape->GetSelect())
		{
			m_select = true;
		}
		shape->SetSelect(false);
	}
}

void CShapeComposite::SetSelect(bool select)
{
	m_select = select;
}

COwnership CShapeComposite::GetOwnership()
{
	return m_ownership;
}

std::shared_ptr<ShapeDecorator> CShapeComposite::GetShape(int index)
{
	return m_shapes[index];
}