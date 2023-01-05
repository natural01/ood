#include "CText.h"

sf::Text CText::getText()
{
	sf::Text text("", m_font, 20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(m_x, m_y);
	text.setString(m_content);
	return text;
}

void CText::setX(double x)
{
	m_x = x;
}

void CText::setY(double y)
{
	m_y = y;
}
