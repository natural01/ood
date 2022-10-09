#pragma once
#include <vector>
#include <string>
#include "SolidShape.h"
#include "Point.h"
#include <SFML/Graphics.hpp>

class CanvasDecorator : public CSolidShape
{
public:
	virtual ~CanvasDecorator() = default;

	virtual void Draw(sf::RenderWindow& windiw) const = 0;

	virtual void SetOwnership(sf::Vector2i point) = 0;
	virtual bool GetOwnership(sf::Vector2i point) = 0;

	void SetFillColor(uint32_t const& color) override;
	uint32_t GetFillColor() const;

	void SetOutlineColor(uint32_t const& color) override;
	uint32_t GetOutlineColor() const;

	virtual int GetOwnershipWidth() = 0;
	virtual int GetOwnershipHeight() = 0;
	virtual CPoint GetOwnershipLeftTopPoint() = 0;
	void SetOwnershipWidth(double width);
	void EetOwnershipHeight(double height);
	void SetOwnershipLeftTopPoint(CPoint leftTopPoint);

	virtual void SetPosition(CPoint newPosition) = 0;

private:
	uint32_t m_fillColor = 000000;
	CPoint m_ownershipLeftTopPoint = CPoint(0, 0);
	int m_ownershipWidth = 0;
	int m_ownershipHeight = 0;
};