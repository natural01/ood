#include "Application.h"

using namespace std;

static sf::Color GetValidateColor(uint32_t color)
{
	uint32_t red = ((color / 256) / 256) % 256;
	uint32_t green = (color / 256) % 256;
	uint32_t blue = color % 256;
	return sf::Color(red, green, blue);
}

void Application::drowPanel(sf::RenderWindow& const window)
{
	CPoint startLine = CPoint(800, 0);
	CPoint finishLine = CPoint(800, 600);
	CLineSegment line = CLineSegment(startLine, finishLine, "000", window);
	line.Draw(window);

	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf");
	sf::Text text("", font, 20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(820.0, 10.0);
	text.setString("add new figure: ");
	window.draw(text);

	CPoint startButtonCircle = CPoint(850, 40);
	CRectangle buttonCircle = CRectangle(startButtonCircle, 100, 20, "C0C0C0", "C0C0C0", window);
	m_buttons.push_back(buttonCircle);
	buttonCircle.Draw(window);
	sf::Text textCircle("", font, 20);
	textCircle.setFillColor(sf::Color::Black);
	textCircle.setPosition(860.0, 36.0);
	textCircle.setString("Circle");
	window.draw(textCircle);

	CPoint startButtonRectangle = CPoint(850, 66);
	CRectangle buttonRectangle = CRectangle(startButtonRectangle, 100, 20, "C0C0C0", "C0C0C0", window);
	m_buttons.push_back(buttonRectangle);
	buttonRectangle.Draw(window);
	sf::Text textRectangle("", font, 20);
	textRectangle.setFillColor(sf::Color::Black);
	textRectangle.setPosition(860.0, 62.0);
	textRectangle.setString("Rectangle");
	window.draw(textRectangle);

	CPoint startButtonLine = CPoint(850, 92);
	CRectangle buttonLine = CRectangle(startButtonLine, 100, 20, "C0C0C0", "C0C0C0", window);
	m_buttons.push_back(buttonLine);
	buttonLine.Draw(window);
	sf::Text textLine("", font, 20);
	textLine.setFillColor(sf::Color::Black);
	textLine.setPosition(860.0, 88.0);
	textLine.setString("Line");
	window.draw(textLine);

	CPoint startButtonTriangle = CPoint(850, 118);
	CRectangle buttonTriangle = CRectangle(startButtonTriangle, 100, 20, "C0C0C0", "C0C0C0", window);
	m_buttons.push_back(buttonTriangle);
	buttonTriangle.Draw(window);
	sf::Text textTriangle("", font, 20);
	textTriangle.setFillColor(sf::Color::Black);
	textTriangle.setPosition(860.0, 114.0);
	textTriangle.setString("Triangle");
	window.draw(textTriangle);
}

void Application::drowPanelForChangeFigure(sf::RenderWindow& window)
{
	// change figure color

	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf");
	sf::Text changeFigureColor("", font, 20);
	changeFigureColor.setFillColor(sf::Color::Black);
	changeFigureColor.setPosition(820.0, 170.0);
	changeFigureColor.setString("change figure color: ");
	window.draw(changeFigureColor);

	CPoint startButtonRed = CPoint(810, 200);
	CRectangle buttonRed = CRectangle(startButtonRed, 20, 20, "000000", "FF0000", window);
	m_buttons.push_back(buttonRed);
	buttonRed.Draw(window);

	CPoint startButtonBlue = CPoint(840, 200);
	CRectangle buttonBlue = CRectangle(startButtonBlue, 20, 20, "000000", "0000FF", window);
	m_buttons.push_back(buttonBlue);
	buttonBlue.Draw(window);

	CPoint startButtonGreen = CPoint(870, 200);
	CRectangle buttonGreen = CRectangle(startButtonGreen, 20, 20, "000000", "008000", window);
	m_buttons.push_back(buttonGreen);
	buttonGreen.Draw(window);

	CPoint startButtonWhite = CPoint(900, 200);
	CRectangle buttonWhite = CRectangle(startButtonWhite, 20, 20, "000000", "FFFFFF", window);
	m_buttons.push_back(buttonWhite);
	buttonWhite.Draw(window);

	CPoint startButtonBlack = CPoint(930, 200);
	CRectangle buttonBlack = CRectangle(startButtonBlack, 20, 20, "000000", "000000", window);
	m_buttons.push_back(buttonBlack);
	buttonBlack.Draw(window);

	// change border size

	sf::Text changeBorderSize("", font, 20);
	changeBorderSize.setFillColor(sf::Color::Black);
	changeBorderSize.setPosition(820.0, 240.0);
	changeBorderSize.setString("change border size: ");
	window.draw(changeBorderSize);

	CPoint startborderSize1 = CPoint(810, 270);
	CRectangle borderSize1 = CRectangle(startborderSize1, 20, 20, "C0C0C0", "C0C0C0", window);
	m_buttons.push_back(borderSize1);
	borderSize1.Draw(window);
	sf::Text textBorderSize1("", font, 20);
	textBorderSize1.setFillColor(sf::Color::Black);
	textBorderSize1.setPosition(815.0, 266.0);
	textBorderSize1.setString("1");
	window.draw(textBorderSize1);

	CPoint startborderSize2 = CPoint(840, 270);
	CRectangle borderSize2 = CRectangle(startborderSize2, 20, 20, "C0C0C0", "C0C0C0", window);
	m_buttons.push_back(borderSize2);
	borderSize2.Draw(window);
	sf::Text textBorderSize2("", font, 20);
	textBorderSize2.setFillColor(sf::Color::Black);
	textBorderSize2.setPosition(845.0, 266.0);
	textBorderSize2.setString("2");
	window.draw(textBorderSize2);

	CPoint startborderSize3 = CPoint(870, 270);
	CRectangle borderSize3 = CRectangle(startborderSize3, 20, 20, "C0C0C0", "C0C0C0", window);
	m_buttons.push_back(borderSize3);
	borderSize3.Draw(window);
	sf::Text textBorderSize3("", font, 20);
	textBorderSize3.setFillColor(sf::Color::Black);
	textBorderSize3.setPosition(875.0, 266.0);
	textBorderSize3.setString("3");
	window.draw(textBorderSize3);
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
					if (m_buttons[i].GetLeftTopPoint().y() == 40) { m_addFigure = addFigure::addCircle; }
					if (m_buttons[i].GetLeftTopPoint().y() == 66) { m_addFigure = addFigure::addRectangle; }
					if (m_buttons[i].GetLeftTopPoint().y() == 92) { m_addFigure = addFigure::addLine; }
					if (m_buttons[i].GetLeftTopPoint().y() == 118) { m_addFigure = addFigure::addTriangle; }
				}
				else
				{
					m_addFigure = addFigure::None;
				}
				if (m_buttons[i].GetLeftTopPoint().y() == 270)
				{
					if (m_buttons[i].GetLeftTopPoint().x() == 810) { m_borderSizeState = BorderSizeState::ChangeSizeFor1; }
					if (m_buttons[i].GetLeftTopPoint().x() == 840) { m_borderSizeState = BorderSizeState::ChangeSizeFor2; }
					if (m_buttons[i].GetLeftTopPoint().x() == 870) { m_borderSizeState = BorderSizeState::ChangeSizeFor3; }
				}
				else
				{
					m_borderSizeState = BorderSizeState::None;
				}
			}
			else
			{
				switch (m_buttons[i].GetFillColor())
				{
				case 16711680:
					m_colorState = ColorState::ChangeColorForRed;
					break;
				case 255:
					m_colorState = ColorState::ChangeColorForBlue;
					break;
				case 32768:
					m_colorState = ColorState::ChangeColorForGreen;
					break;
				case 16777215:
					m_colorState = ColorState::ChangeColorForWhite;
					break;
				case 0:
					m_colorState = ColorState::ChangeColorForBlack;
					break;
				default:
					m_colorState = ColorState::None;
				}
			}
			return true;
		}
	}
	return false;
}