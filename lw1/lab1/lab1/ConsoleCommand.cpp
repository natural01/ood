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

vector<string> createDefoltCircle()
{
	vector<string> command;
	command.push_back("Circle");
	command.push_back("200");
	command.push_back("500");
	command.push_back("50");
	command.push_back("000000");
	command.push_back("ffffff");
	return command;
}
vector<string> createDefoltRectangle()
{
	vector<string> command;
	command.push_back("Rectangle");
	command.push_back("200");
	command.push_back("500");
	command.push_back("150");
	command.push_back("100");
	command.push_back("000000");
	command.push_back("ffffff");
	return command;
}
vector<string> createDefoltLine()
{
	vector<string> command;
	command.push_back("LineSegment");
	command.push_back("200");
	command.push_back("500");
	command.push_back("300");
	command.push_back("600");
	command.push_back("000000");
	return command;
}
vector<string> createDefoltTriangle()
{
	vector<string> command;
	command.push_back("Triangle");
	command.push_back("350");
	command.push_back("400");
	command.push_back("300");
	command.push_back("500");
	command.push_back("400");
	command.push_back("500");
	command.push_back("000000");
	command.push_back("ffffff");
	return command;
}

std::vector<std::shared_ptr<ShapeDecorator>> CConsoleCommand::getShapes()
{
	return m_shapes;
}

shared_ptr<ShapeDecorator> CreateLineSegment(vector<string> command, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Line)
	{
		try
		{
			CLineSegment newLine = CLineSegment(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5], newWindow);
			return make_shared<CLineSegment>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5], newWindow);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
}

shared_ptr<ShapeDecorator> CreateTriangle(vector<string> command, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Triangle)
	{
		try
		{
			CTriangle newLine = CTriangle(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8], newWindow);
			return make_shared<CTriangle>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8], newWindow);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
}

shared_ptr<ShapeDecorator> CreateRectangle(vector<string> command, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Rectangle)
	{
		try
		{
			CRectangle newLine = CRectangle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6], newWindow);
			return make_shared<CRectangle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6], newWindow);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
}

shared_ptr<ShapeDecorator> CreateCircle(vector<string> command, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Circle)
	{
		try
		{
			CCircle newLine = CCircle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5], newWindow);
			return make_shared<CCircle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5], newWindow);
		}
		catch (const std::logic_error&)
		{
			throw invalid_argument(Error_Incorrect_Argument);
		}
	}
	else
	{
		throw invalid_argument(Error_Incorrect_Number_Of_Arguments);
	}
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
	switch (newFigure)
	{
	case figures::Triangle:
		m_shapes.push_back(CreateTriangle(createDefoltTriangle(), window));
		break;
	case figures::Circle:
		m_shapes.push_back(CreateCircle(createDefoltCircle(), window));
		break;
	case figures::Rectangle:
		m_shapes.push_back(CreateRectangle(createDefoltRectangle(), window));
		break;
	case figures::Line:
		m_shapes.push_back(CreateLineSegment(createDefoltLine(), window));
		break;
	}
}

vector<string> parsing(string commandLine)
{
	vector<string> arr;
	if (commandLine.empty())
	{
		return arr;
	}
	string delimiter(" ");
	size_t prev = 0;
	size_t next;
	size_t delta = delimiter.length();

while ((next = commandLine.find(delimiter, prev)) != string::npos) {
	arr.push_back(commandLine.substr(prev, next - prev));
	prev = next + delta;
}
arr.push_back(commandLine.substr(prev));
return arr;
}

void CConsoleCommand::DoCommand(ifstream& inputfile, ofstream& outputFile)
{
	string commandLine;
	vector<string> command;
	sf::RenderWindow window(sf::VideoMode(600, 1800), "Draw Shapes!");
	while (getline(inputfile, commandLine))
	{
		try
		{
			command = parsing(commandLine);

			if (command.empty())
			{
				break;
			}

			if (command[0] == Line)
			{
				m_shapes.push_back(CreateLineSegment(command, window));
			}
			else if (command[0] == Triangle)
			{
				m_shapes.push_back(CreateTriangle(command, window));
			}
			else if (command[0] == Rectangle)
			{
				m_shapes.push_back(CreateRectangle(command, window));
			}
			else if (command[0] == Circle)
			{
				m_shapes.push_back(CreateCircle(command, window));
			}
			else
			{
				throw invalid_argument(Error_Incorrect_Shape);
			}
		}
		catch (invalid_argument const& e)
		{
			cout << e.what() << endl;
		}
	}
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