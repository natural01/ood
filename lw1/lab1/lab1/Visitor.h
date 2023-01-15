#pragma once
#include "AddingShape.h"
#include "ChangingColor.h"
#include "ChangingBorder.h"
#include "ConsoleCommand.h"
#include <fstream>

class Visitor
{
public:
	Visitor(AddingShape addingShape, ChangingColor changeColor, ChangingBorder changeBorderSize, Save saveFile);
	bool GetChange(CConsoleCommand* m_observer, sf::Vector2i point, sf::RenderWindow& mwindow);
	void WriteToFile(CConsoleCommand* application);

private:
	ofstream m_file;
	AddingShape m_addFigure;
	ChangingColor m_changeColor;
	ChangingBorder m_changingBorder;
	Save m_saveFile;
};