#include "Visitor.h"
#include "GetInfoRectangleStrategy.h"
#include "GetInfoLineStrategy.h"
#include "GetInfoCircleStrategy.h"
#include "GetInfoTriangleStrategy.h"

void Visitor::WriteToFile(CConsoleCommand* application)
{
	m_file.open("SavedFile.txt");
	for (const auto& shape : application->getShapes())
	{
		if (dynamic_cast<CLineSegment*>(shape.get()))
		{
			const CLineSegment& line = dynamic_cast<CLineSegment&>(*shape.get());
			GetInfoLineStrategy strategy = GetInfoLineStrategy(line);
			m_file << application->GetInfo(strategy);
		}
		if (dynamic_cast<CCircle*>(shape.get()))
		{
			const CCircle& circle = dynamic_cast<CCircle&>(*shape.get());
			GetInfoCircleStrategy strategy = GetInfoCircleStrategy(circle);
			m_file << application->GetInfo(strategy);
		}
		if (dynamic_cast<CTriangle*>(shape.get()))
		{
			const CTriangle& triangle = dynamic_cast<CTriangle&>(*shape.get());
			GetInfoTriangleStrategy strategy = GetInfoTriangleStrategy(triangle);
			m_file << application->GetInfo(strategy);
		}
		if (dynamic_cast<CRectangle*>(shape.get()))
		{
			const CRectangle& rectangle = dynamic_cast<CRectangle&>(*shape.get());
			GetInfoRectangleStrategy strategy = GetInfoRectangleStrategy(rectangle);
			m_file << application->GetInfo(strategy);
		}
		m_file << endl;
	}
	m_file.close();
}

Visitor::Visitor(AddingShape addingShape, ChangingColor changeColor, ChangingBorder changeBorderSize, Save saveFile)
	: m_addFigure(addingShape)
	, m_changeColor(changeColor)
	, m_changingBorder(changeBorderSize)
	, m_saveFile(saveFile)
{
}

void ChangeColor(CConsoleCommand* application, uint32_t const& color)
{
	for (const auto& shape : application->getShapes())
		if (shape->GetSelect())
		{
			if (!shape->GetGroup().empty())
			{
				for (const auto& subShape : shape->GetGroup())
				{
					subShape->SetFillColor(color);
				}
			}
			else
			{
				shape->SetFillColor(color);
			}
		}
}
void ChangeBorderSize(CConsoleCommand* application, int size)
{
	for (const auto& shape : application->getShapes())
		if (shape->GetSelect())
		{
			if (!shape->GetGroup().empty())
			{
				for (const auto& subShape : shape->GetGroup())
				{
					subShape->SetBorder(size);
				}
			}
			else
			{
				shape->SetBorder(size);
			}
		}
}

bool Visitor::GetChange(CConsoleCommand* application, sf::Vector2i point, sf::RenderWindow& window)
{
	if (m_addFigure.GetState(point) == MenuButtonsState::AddLine) { application->addShapes(figures::Line, window); return true; }
	if (m_addFigure.GetState(point) == MenuButtonsState::AddCircle) { application->addShapes(figures::Circle, window); return true; }
	if (m_addFigure.GetState(point) == MenuButtonsState::AddRectangle) { application->addShapes(figures::Rectangle, window); return true; }
	if (m_addFigure.GetState(point) == MenuButtonsState::AddTriangle) { application->addShapes(figures::Triangle, window); return true; }

	if (m_changeColor.GetState(point) == MenuButtonsState::ChangeColorRed) { ChangeColor(application, 16711680); return true; }
	if (m_changeColor.GetState(point) == MenuButtonsState::ChangeColorBlue) { ChangeColor(application, 255); return true; }
	if (m_changeColor.GetState(point) == MenuButtonsState::ChangeColorGreen) { ChangeColor(application, 32768); return true; }
	if (m_changeColor.GetState(point) == MenuButtonsState::ChangeColorWhite) { ChangeColor(application, 16777215); return true; }
	if (m_changeColor.GetState(point) == MenuButtonsState::ChangeColorBlack) { ChangeColor(application, 0); return true; }

	if (m_changingBorder.GetState(point) == MenuButtonsState::ChangeBorderSize1) { ChangeBorderSize(application, 1); return true; }
	if (m_changingBorder.GetState(point) == MenuButtonsState::ChangeBorderSize2) { ChangeBorderSize(application, 2); return true; }
	if (m_changingBorder.GetState(point) == MenuButtonsState::ChangeBorderSize3) { ChangeBorderSize(application, 3); return true; }

	if (m_saveFile.GetState(point) == MenuButtonsState::Save) { WriteToFile(application); }

	return false;
}
