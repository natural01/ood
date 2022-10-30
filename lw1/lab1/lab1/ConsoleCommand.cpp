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

shared_ptr<ShapeDecorator> CreateLineSegment(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Line)
	{
		try
		{
			CLineSegment newLine = CLineSegment(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), command[5], newWindow);
			outputFile << Line << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
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

shared_ptr<ShapeDecorator> CreateTriangle(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Triangle)
	{
		try
		{
			CTriangle newLine = CTriangle(CPoint(stod(command[1]), stod(command[2])), CPoint(stod(command[3]), stod(command[4])), CPoint(stod(command[5]), stod(command[6])), command[7], command[8], newWindow);
			outputFile << Triangle << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
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

shared_ptr<ShapeDecorator> CreateRectangle(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Rectangle)
	{
		try
		{
			CRectangle newLine = CRectangle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), stod(command[4]), command[5], command[6], newWindow);
			outputFile << Rectangle << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
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

shared_ptr<ShapeDecorator> CreateCircle(vector<string> command, ofstream& outputFile, sf::RenderWindow& newWindow)
{
	if (command.size() == The_Number_Of_Elements_In_Circle)
	{
		try
		{
			CCircle newLine = CCircle(CPoint(stod(command[1]), stod(command[2])), stod(command[3]), command[4], command[5], newWindow);
			outputFile << Circle << ": P=" << newLine.GetPerimeter() << "; S=" << newLine.GetArea() << endl;
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

unique_ptr<COwnership> CreateOwnership(CPoint const& leftTopPoint, double const& width, double const& height, sf::RenderWindow& window)
{
	return make_unique<COwnership>(leftTopPoint, width, height, window);
}

shared_ptr<CShapeComposite> CreateGroupe(CShapeComposite shapes)
{
	CPoint firstCornerOfOwnershap = CPoint(0, 0);
	CPoint secondCornerOfOwnershap = CPoint(0, 0);
	for (const auto& shape : shapes.GetGroup())
	{
		CPoint firstCornerOfOwnershap = shape->GetOwnershipLeftTopPoint();
		if (firstCornerOfOwnershap.x() < secondCornerOfOwnershap.x())
		{
			secondCornerOfOwnershap.setX(firstCornerOfOwnershap.x());
		}
		if (firstCornerOfOwnershap.y() < secondCornerOfOwnershap.y())
		{
			secondCornerOfOwnershap.setY(firstCornerOfOwnershap.y());
		}
	}
	return make_shared<CShapeComposite>(shapes);
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
		bool oneClick = true;
		bool oneReleas = false;
		bool oneGroup = true;
		sf::RenderWindow window(sf::VideoMode(600, 600), "Draw Shapes!");
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		while (window.isOpen())
		{
			bool checkEntry = true;
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
				oneReleas = true;
				oneGroup = true;
				if (oneClick)
				{
					mousePosition = sf::Mouse::getPosition(window);
					for (const auto& shape : m_shapes)
					{
						shape->SetOwnership(mousePosition, sf::Keyboard::isKeyPressed(sf::Keyboard::LControl));
						if (shape->GetOwnership())
						{
							checkEntry = true;
							for (const auto& group : m_groups)
							{
								if (group->EntryShape(shape, sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
								{
									if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
									{
										m_ownerships.clear();
									}
									CPoint leftTopPoint = group->GetOwnershipLeftTopPoint();
									int width = group->GetOwnershipWidth();
									int height = group->GetOwnershipHeight();
									m_ownerships.push_back(CreateOwnership(leftTopPoint, width, height, window));
									checkEntry = false;
									break;
								}
							}
							if (checkEntry)
							{
								int width = shape->GetOwnershipWidth();
								int height = shape->GetOwnershipHeight();
								CPoint leftTopPoint = shape->GetOwnershipLeftTopPoint();
								m_ownerships.push_back(CreateOwnership(leftTopPoint, width, height, window));
							}
						}
					}
					oneClick = false;
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				oneClick = true;
				sf::Vector2i newMousePosition = sf::Mouse::getPosition(window);
				CPoint newPosition = CPoint(0, 0);
				if (oneReleas)
				{
					newPosition = CPoint(mousePosition.x - newMousePosition.x, mousePosition.y - newMousePosition.y);
					oneReleas = false;
				}
				for (const auto& shape : m_shapes)
				{
					if (shape->GetOwnership() && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
					{
						for (const auto& group : m_groups)
						{
							if (group->EntryShape(shape, sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
							{
								m_ownerships.clear();
								group->SetPosition(newPosition);
								int width = group->GetOwnershipWidth();
								int height = group->GetOwnershipHeight();
								CPoint leftTopPoint = group->GetOwnershipLeftTopPoint();
								m_ownerships.push_back(CreateOwnership(leftTopPoint, width, height, window));
								checkEntry = false;
								break;
							}
						}
						if (checkEntry)
						{
							m_ownerships.clear();
							shape->SetPosition(newPosition);
							int width = shape->GetOwnershipWidth();
							int height = shape->GetOwnershipHeight();
							CPoint leftTopPoint = shape->GetOwnershipLeftTopPoint();
							m_ownerships.push_back(CreateOwnership(leftTopPoint, width, height, window));
						}
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				if (oneGroup)
				{
					std::vector<std::shared_ptr<ShapeDecorator>> group;
					vector<int> indexesForRemove;
					CShapeComposite newGroup = CShapeComposite(group, CPoint(0, 0));
					int count = 0;
					for (const auto& group : m_groups)
					{
						if (group->GetOwnership())
						{
							indexesForRemove.push_back(count);
							continue;
						}
						count++;
					}
					for (int index : indexesForRemove)
					{
						m_groups.erase(m_groups.begin() + index);
					}
					for (auto& shape : m_shapes)
					{
						if (shape->GetOwnership())
						{
							newGroup.insertShape(shape);
						}
					}
					m_groups.push_back(CreateGroupe(newGroup));
					oneGroup = false;
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::U))
			{
				int count = 0;
				for (auto& group : m_groups)
				{
					if (group->GetOwnership())
					{
						group->ClearShapeList();
						m_groups.erase(m_groups.begin() + count);
						m_ownerships.clear();
					}
					count++;
				}
			}
			window.display();

		}
	}
}