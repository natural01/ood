#include "Save.h"

int const BUTTON_POSOITION_X = 850;
int const BUTTON_POSOITION_Y = 540;
int const BUTTON_POSOITION_ACCESS_Y = 26;
int const WIDTH_BUTTON = 100;
int const HEIGHT_BUTTON = 20;
string const BUTTON_COLOR = "C0C0C0";
string const TEXT = "Save file";
double const FIGURE_TEXT_POSITION_X = 860.0;
double const FIGURE_TEXT_POSITION_Y = 536.0;
double const FIGIRE_POSOTION_ACCESS_Y = 26.0;

void Save::Draw(sf::RenderWindow& window)
{
	CPoint startButtonCircle = CPoint(BUTTON_POSOITION_X, BUTTON_POSOITION_Y + BUTTON_POSOITION_ACCESS_Y);
	CRectangle buttonCircle = CRectangle(startButtonCircle, WIDTH_BUTTON, HEIGHT_BUTTON, BUTTON_COLOR, BUTTON_COLOR, window);
	if (m_button.size() < 1) m_button.push_back(buttonCircle);
	buttonCircle.Draw(window);
	CText circle(TEXT, FIGURE_TEXT_POSITION_X, FIGURE_TEXT_POSITION_Y + FIGIRE_POSOTION_ACCESS_Y);
	window.draw(circle.getText());
}

MenuButtonsState Save::GetState(sf::Vector2i point)
{
	if (((point.x < m_button[0].GetLeftTopPoint().x() + m_button[0].GetWidth() && point.x > m_button[0].GetLeftTopPoint().x()) && (point.y < m_button[0].GetLeftTopPoint().y() + m_button[0].GetHeight() && point.y > m_button[0].GetLeftTopPoint().y()))
		&& m_button[0].GetFillColor() == 12632256 && m_button[0].GetLeftTopPoint().x() == 850)
	{
		if (m_button[0].GetLeftTopPoint().y() == BUTTON_POSOITION_Y + BUTTON_POSOITION_ACCESS_Y) { return MenuButtonsState::Save; }
	}
	return MenuButtonsState::None;
}
