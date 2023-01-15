#include "AddingShape.h"

double const TITLE_POSITION_X = 820.0;
double const TITLE_POSITION_Y = 10.0;
int const COUNT_OF_FIGURES = 4;
int const BUTTON_POSOITION_X = 850;
int const BUTTON_POSOITION_Y = 40;
int const BUTTON_POSOITION_ACCESS_Y = 26;
int const WIDTH_BUTTON = 100;
int const HEIGHT_BUTTON = 20;
string const BUTTON_COLOR = "C0C0C0";
string const FIGURES[4] = { "Circle", "Rectangle", "Line", "Triangle" };
double const FIGURE_TEXT_POSITION_X = 860.0;
double const FIGURE_TEXT_POSITION_Y = 36.0;
double const FIGIRE_POSOTION_ACCESS_Y = 26.0;

void AddingShape::Draw(sf::RenderWindow& window)
{
	CPoint startLine = CPoint(800, 0);
	CPoint finishLine = CPoint(800, 600);
	CLineSegment markup = CLineSegment(startLine, finishLine, "000", window);
	markup.Draw(window);

	CText title("add new figure: ", TITLE_POSITION_X, TITLE_POSITION_Y);
	window.draw(title.getText());

	for (int count = 0; count < COUNT_OF_FIGURES; count++)
	{
		CPoint startButtonCircle = CPoint(BUTTON_POSOITION_X, BUTTON_POSOITION_Y + BUTTON_POSOITION_ACCESS_Y * count);
		CRectangle buttonCircle = CRectangle(startButtonCircle, WIDTH_BUTTON, HEIGHT_BUTTON, BUTTON_COLOR, BUTTON_COLOR, window);
		m_buttons.push_back(buttonCircle);
		buttonCircle.Draw(window);
		CText circle(FIGURES[count], FIGURE_TEXT_POSITION_X, FIGURE_TEXT_POSITION_Y + FIGIRE_POSOTION_ACCESS_Y * count);
		window.draw(circle.getText());
	}
}

MenuButtonsState AddingShape::GetState(sf::Vector2i point)
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (((point.x < m_buttons[i].GetLeftTopPoint().x() + m_buttons[i].GetWidth() && point.x > m_buttons[i].GetLeftTopPoint().x()) && (point.y < m_buttons[i].GetLeftTopPoint().y() + m_buttons[i].GetHeight() && point.y > m_buttons[i].GetLeftTopPoint().y())) 
			&& m_buttons[i].GetFillColor() == 12632256 && m_buttons[i].GetLeftTopPoint().x() == 850)
		{
			if (m_buttons[i].GetLeftTopPoint().y() == 40) { return MenuButtonsState::AddCircle; }
			if (m_buttons[i].GetLeftTopPoint().y() == 66) { return MenuButtonsState::AddRectangle; }
			if (m_buttons[i].GetLeftTopPoint().y() == 92) { return MenuButtonsState::AddLine; }
			if (m_buttons[i].GetLeftTopPoint().y() == 118) { return MenuButtonsState::AddTriangle; }
		}
	}
	return MenuButtonsState::None;
}
