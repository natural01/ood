#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "ConsoleCommand.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "SolidShape.h"
#include "Triangle.h"
#include "ShapeDecorator.h"
#include "Figures.h"
#include <fstream>
#include "CApplicationWindow.h"
#include "TextReader.h"
#include "TextConverter.h"

using namespace std;

string const Error_Incorrect_Argument = "Incorrect argument";
string const Error_Incorrect_Number_Of_Arguments = "Incorrect number of arguments";
string const Error_Incorrect_Shape = "Incorrect shape";
int const The_Number_Of_Elements_In_Line = 6;
int const The_Number_Of_Elements_In_Triangle = 9;
int const The_Number_Of_Elements_In_Rectangle = 7;
int const The_Number_Of_Elements_In_Circle = 6;
string const Line = "LineSegment";
string const Triangle = "Triangle";
string const Rectangle = "Rectangle";
string const Circle = "Circle";
string const Info_Max_Area = "Shape with max area:\n";
string const Info_Min_Perimeter = "Shape with min perimeter:\n";

string createDefoltCircle()
{
	return "Circle 200 500 50 000000 ffffff";
}
string createDefoltRectangle()
{
	return "Rectangle 200 500 150 100 000000 ffffff";
}
string createDefoltLine()
{
	return "LineSegment 200 500 300 600 000000";
}
string createDefoltTriangle()
{
	return "Triangle 350 400 300 500 400 500 000000 ffffff";
}

std::vector<std::shared_ptr<ShapeDecorator>> CConsoleCommand::getShapes()
{
	return m_shapes;
}

bool AreaCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetArea() < secondShape->GetArea();
}

bool PerimeterCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetPerimeter() < secondShape->GetPerimeter();
}

void CConsoleCommand::addShapes(figures newFigure, sf::RenderWindow& window)
{
	TextConverter textConverter = TextConverter(window);
	switch (newFigure)
	{
	case figures::Triangle:
		m_shapes.push_back(textConverter.ConvertText(createDefoltTriangle()));
		break;
	case figures::Circle:
		m_shapes.push_back(textConverter.ConvertText(createDefoltCircle()));
		break;
	case figures::Rectangle:
		m_shapes.push_back(textConverter.ConvertText(createDefoltRectangle()));
		break;
	case figures::Line:
		m_shapes.push_back(textConverter.ConvertText(createDefoltLine()));
		break;
	}
}

void CConsoleCommand::SetShapes(std::vector<std::shared_ptr<ShapeDecorator>> shapes)
{
	m_shapes = shapes;
}

void CConsoleCommand::DoCommand(ifstream& inputfile, ofstream& outputFile)
{
	sf::RenderWindow window(sf::VideoMode(600, 1800), "Draw Shapes!");
	TextConverter textConverter = TextConverter(window);
	TextReader textReader = TextReader();
	SetShapes(textReader.Read(inputfile, textConverter));
}

void CConsoleCommand::DrawShapes(ofstream& outputFile)
{
	if (!m_shapes.empty())
	{
		bool oneGroup = true;
		sf::RenderWindow window(sf::VideoMode(1000, 600), "Draw Shapes!");
		auto& instance = Application::getInstance(this, window);
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		CApplicationWindow applicationWindow = CApplicationWindow(window, m_shapes, mousePosition, m_history);
		applicationWindow.CreateHistory();
		while (window.isOpen())
		{
			sf::Event event = applicationWindow.getEvent();
			bool checkEntry = true;
			applicationWindow.drawShapes(instance);

			if (event.type == sf::Event::MouseButtonPressed)
				applicationWindow.mousePressEvent(instance);
			if (event.type == sf::Event::MouseButtonReleased)
				applicationWindow.mouseReleasEvent();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G))
				applicationWindow.createGroup();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::U))
				applicationWindow.unGroup();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
				applicationWindow.UnDo();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
				applicationWindow.ReDo();
			window.display();

		}
	}
}

string CConsoleCommand::GetInfo(IStrategy& strategy)
{
	return strategy.GetInfo();
}