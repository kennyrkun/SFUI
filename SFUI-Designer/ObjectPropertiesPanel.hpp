#ifndef OBJECT_PROPERTIES_PANEL_HPP
#define OBJECT_PROPERTIES_PANEL_HPP

#include <SFML/Graphics.hpp>
#include <SFUI.hpp>

#include <vector>

class WidgetEditor : public sf::Drawable
{
public:
	WidgetEditor(sf::RenderWindow* window);

	void setWidget(SFUI::Widget* widget);
	SFUI::Widget* getWidget() const;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	SFUI::Menu* menu;
	SFUI::Widget* widget;

	sf::RectangleShape barShape;
};

#endif // !OBJECT_PROPERTIES_PANEL_HPP
