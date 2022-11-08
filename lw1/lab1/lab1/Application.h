#pragma once
#include <SFML/Graphics.hpp>
#include "vector"
#include "LineSegment.h"
#include "Rectangle.h"
#include "Point.h"

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

	enum class addFigure
	{
		None,
		addCircle,
		addTriangle,
		addRectangle,
		addLine,
	};
	enum class ColorState
	{
		None,
		ChangeColorForRed,
		ChangeColorForGreen,
		ChangeColorForBlue,
		ChangeColorForBlack,
		ChangeColorForWhite,
	};
	enum class BorderSizeState
	{
		None,
		ChangeSizeFor1,
		ChangeSizeFor2,
		ChangeSizeFor3,
	};

	BorderSizeState getBorderSizeState();

	void drowPanel(sf::RenderWindow& window);
	void drowPanelForChangeFigure(sf::RenderWindow& window);
	bool buttonPressed(sf::Vector2i point);
private:
	Application()
	{
	}
	std::vector<CRectangle> m_buttons;
	ColorState m_colorState = ColorState::None;
	BorderSizeState m_borderSizeState = BorderSizeState::None;
	addFigure m_addFigure = addFigure::None;
};