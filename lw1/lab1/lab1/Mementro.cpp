#include "ShapeDecorator.h"
#include "Ownership.h"
#include "CShapeComposite.h"

class Mementro
{
public:

	Mementro() = default;

	void addHitory(std::vector<std::shared_ptr<ShapeDecorator>> shape)
	{
		if (m_index > 100)
		{
			m_history.erase(m_history.begin());
			m_index--;
		}
		if (m_index >= 0)
			m_history.erase(m_history.begin() + m_index+1, m_history.end());
		m_history.push_back(shape);
		m_index++;
	};

	bool Undo() 
	{
		if (m_index > 0)
		{
			m_index--;
			return true;
		}
		return false;
	};
	bool Redo()
	{
		if (m_index < m_history.size()-1)
		{
			m_index++;
			return true;
		}
		return false;
	}
	int getIndex() { return m_index; };
	std::vector<std::shared_ptr<ShapeDecorator>> getHistory() { return m_history[m_index]; }
	bool Emty() { if (m_history.empty()) { return true; } return false; }
private:
	int m_index = -1;
	std::vector<std::vector<std::shared_ptr<ShapeDecorator>>> m_history;
};