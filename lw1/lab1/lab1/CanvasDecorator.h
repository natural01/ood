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

	void SetFillColor(uint32_t const& color) override;
	uint32_t GetFillColor() const;

	void SetOutlineColor(uint32_t const& color) override;
	uint32_t GetOutlineColor() const;

private:
	uint32_t m_fillColor = 000000;
};