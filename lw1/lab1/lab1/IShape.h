#pragma once
#include "Point.h"
#include "ICanvas.h"
#include <string>

class IShape
{
public:
	virtual ~IShape() = default;

	virtual void Draw(ICanvas& canvas) const = 0;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual void SetOutlineColor(uint32_t const& color) = 0;
	virtual uint32_t GetOutlineColor() const = 0;
};