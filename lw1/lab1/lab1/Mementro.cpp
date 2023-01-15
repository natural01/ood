#include "Mementro.h"
#include "Rectangle.h"

//std::vector<std::unique_ptr<ShapeDecorator>> createNewVector(std::vector<std::shared_ptr<ShapeDecorator>> shapes)
//{
//	std::vector<std::unique_ptr<ShapeDecorator>> newVector;
//	for (const auto& shape : shapes)
//	{
//		if (typeid(*shape).name() == "CRectangle")
//			newVector.push_back(std::make_unique<CRectangle>(*shape));
//	}
//}

void Mementro::addHitory(std::vector<std::shared_ptr<ShapeDecorator>> shapes)
{
	if (m_index > 100)
	{
		m_history.erase(m_history.begin());
		m_index--;
	}
	if (m_index >= 0)
		m_history.erase(m_history.begin() + m_index+1, m_history.end());
	m_history.push_back(shapes);
	m_index++;
};

bool Mementro::Undo()
{
	if (m_index > 0)
	{
		m_index--;
		return true;
	}
	return false;
}
bool Mementro::Redo()
{
	if (m_index < m_history.size()-1)
	{
		m_index++;
		return true;
	}
	return false;
}
int Mementro::getIndex()
{ 
	return m_index; 
}
std::vector<std::shared_ptr<ShapeDecorator>> Mementro::getHistory()
{ 
	return m_history[m_index]; 
}
bool Mementro::Emty()
{ 
	if (m_history.empty()) 
	{ 
		return true; 
	} 
	return false; 
}