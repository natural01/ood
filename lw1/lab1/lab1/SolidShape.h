#pragma once
#include "ISolidShape.h"
#include "Shape.h"

class CSolidShape : public ISolidShape, public CShape
{
public:
	CSolidShape() = default;
	virtual ~CSolidShape() = default;

	void SetFillColor(uint32_t const& color) override;
	uint32_t GetFillColor() const;

	void SetOutlineColor(uint32_t const& color) override;
	uint32_t GetOutlineColor() const;

	virtual void SetBorder(int borderSize) = 0;

private:
	uint32_t m_fillColor = 000000;
	int m_borderSize = 1;
};