#include "ObjectPropertiesPanel.hpp"

#include <iostream>

WidgetEditor::WidgetEditor(sf::RenderWindow* window)
{
	menu = new SFUI::Menu(*window);

	menu->addButton("object editor panel");
	menu->addLabel("Name:");
	menu->addLabel("Type:");
	menu->addLabel("Size:");
	menu->addLabel("Position:");
	menu->addLabel("Callback:");

	barShape.setSize(sf::Vector2f(100, window->getSize().y));
}

void WidgetEditor::setWidget(SFUI::Widget* widget)
{
	this->widget = widget;

	std::cout << "set widget" << std::endl;
}

SFUI::Widget* WidgetEditor::getWidget() const
{
	return widget;
}

void WidgetEditor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*menu);
}
