#include "Application.h"
#include "Visitor.h"

using namespace std;

float getPointForFigure(figures figure)
{
	switch (figure)
	{
	case figures::Line:
		return 88.0;
		break;
	case figures::Circle:
		return 36.0;
		break;
	case figures::Rectangle:
		return 62.0;
		break;
	case figures::Triangle:
		return 114.0;
		break;
	default:
		return 0.0;
	}
}

string getFigureString(figures figure)
{
	switch (figure)
	{
	case figures::Line:
		return "Line";
		break;
	case figures::Circle:
		return "Circle";
		break;
	case figures::Rectangle:
		return "Rectangle";
		break;
	case figures::Triangle:
		return "Triangle";
		break;
	default:
		return "";
	}
}

void Application::drowPanel()
{
	m_addingShape.Draw(m_window);
	m_saveFile.Draw(m_window);
}

void Application::drowPanelForChangeFigure()
{
	m_changingBorder.Draw(m_window);
	m_changingColor.Draw(m_window);
}

bool Application::buttonPressed(sf::Vector2i point)
{
	Visitor visitor(m_addingShape, m_changingColor, m_changingBorder, m_saveFile);
	return visitor.GetChange(m_observer, point, m_window);
}