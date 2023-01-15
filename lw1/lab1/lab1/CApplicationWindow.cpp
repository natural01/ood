#include "CApplicationWindow.h"

shared_ptr<COwnership> CreateOwnership(CPoint const& leftTopPoint, double const& width, double const& height, sf::RenderWindow& window)
{
	return make_unique<COwnership>(leftTopPoint, width, height);
}

sf::Event CApplicationWindow::getEvent() const
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
	m_window.clear(sf::Color(255, 255, 255));
	return event;
}

void CApplicationWindow::drawShapes(Application& instance) const
{
	instance.drowPanel();
	for (const auto& shape : m_shapes)
	{
		if (shape->GetSelect())
			instance.drowPanelForChangeFigure();
	}

	for (const auto& shape : m_shapes)
	{
		shape->Draw(m_window);
	}
}

void clearOwnership(vector<shared_ptr<ShapeDecorator>>& shapes)
{
	for (const auto& shape : shapes)
	{
		shape->SetSelect(false);
	}
}

void CApplicationWindow::mousePressEvent(Application& instance)
{
	m_mouseReleasTrigger = true;
	m_createGroupTriger = true;
	if (m_mouseClickTrigger)
	{
		m_mousePosition = sf::Mouse::getPosition(m_window);
		if (instance.buttonPressed(m_mousePosition))
		{
			m_history.addHitory(m_shapes);
			m_mouseClickTrigger = false;
			return;
		}
		for (const auto& shape : m_shapes)
		{
			shape->SetSelect(m_mousePosition, sf::Keyboard::isKeyPressed(sf::Keyboard::LControl));
			if (shape->GetSelect())
			{
				shape->SetSelect(true);
			}
		}
		m_mouseClickTrigger = false;
	}
}

void CApplicationWindow::mouseReleasEvent()
{
	m_mouseClickTrigger = true;
	sf::Vector2i newMousePosition = sf::Mouse::getPosition(m_window);
	CPoint newPosition = CPoint(0, 0);
	if (m_mouseReleasTrigger)
	{
		newPosition = CPoint(m_mousePosition.x - newMousePosition.x, m_mousePosition.y - newMousePosition.y);
		m_mouseReleasTrigger = false;
	}
	for (const auto& shape : m_shapes)
	{
		if (shape->GetSelect() && !(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
		{
			clearOwnership(m_shapes);
			shape->SetPosition(newPosition);
			shape->SetSelect(true);
		}
	}
}

void CApplicationWindow::createGroup()
{
	CShapeComposite group = CShapeComposite();
	vector<int> indexes;
	int count = 0;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetSelect())
		{
			if (!shape->GetGroup().empty())
			{
				for (const auto& subShape : shape->GetGroup())
				{
					group.insertShape(subShape);
				}
				indexes.insert(indexes.begin(), count);
			}
			else
			{
				group.insertShape(shape);
				indexes.insert(indexes.begin(), count);
			}
		}
		count++;
	}
	if (group.GetGroup().size() > 1)
	{
		group.CreateOwnership();
		m_shapes.push_back(make_shared<CShapeComposite>(group));
		for (int i : indexes)
		{
			m_shapes.erase(m_shapes.begin() + i);
		}
	}
	if (m_createGroupTriger)
		m_history.addHitory(m_shapes);
	m_createGroupTriger = false;
}

void CApplicationWindow::unGroup()
{
	vector<int> indexes;
	int count = 0;
	for (const auto& shape : m_shapes)
	{
		if (shape->GetSelect() && !shape->GetGroup().empty())
		{
			indexes.insert(indexes.begin(), count);
			for (const auto& subShape : shape->GetGroup())
				m_shapes.push_back(subShape);
		}
		count++;
	}
	for (int i : indexes)
		m_shapes.erase(m_shapes.begin() + i);
	m_history.addHitory(m_shapes);
}

void CApplicationWindow::UnDo()
{
	if (m_history.Undo())
		m_shapes = m_history.getHistory();
}

void CApplicationWindow::ReDo()
{
	if (m_history.Redo())
		m_shapes = m_history.getHistory();
}

void CApplicationWindow::CreateHistory()
{
	m_history.addHitory(m_shapes);
}
