#include "ChangingBorder.h"

string const BORDER[3] = { "1", "2", "3" };
int const SIZE_BUTTON = 20;
string const BUTTON_COLOR = "C0C0C0";
int const COLOR_BUTTON_POSITION_X = 810;
int const COLOR_BUTTON_POSITION_Y = 200;
int const COLOR_BUTTON_POSITION_ACCESS_X = 30;
double const BORDER_BUTTON_POSITION_X = 815.0;
double const BORDER_BUTTON_POSITION_Y = 266.0;
double const BORDER_BUTTON_POSITION_ACCESS_X = 30.0;

void ChangingBorder::Draw(sf::RenderWindow& window)
{
	CText border("change border size: ", 820.0, 240.0);
	window.draw(border.getText());

	for (int count = 0; count < 3; count++)
	{
		CPoint startborderSize = CPoint(COLOR_BUTTON_POSITION_X + COLOR_BUTTON_POSITION_ACCESS_X * count, 270);
		CRectangle borderSize = CRectangle(startborderSize, SIZE_BUTTON, SIZE_BUTTON, BUTTON_COLOR, BUTTON_COLOR, window);
		m_buttons.push_back(borderSize);
		borderSize.Draw(window);
		CText borderText(BORDER[count], BORDER_BUTTON_POSITION_X + BORDER_BUTTON_POSITION_ACCESS_X * count, BORDER_BUTTON_POSITION_Y);
		window.draw(borderText.getText());
	}
}

MenuButtonsState ChangingBorder::GetState(sf::Vector2i point)
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (((point.x < m_buttons[i].GetLeftTopPoint().x() + m_buttons[i].GetWidth() && point.x > m_buttons[i].GetLeftTopPoint().x()) && (point.y < m_buttons[i].GetLeftTopPoint().y() + m_buttons[i].GetHeight() && point.y > m_buttons[i].GetLeftTopPoint().y()))
			&& m_buttons[i].GetFillColor() == 12632256 && m_buttons[i].GetLeftTopPoint().y() == 270)
		{
			if (m_buttons[i].GetLeftTopPoint().x() == 810) return MenuButtonsState::ChangeBorderSize1;
			if (m_buttons[i].GetLeftTopPoint().x() == 840) return MenuButtonsState::ChangeBorderSize2;
			if (m_buttons[i].GetLeftTopPoint().x() == 870) return MenuButtonsState::ChangeBorderSize3;
		}
	}
	return MenuButtonsState::None;
}
