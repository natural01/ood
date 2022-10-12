#pragma once
#include "CanvasDecorator.h"

class IGroup
{
public:
	virtual ~IGroup() = default;

	virtual int GetShapeCount() const = 0;
	virtual int GetShapeAtIndex(int index) const = 0;
	virtual void insertShape(CanvasDecorator shape) = 0;
	virtual void RemoutShapeAtIndex(int index) = 0;

};