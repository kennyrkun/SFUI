#ifndef SFUI_WIDGET_HPP
#define SFUI_WIDGET_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

namespace SFUI
{

enum class State
{
	Default,
	Hovered,
	Pressed,
	Focused,
	Focused_Hovered,
	Focused_Pressed,
};

class Layout;

// Abstract base class for SFUI widgets
class Widget : public sf::Drawable
{
public:
	Widget();

	// Give an ID to the widget
	void setID(int id);
	// Return ID of widget
	int getID() const;

	// Widget's position
	void setPosition(const sf::Vector2f& pos);
	// Return widget's position
	const sf::Vector2f& getPosition() const;

	sf::Vector2f getAbsolutePosition() const;

	// Get widget's dimensions
	const sf::Vector2f& getSize() const;

	// Check if a point is inside the widget
	bool containsPoint(const sf::Vector2f& point) const;

	// Check if the widget can be selected and trigger events
	bool isSelectable() const;

	// Check if the widget is currently focused
	bool isFocused() const;

	// Event callbacks
	virtual void onStateChanged(State state);
	virtual void onMouseMoved(float x, float y);
	virtual void onMousePressed(float x, float y);
	virtual void onMouseReleased(float x, float y);
	virtual void onMouseWheelMoved(int delta);
	virtual void onKeyPressed(sf::Keyboard::Key key);
	virtual void onKeyReleased(sf::Keyboard::Key key);
	virtual void onTextEntered(sf::Uint32 unicode);

protected:
	void setSize(const sf::Vector2f& size);

	friend class Layout;
	friend class FormLayout;
	friend class HorizontalBoxLayout;
	friend class VerticalBoxLayout;

	void setSelectable(bool selectable);

	// Notify parent that the widget has been triggered by user input
	virtual void triggerCallback(const Widget* triggered = NULL);

	void setState(State state);
	State getState() const;

	// Set the widget's container (parent)
	void setParent(Layout* parent);
	Layout* getParent() { return m_parent; }

	// HACK: hack?
	virtual Layout* toLayout() { return NULL; }

	// Centers text in SFUI::SpriteButton objects
	void centerText(sf::Text& text);

	virtual void recomputeGeometry() {};

	const sf::Transform& getTransform() const;

private:
	// TODO: perhaps put parent, previous and next into
	// Protected so that derived classes can access them
	// Layout this Widget is a part of.
	Layout*      m_parent;
	// Widget before this one in layout. (?)
	Widget*      m_previous;
	// Widget after this one in layout. (?)
	Widget*      m_next;

	State        m_state;
	sf::Vector2f m_position;
	sf::Vector2f m_size;
	int          m_id;
	bool         m_selectable;

	sf::Transform m_transform;
};

}

#endif // SFUI_WIDGET_HPP
