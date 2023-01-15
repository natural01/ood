#include "TextConverter.h"

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

vector<string> parsing(const string& commandLine)
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

TextConverter::TextConverter(sf::RenderWindow& window)
	:m_window(window)
{
}

shared_ptr<ShapeDecorator> TextConverter::ConvertText(const string& commandLine)
{
	try
	{
		vector<string> command = parsing(commandLine);

		if (command.empty())
		{
			return shared_ptr<ShapeDecorator>();
		}

		if (command[0] == Line)
		{
			return CreateLineSegment(command, m_window);
		}
		else if (command[0] == Triangle)
		{
			return CreateTriangle(command, m_window);
		}
		else if (command[0] == Rectangle)
		{
			return CreateRectangle(command, m_window);
		}
		else if (command[0] == Circle)
		{
			return CreateCircle(command, m_window);
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
