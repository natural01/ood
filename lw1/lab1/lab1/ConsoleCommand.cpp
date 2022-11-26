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
#include "States.h"
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

void CConsoleCommand::updateFromMenu(addFigure state, sf::RenderWindow& window)
{
	CPoint center = CPoint(300, 700);
	if (state == addFigure::addCircle)
	{
		m_shapes.push_back(make_shared<CCircle>(center, 50, "000", "fff", window));
	}
	if (state == addFigure::addLine)
	{
		CPoint finish = CPoint(400, 700);
		m_shapes.push_back(make_shared<CLineSegment>(center, finish, "000", window));
	}
	if (state == addFigure::addRectangle)
	{
		m_shapes.push_back(make_shared<CRectangle>(center, 50, 50, "000", "fff", window));
	}
	if (state == addFigure::addTriangle)
	{
		CPoint vertex1 = CPoint(400, 700);
		CPoint vertex2 = CPoint(350, 600);
		m_shapes.push_back(make_shared<CTriangle>(center, vertex1, vertex2, "000", "fff", window));
	}
}

void CConsoleCommand::updateFromMenu(ColorState state)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->GetOwnership())
		{
			switch (state)
			{
			case ColorState::ChangeColorForBlack:
				shape->SetFillColor(0);
				break;
			case ColorState::ChangeColorForWhite:
				shape->SetFillColor(16777215);
				break;
			case ColorState::ChangeColorForRed:
				shape->SetFillColor(16711680);
				break;
			case ColorState::ChangeColorForBlue:
				shape->SetFillColor(255);
				break;
			case ColorState::ChangeColorForGreen:
				shape->SetFillColor(32768);
				break;
			}
		}
	}
}

void CConsoleCommand::updateFromMenu(BorderSizeState state)
{
	for (const auto& shape : m_shapes)
	{
		if (shape->GetOwnership())
		{
			switch (state)
			{
			case BorderSizeState::ChangeSizeFor1:
				shape->SetBorder(1);
				break;
			case BorderSizeState::ChangeSizeFor2:
				shape->SetBorder(2);
				break;
			case BorderSizeState::ChangeSizeFor3:
				shape->SetBorder(3);
				break;
			}
		}
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

void CConsoleCommand::DrawShapes(ofstream& outputFile)
{
	auto& instance = Application::getInstance();
	if (!m_shapes.empty())
	{
		bool oneClick = true;
		bool oneReleas = false;
		bool oneGroup = true;
		sf::RenderWindow window(sf::VideoMode(1000, 600), "Draw Shapes!");
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
			bool ownership = false;

			instance.drowPanel(window);
			if (!(m_ownerships.empty()))
				instance.drowPanelForChangeFigure(window);

			for (const auto& shape : m_shapes)
			{
				if (shape->GetOwnership())
					ownership = true;
				shape->Draw(window);
			}
			if (!ownership)
				m_ownerships.clear();
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
					if (instance.buttonPressed(mousePosition) && (instance.getAddFigureState() != addFigure::None || instance.getColorState() != ColorState::None || instance.getBorderState() != BorderSizeState::None))
					{
						switch (instance.getAddFigureState())
						{
						case addFigure::addCircle:
							m_shapes.push_back(CreateCircle(createDefoltCircle(), outputFile, window));
							break;
						case addFigure::addLine:
							m_shapes.push_back(CreateLineSegment(createDefoltLine(), outputFile, window));
							break;
						case addFigure::addRectangle:
							m_shapes.push_back(CreateRectangle(createDefoltRectangle(), outputFile, window));
							break;
						case addFigure::addTriangle:
							m_shapes.push_back(CreateTriangle(createDefoltTriangle(), outputFile, window));
							break;
						}
						switch (instance.getBorderState())
						{
						case BorderSizeState::ChangeSizeFor1:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetBorder(1);
							break;
						case BorderSizeState::ChangeSizeFor2:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetBorder(2);
							break;
						case BorderSizeState::ChangeSizeFor3:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetBorder(3);
							break;
						}
						switch (instance.getColorState())
						{
						case ColorState::ChangeColorForBlack:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetFillColor(0);
							break;
						case ColorState::ChangeColorForBlue:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetFillColor(255);
							break;
						case ColorState::ChangeColorForGreen:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetFillColor(32768);
							break;
						case ColorState::ChangeColorForRed:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetFillColor(16711680);
							break;
						case ColorState::ChangeColorForWhite:
							for (const auto& shape : m_shapes)
								if (shape->GetOwnership())
									shape->SetFillColor(16777215);
							break;
						}

						instance.nullState();
						continue;
					}
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