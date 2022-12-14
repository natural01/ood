#pragma once
#include "Point.h"
#include <string>
#include <SFML/Graphics.hpp>

class IShape
{
public:
	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual void SetOutlineColor(uint32_t const& color) = 0;
	virtual uint32_t GetOutlineColor() const = 0;
};