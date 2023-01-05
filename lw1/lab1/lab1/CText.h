#pragma once
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class CText
{
public:
	CText(string content, double x, double y) : m_content(content), m_x(x), m_y(y)
	{
		m_font.loadFromFile("CyrilicOld.ttf");
	}

	sf::Text getText();
	void setX(double x);
	void setY(double y);

private:
	string m_content;
	sf::Font m_font;
	double m_x;
	double m_y;
};