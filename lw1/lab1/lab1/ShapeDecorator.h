#pragma once
#include <vector>
#include <string>
#include "SolidShape.h"
#include "Point.h"
#include <SFML/Graphics.hpp>
#include "Ownership.h"
#include "IStrategy.h"

class ShapeDecorator : public CSolidShape
{
public:
	virtual ~ShapeDecorator() = default;

	virtual void Draw(sf::RenderWindow& windiw) const = 0;

	virtual void SetSelect(sf::Vector2i point, bool select) = 0;
	virtual void SetSelect(bool select) = 0;
	virtual bool GetSelect() = 0;
	virtual COwnership GetOwnership() = 0;
	CPoint GetSelectLeftTopPoint();
	int GetSelectWidth();
	int GetSelectHeight();

	void SetFillColor(uint32_t const& color) override;
	uint32_t GetFillColor() const;

	void SetOutlineColor(uint32_t const& color) override;
	uint32_t GetOutlineColor() const;
	int GetBorder() const;
	void SetBorder(int borderSize) override;

	virtual std::vector<std::shared_ptr<ShapeDecorator>> GetGroup() = 0;
	virtual void SetPosition(CPoint newPosition) = 0;

private:
	uint32_t m_fillColor = 000000;
	int m_borederSize = 1;
	CPoint m_ownershipLeftTopPoint = CPoint(0, 0);
	int m_ownershipWidth = 0;
	int m_ownershipHeight = 0;
};