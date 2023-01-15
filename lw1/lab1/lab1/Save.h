#pragma once
#include "IMenu.h"
#include "CText.h"
#include "Point.h"
#include "LineSegment.h"
#include "Rectangle.h"

class Save : public IMenu
{
public:
	void Draw(sf::RenderWindow& window);
	MenuButtonsState GetState(sf::Vector2i point);

private:
	std::vector<CRectangle> m_button;
};