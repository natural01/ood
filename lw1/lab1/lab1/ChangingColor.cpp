#include "ChangingColor.h"

string const COLORS[5] = { "FF0000", "0000FF", "008000", "FFFFFF", "000000" };
int const COLOR_BUTTON_POSITION_X = 810;
int const COLOR_BUTTON_POSITION_Y = 200;
int const COLOR_BUTTON_POSITION_ACCESS_X = 30;
int const SIZE_BUTTON = 20;
string const COLOR_OF_COLOR_BUTTON = "000000";

void ChangingColor::Draw(sf::RenderWindow& window)
{
	CText color("change figure color: ", 820.0, 170.0);
	window.draw(color.getText());

	for (int count = 0; count < COLORS->size() - 1; count++)
	{
		CPoint startButton = CPoint(COLOR_BUTTON_POSITION_X + COLOR_BUTTON_POSITION_ACCESS_X * count, COLOR_BUTTON_POSITION_Y);
		CRectangle button = CRectangle(startButton, SIZE_BUTTON, SIZE_BUTTON, COLOR_OF_COLOR_BUTTON, COLORS[count], window);
		m_buttons.push_back(button);
		button.Draw(window);
	}
}

MenuButtonsState ChangingColor::GetState(sf::Vector2i point)
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (((point.x < m_buttons[i].GetLeftTopPoint().x() + m_buttons[i].GetWidth() && point.x > m_buttons[i].GetLeftTopPoint().x()) && (point.y < m_buttons[i].GetLeftTopPoint().y() + m_buttons[i].GetHeight() && point.y > m_buttons[i].GetLeftTopPoint().y()))
			&& m_buttons[i].GetFillColor() != 12632256)
		{
			switch (m_buttons[i].GetFillColor())
			{
			case 16711680:
				return MenuButtonsState::ChangeColorRed;
				break;
			case 255:
				return MenuButtonsState::ChangeColorBlue;
				break;
			case 32768:
				return MenuButtonsState::ChangeColorGreen;
				break;
			case 16777215:
				return MenuButtonsState::ChangeColorWhite;
				break;
			case 0:
				return MenuButtonsState::ChangeColorBlack;
				break;
			}
		}
	}
	return MenuButtonsState::None;
}
