#pragma once
#include <SFML/Graphics.hpp>
#include "vector"
#include "LineSegment.h"
#include "Rectangle.h"
#include "Point.h"
#include "ConsoleCommand.h"
#include "States.h"

class Application
{
public:
	static Application& getInstance()
	{
		static Application instance;
		return instance;
	};
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;
	 
	void drowPanel(sf::RenderWindow& window);
	void drowPanelForChangeFigure(sf::RenderWindow& window);
	bool buttonPressed(sf::Vector2i point);
	void nullState();

	ColorState getColorState();
	BorderSizeState getBorderState();
	addFigure getAddFigureState();
private:
	Application()
	{
	}
	std::vector<CRectangle> m_buttons;
	ColorState m_colorState = ColorState::None;
	BorderSizeState m_borderSizeState = BorderSizeState::None;
	addFigure m_addFigure = addFigure::None;
};