#ifndef SFUI_LAYOUT_HPP
#define SFUI_LAYOUT_HPP

#include "../Widget.hpp"


namespace SFUI
{

class Widget;
class Label;
class Button;
class FormLayout;
class HorizontalBoxLayout;
class VerticalBoxLayout;

// Base class for layouts.
// Layouts are special widgets which act as containers.
// See FormLayout, HorizontalBoxLayout and VerticalBoxLayout
// ---- This function is NOT intended to be used outside the API.
// TODO: add outlines to each layout, so they can visually be debugged
class Layout : public Widget
{
public:
	Layout();
	~Layout();

	 // Add a new widget in the container
	 // The container will take care of widget deallocation
	 // returns the added widget
	virtual Widget* add(Widget* widget, int callbackID = -1) = 0;

	Button*				 addButton(const sf::String& string, int callbackID = -1);
	Label*				 addLabel(const sf::String& string);
	FormLayout*			 addFormLayout();
	HorizontalBoxLayout* addHorizontalBoxLayout();
	VerticalBoxLayout*	 addVerticalBoxLayout();

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// Callbacks
	void onStateChanged(State state) override;
	void onMouseMoved(float x, float y) override;
	void onMousePressed(float x, float y) override;
	void onMouseReleased(float x, float y) override;
	void onMouseWheelMoved(int delta) override;
	void onKeyPressed(sf::Keyboard::Key key) override;
	void onKeyReleased(sf::Keyboard::Key key) override;
	void onTextEntered(sf::Uint32 unicode) override;

	Layout* toLayout() override { return this; } // HACK: hack?

	bool focusNextWidget();
	bool focusPreviousWidget();

	// Append a new widget in the container
	Widget* push(Widget* widget);

	Widget* getFirstWidget();

private:
	// Give the focus to a widget, if applicable
	// state: new state of the widget if it took focus
	// true if widget took the focus, otherwise false
	bool focusWidget(Widget* widget, State state = State::Focused);

	Widget*   m_first;
	Widget*   m_last;
	Widget*   m_hover;
	Widget*   m_focus;
};

}

#endif // !SFUI_LAYOUT_HPP
