#include "Application.h"

using namespace std;

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
	CLineSegment line = CLineSegment(startLine, finishLine, "000", m_window);
	line.Draw(m_window);

	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf");
	sf::Text text("", font, 20);
	text.setFillColor(sf::Color::Black);
	text.setPosition(820.0, 10.0);
	text.setString("add new figure: ");
	m_window.draw(text);

	CPoint startButtonCircle = CPoint(850, 40);
	CRectangle buttonCircle = CRectangle(startButtonCircle, 100, 20, "C0C0C0", "C0C0C0", m_window);
	m_buttons.push_back(buttonCircle);
	buttonCircle.Draw(m_window);
	sf::Text textCircle("", font, 20);
	textCircle.setFillColor(sf::Color::Black);
	textCircle.setPosition(860.0, 36.0);
	textCircle.setString("Circle");
	m_window.draw(textCircle);

	CPoint startButtonRectangle = CPoint(850, 66);
	CRectangle buttonRectangle = CRectangle(startButtonRectangle, 100, 20, "C0C0C0", "C0C0C0", m_window);
	m_buttons.push_back(buttonRectangle);
	buttonRectangle.Draw(m_window);
	sf::Text textRectangle("", font, 20);
	textRectangle.setFillColor(sf::Color::Black);
	textRectangle.setPosition(860.0, 62.0);
	textRectangle.setString("Rectangle");
	m_window.draw(textRectangle);

	CPoint startButtonLine = CPoint(850, 92);
	CRectangle buttonLine = CRectangle(startButtonLine, 100, 20, "C0C0C0", "C0C0C0", m_window);
	m_buttons.push_back(buttonLine);
	buttonLine.Draw(m_window);
	sf::Text textLine("", font, 20);
	textLine.setFillColor(sf::Color::Black);
	textLine.setPosition(860.0, 88.0);
	textLine.setString("Line");
	m_window.draw(textLine);

	CPoint startButtonTriangle = CPoint(850, 118);
	CRectangle buttonTriangle = CRectangle(startButtonTriangle, 100, 20, "C0C0C0", "C0C0C0", m_window);
	m_buttons.push_back(buttonTriangle);
	buttonTriangle.Draw(m_window);
	sf::Text textTriangle("", font, 20);
	textTriangle.setFillColor(sf::Color::Black);
	textTriangle.setPosition(860.0, 114.0);
	textTriangle.setString("Triangle");
	m_window.draw(textTriangle);
}

void Application::drowPanelForChangeFigure()
{
	// change figure color

	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf");
	sf::Text changeFigureColor("", font, 20);
	changeFigureColor.setFillColor(sf::Color::Black);
	changeFigureColor.setPosition(820.0, 170.0);
	changeFigureColor.setString("change figure color: ");
	m_window.draw(changeFigureColor);

	CPoint startButtonRed = CPoint(810, 200);
	CRectangle buttonRed = CRectangle(startButtonRed, 20, 20, "000000", "FF0000", m_window);
	m_buttons.push_back(buttonRed);
	buttonRed.Draw(m_window);

	CPoint startButtonBlue = CPoint(840, 200);
	CRectangle buttonBlue = CRectangle(startButtonBlue, 20, 20, "000000", "0000FF", m_window);
	m_buttons.push_back(buttonBlue);
	buttonBlue.Draw(m_window);

	CPoint startButtonGreen = CPoint(870, 200);
	CRectangle buttonGreen = CRectangle(startButtonGreen, 20, 20, "000000", "008000", m_window);
	m_buttons.push_back(buttonGreen);
	buttonGreen.Draw(m_window);

	CPoint startButtonWhite = CPoint(900, 200);
	CRectangle buttonWhite = CRectangle(startButtonWhite, 20, 20, "000000", "FFFFFF", m_window);
	m_buttons.push_back(buttonWhite);
	buttonWhite.Draw(m_window);

	CPoint startButtonBlack = CPoint(930, 200);
	CRectangle buttonBlack = CRectangle(startButtonBlack, 20, 20, "000000", "000000", m_window);
	m_buttons.push_back(buttonBlack);
	buttonBlack.Draw(m_window);

	// change border size

	sf::Text changeBorderSize("", font, 20);
	changeBorderSize.setFillColor(sf::Color::Black);
	changeBorderSize.setPosition(820.0, 240.0);
	changeBorderSize.setString("change border size: ");
	m_window.draw(changeBorderSize);

	CPoint startborderSize1 = CPoint(810, 270);
	CRectangle borderSize1 = CRectangle(startborderSize1, 20, 20, "C0C0C0", "C0C0C0", m_window);
	m_buttons.push_back(borderSize1);
	borderSize1.Draw(m_window);
	sf::Text textBorderSize1("", font, 20);
	textBorderSize1.setFillColor(sf::Color::Black);
	textBorderSize1.setPosition(815.0, 266.0);
	textBorderSize1.setString("1");
	m_window.draw(textBorderSize1);

	CPoint startborderSize2 = CPoint(840, 270);
	CRectangle borderSize2 = CRectangle(startborderSize2, 20, 20, "C0C0C0", "C0C0C0", m_window);
	m_buttons.push_back(borderSize2);
	borderSize2.Draw(m_window);
	sf::Text textBorderSize2("", font, 20);
	textBorderSize2.setFillColor(sf::Color::Black);
	textBorderSize2.setPosition(845.0, 266.0);
	textBorderSize2.setString("2");
	m_window.draw(textBorderSize2);

	CPoint startborderSize3 = CPoint(870, 270);
	CRectangle borderSize3 = CRectangle(startborderSize3, 20, 20, "C0C0C0", "C0C0C0", m_window);
	m_buttons.push_back(borderSize3);
	borderSize3.Draw(m_window);
	sf::Text textBorderSize3("", font, 20);
	textBorderSize3.setFillColor(sf::Color::Black);
	textBorderSize3.setPosition(875.0, 266.0);
	textBorderSize3.setString("3");
	m_window.draw(textBorderSize3);
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
					{
						for (const auto& shape : m_observer->getShapes())
							if (shape->GetOwnership())
								shape->SetBorder(1);
					}
					if (m_buttons[i].GetLeftTopPoint().x() == 840)
					{
						for (const auto& shape : m_observer->getShapes())
							if (shape->GetOwnership())
								shape->SetBorder(2);
					}
					if (m_buttons[i].GetLeftTopPoint().x() == 870)
					{
						for (const auto& shape : m_observer->getShapes())
							if (shape->GetOwnership())
								shape->SetBorder(3);
					}
				}
			}
			else
			{
				switch (m_buttons[i].GetFillColor())
				{
				case 16711680:
					for (const auto& shape : m_observer->getShapes())
						if (shape->GetOwnership())
							shape->SetFillColor(16711680);
					break;
				case 255:
					for (const auto& shape : m_observer->getShapes())
						if (shape->GetOwnership())
							shape->SetFillColor(255);
					break;
				case 32768:
					for (const auto& shape : m_observer->getShapes())
						if (shape->GetOwnership())
							shape->SetFillColor(32768);
					break;
				case 16777215:
					for (const auto& shape : m_observer->getShapes())
						if (shape->GetOwnership())
							shape->SetFillColor(16777215);
					break;
				case 0:
					for (const auto& shape : m_observer->getShapes())
						if (shape->GetOwnership())
							shape->SetFillColor(0);
					break;
				}
			}
			return true;
		}
	}
	return false;
}

void Application::nullState()
{
	m_colorState = ColorState::None;
}

ColorState Application::getColorState()
{
	return m_colorState;
}