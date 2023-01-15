#pragma once
#include <vector>
#include <string>
#include "ShapeDecorator.h"
#include "Circle.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

class TextConverter
{
public:
	TextConverter(sf::RenderWindow& window);
	shared_ptr<ShapeDecorator> ConvertText(const string& commandLine);

private:
	sf::RenderWindow& m_window;
};