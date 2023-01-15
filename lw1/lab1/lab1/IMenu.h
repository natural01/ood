#pragma once
#include <SFML/Graphics.hpp>
#include "MenuButtonsState.h"

using namespace std;

class IMenu
{
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual MenuButtonsState GetState(sf::Vector2i point) = 0;
};