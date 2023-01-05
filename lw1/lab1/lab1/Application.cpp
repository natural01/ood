#include "Application.h"

using namespace std;

double const TITLE_POSITION_X = 820.0;
double const TITLE_POSITION_Y = 10.0;
double const FIGURE_TEXT_POSITION_X = 860.0;
double const FIGURE_TEXT_POSITION_Y = 36.0;
double const FIGIRE_POSOTION_ACCESS_Y = 26.0;
int const WIDTH_BUTTON = 100;
int const HEIGHT_BUTTON = 20;
int const BUTTON_POSOITION_X = 850;
int const BUTTON_POSOITION_Y = 40;
int const BUTTON_POSOITION_ACCESS_Y = 26;
string const BUTTON_COLOR = "C0C0C0";
int const COUNT_OF_FIGURES = 4;
string const FIGURES[4] = { "Circle", "Rectangle", "Line", "Triangle" };
string const COLORS[5] = { "FF0000", "0000FF", "008000", "FFFFFF", "000000" };
string const COLOR_OF_COLOR_BUTTON = "000000";
int const COLOR_BUTTON_POSITION_X = 810;
int const COLOR_BUTTON_POSITION_Y = 200;
int const COLOR_BUTTON_POSITION_ACCESS_X = 30;
int const SIZE_BUTTON = 20;
string const BORDER[3] = { "1", "2", "3" };
double const BORDER_BUTTON_POSITION_X = 815.0;
double const BORDER_BUTTON_POSITION_Y = 266.0;
double const BORDER_BUTTON_POSITION_ACCESS_X = 30.0;

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

