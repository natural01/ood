#pragma once
#include "IMenu.h"
#include "CText.h"
#include "Point.h"
#include "LineSegment.h"
#include "Rectangle.h"

class AddingShape : public IMenu
{
public:
	void Draw(sf::RenderWindow& window) override;
	MenuButtonsState GetState(sf::Vector2i point) override;

private:
	std::vector<CRectangle> m_buttons;
};