#ifndef SFUI_MENU_HPP
#define SFUI_MENU_HPP

#include "VerticalBoxLayout.hpp"

#include <SFML/Graphics.hpp>

namespace SFUI
{

// Vertical Stacked Layout
// basically a container for widgets?
class Menu : public SFUI::VerticalBoxLayout
{
public:
	Menu(sf::RenderTarget& window);

	// Handle event and send it to widgets
	// triggered widget ID, or -1 if none
	int onEvent(const sf::Event& event);

	void triggerCallback(const Widget* widget) override;

private:
	// Get mouse cursor relative position
	// x: absolute x position from the event
	// y: absolute y position from the event
	// relative: if not NULL, compute mouse position relative to this widget
	sf::Vector2f convertMousePosition(int x, int y) const;

	sf::RenderTarget& m_window;
	const Widget*     m_triggered;
};

}

#endif // SFUI_MENU_HPP
