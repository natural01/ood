#pragma once
#include "ShapeDecorator.h"

class IShapeComposite : public ShapeDecorator
{
public:
	virtual ~IShapeComposite() = default;

	virtual void insertShape(std::shared_ptr<ShapeDecorator> shape) = 0;
	virtual void RemoutShapeAtIndex(int index) = 0;
	virtual void ClearShapeList() = 0;
	virtual bool EntryShape(std::shared_ptr<ShapeDecorator> shape, bool select) = 0;
	virtual void SetPosition(CPoint newPosition) = 0;

};