sf::Text addButton(sf::RenderWindow& window, std::vector<CRectangle>* buttons, figures figure)
{
	sf::Font font;
	CPoint startButtonLine = CPoint(850, getPointForFigure(figure)+4);
	CRectangle buttonLine = CRectangle(startButtonLine, 100, 20, "C0C0C0", "C0C0C0", window);
	buttons->push_back(buttonLine);
	buttonLine.Draw(window);
	sf::Text text("", font, 20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(860.0, getPointForFigure(figure));
	text.setString(getFigureString(figure));
	return text;
}

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

void Application::drowPanel()
{
	CPoint startLine = CPoint(800, 0);
	CPoint finishLine = CPoint(800, 600);
	CLineSegment markup = CLineSegment(startLine, finishLine, "000", m_window);
	markup.Draw(m_window);

	CText title("add new figure: ", TITLE_POSITION_X, TITLE_POSITION_Y);
	m_window.draw(title.getText());

	for (int count = 0; count < COUNT_OF_FIGURES; count++)
	{
		CPoint startButtonCircle = CPoint(BUTTON_POSOITION_X, BUTTON_POSOITION_Y + BUTTON_POSOITION_ACCESS_Y * count);
		CRectangle buttonCircle = CRectangle(startButtonCircle, WIDTH_BUTTON, HEIGHT_BUTTON, BUTTON_COLOR, BUTTON_COLOR, m_window);
		m_buttons.push_back(buttonCircle);
		buttonCircle.Draw(m_window);
		CText circle(FIGURES[count], FIGURE_TEXT_POSITION_X, FIGURE_TEXT_POSITION_Y + FIGIRE_POSOTION_ACCESS_Y * count);
		m_window.draw(circle.getText());
	}
}

void Application::drowPanelForChangeFigure()
{
	CText color("change figure color: ", 820.0, 170.0);
	m_window.draw(color.getText());

	for (int count = 0; count < COLORS->size() - 1; count++)
	{
		CPoint startButton = CPoint(COLOR_BUTTON_POSITION_X + COLOR_BUTTON_POSITION_ACCESS_X * count, COLOR_BUTTON_POSITION_Y);
		CRectangle button = CRectangle(startButton, SIZE_BUTTON, SIZE_BUTTON, COLOR_OF_COLOR_BUTTON, COLORS[count], m_window);
		m_buttons.push_back(button);
		button.Draw(m_window);
	}

	CText border("change border size: ", 820.0, 240.0);
	m_window.draw(border.getText());

	for (int count = 0; count < 3; count++)
	{
		CPoint startborderSize = CPoint(COLOR_BUTTON_POSITION_X + COLOR_BUTTON_POSITION_ACCESS_X * count, 270);
		CRectangle borderSize = CRectangle(startborderSize, SIZE_BUTTON, SIZE_BUTTON, BUTTON_COLOR, BUTTON_COLOR, m_window);
		m_buttons.push_back(borderSize);
		borderSize.Draw(m_window);
		CText borderText(BORDER[count], BORDER_BUTTON_POSITION_X + BORDER_BUTTON_POSITION_ACCESS_X * count, BORDER_BUTTON_POSITION_Y);
		m_window.draw(borderText.getText());
	}
}

void ChangeColor(CConsoleCommand* application, uint32_t const& color)
{
	for (const auto& shape : application->getShapes())
		if (shape->GetSelect())
		{
			if (!shape->GetGroup().empty())
			{
				for (const auto& subShape : shape->GetGroup())
				{
					subShape->SetFillColor(color);
				}
			}
			else
			{
				shape->SetFillColor(color);
			}
		}
}
void ChangeBorderSize(CConsoleCommand* application, int size)
{
	for (const auto& shape : application->getShapes())
		if (shape->GetSelect())
		{
			if (!shape->GetGroup().empty())
			{
				for (const auto& subShape : shape->GetGroup())
				{
					subShape->SetBorder(size);
				}
			}
			else
			{
				shape->SetBorder(size);
			}
		}
}

bool Application::buttonPressed(sf::Vector2i point)
{
	for (int i = 0; i < m_buttons.size(); i++)
	{
		if (((point.x < m_buttons[i].GetLeftTopPoint().x() + m_buttons[i].GetWidth() && point.x > m_buttons[i].GetLeftTopPoint().x()) && (point.y < m_buttons[i].GetLeftTopPoint().y() + m_buttons[i].GetHeight() && point.y > m_buttons[i].GetLeftTopPoint().y())))
		{
			if (m_buttons[i].GetFillColor() == 12632256)
			{
				if (m_buttons[i].GetLeftTopPoint().x() == 850)
				{
					if (m_buttons[i].GetLeftTopPoint().y() == 40) { m_observer->addShapes(figures::Circle, m_window); }
					if (m_buttons[i].GetLeftTopPoint().y() == 66) { m_observer->addShapes(figures::Rectangle, m_window); }
					if (m_buttons[i].GetLeftTopPoint().y() == 92) { m_observer->addShapes(figures::Line, m_window); }
					if (m_buttons[i].GetLeftTopPoint().y() == 118) { m_observer->addShapes(figures::Triangle, m_window); }
				}
				if (m_buttons[i].GetLeftTopPoint().y() == 270)
				{
					if (m_buttons[i].GetLeftTopPoint().x() == 810)
						ChangeBorderSize(m_observer, 1);
					if (m_buttons[i].GetLeftTopPoint().x() == 840)
						ChangeBorderSize(m_observer, 2);
					if (m_buttons[i].GetLeftTopPoint().x() == 870)
						ChangeBorderSize(m_observer, 3);
				}
			}
			else
			{
				switch (m_buttons[i].GetFillColor())
				{
				case 16711680:
					ChangeColor(m_observer, 16711680);
					break;
				case 255:
					ChangeColor(m_observer, 255);
					break;
				case 32768:
					ChangeColor(m_observer, 32768);
					break;
				case 16777215:
					ChangeColor(m_observer, 16777215);
					break;
				case 0:
					ChangeColor(m_observer, 0);
					break;
				}
			}
			return true;
		}
	}
	return false;
}