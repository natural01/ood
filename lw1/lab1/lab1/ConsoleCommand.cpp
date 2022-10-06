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
#include "CanvasDecorator.h"
#include <fstream>

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

unique_ptr<CanvasDecorator> CreateLineSegment(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Line)
	{
		try
		{
			CLineSegment newLine = CLineSegment(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5], newWindow);
			outputFile << Line << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
			return make_unique<CLineSegment>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5], newWindow);
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

unique_ptr<CanvasDecorator> CreateTriangle(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Triangle)
	{
		try
		{
			CTriangle newLine = CTriangle(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8], newWindow);
			outputFile << Triangle << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
			return make_unique<CTriangle>(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8], newWindow);
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

unique_ptr<CanvasDecorator> CreateRectangle(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Rectangle)
	{
		try
		{
			CRectangle newLine = CRectangle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6], newWindow);
			outputFile << Rectangle << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
			return make_unique<CRectangle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6], newWindow);
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

unique_ptr<CanvasDecorator> CreateCircle(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Circle)
	{
		try
		{
			CCircle newLine = CCircle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5], newWindow);
			outputFile << Circle << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
			return make_unique<CCircle>(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5], newWindow);
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

unique_ptr<COwnership> CreateOwnership(CPoint const& leftTopPoint, double const& width, double const& height, sf::RenderWindow& window)
{
	return make_unique<COwnership>(leftTopPoint, width, height, window);
}

bool AreaCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetArea() < secondShape->GetArea();
}

bool PerimeterCompare(unique_ptr<IShape> const& firstShape, unique_ptr<IShape> const& secondShape)
{
	return firstShape->GetPerimeter() < secondShape->GetPerimeter();
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
	sf::RenderWindow window(sf::VideoMode(600, 600), "Draw Shapes!");
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
				m_shapes.push_back(CreateLineSegment(command, outputFile, window));
			}
			else if (command[0] == Triangle)
			{
				m_shapes.push_back(CreateTriangle(command, outputFile, window));
			}
			else if (command[0] == Rectangle)
			{
				m_shapes.push_back(CreateRectangle(command, outputFile, window));
			}
			else if (command[0] == Circle)
			{
				m_shapes.push_back(CreateCircle(command, outputFile, window));
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

void CConsoleCommand::DrawShapes() 
{
	if (!m_shapes.empty())
	{
		sf::RenderWindow window(sf::VideoMode(600, 600), "Draw Shapes!");
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					window.close();
				}
			}
			window.clear(sf::Color(255, 255, 255));

			for (const auto& shape : m_shapes)
			{
				shape->Draw(window);
			}
			for (const auto& ownership : m_ownerships)
			{
				ownership->Draw(window);
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (const auto& shape : m_shapes)
				{
					shape->SetOwnership(sf::Mouse::getPosition(window));
					bool ownership = shape->GetOwnership(sf::Mouse::getPosition(window));
					if (ownership)
					{
						m_ownerships.clear();
						int width = shape->GetOwnershipWidth();
						int height = shape->GetOwnershipHeight();
						CPoint leftTopPoint = shape->GetOwnershipLeftTopPoint();
						m_ownerships.push_back(CreateOwnership(leftTopPoint, width, height, window));
					}
				}
			}
			window.display();

		}
	}
}