#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ShapeDecorator.h"
#include "Application.h"
#include "CShapeComposite.h"

using namespace std;

class CApplicationWindow
{
public:
	CApplicationWindow(sf::RenderWindow& window, vector<shared_ptr<ShapeDecorator>>& shapes, sf::Vector2i mousePosition, Mementro& history)
		: m_window(window)
		, m_shapes(shapes)
		, m_mousePosition(mousePosition)
		, m_history(history)
	{
	}

	sf::Event getEvent() const;
	void drawShapes(Application& instance) const;
	void mousePressEvent(Application& instance);
	void mouseReleasEvent();
	void createGroup();
	void unGroup();
	void UnDo();
	void ReDo();
	void CreateHistory();

private:
	sf::RenderWindow& m_window;
	vector<shared_ptr<ShapeDecorator>>& m_shapes;
	Mementro& m_history;
	sf::Vector2i m_mousePosition;
	bool m_mouseReleasTrigger = false;
	bool m_mouseClickTrigger = true;
	bool m_createGroupTriger = false;
};