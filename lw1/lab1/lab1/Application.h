#pragma once
#include <SFML/Graphics.hpp>
#include "vector"
#include "LineSegment.h"
#include "Rectangle.h"
#include "Point.h"
#include "ConsoleCommand.h"
#include "States.h"

class CConsoleCommand;
class Application
{
public:
	static Application& getInstance(CConsoleCommand* observer, sf::RenderWindow& window)
	{
		static Application instance(observer, window);
		return instance;
	};
	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;
	 
	void drowPanel();
	void drowPanelForChangeFigure();
	bool buttonPressed(sf::Vector2i point);
	void nullState();

	ColorState getColorState();
private:
	Application(CConsoleCommand* observer, sf::RenderWindow& window): m_observer(observer), m_window(window)
	{
	}
	std::vector<CRectangle> m_buttons;
	ColorState m_colorState = ColorState::None;
	CConsoleCommand* m_observer;
	sf::RenderWindow& m_window;
};