#ifndef SFUI_SLIDER_HPP
#define SFUI_SLIDER_HPP

#include "Widget.hpp"
#include "Utils/Box.hpp"

namespace SFUI
{

// This widget provides a vertical or horizontal slider.
// The slider is the classic widget for controlling a bounded value.
// The callback is triggered when 'Return' key is pressed.
class Slider : public Widget
{
public:
	enum class Type { Horizontal, Vertical };

	Slider(float length = 200, Type type = Type::Horizontal);

	int getQuantum() const;

	void setQuantum(int slideStep);

	int getValue() const;

	void setValue(int value);


	// callbacks ---------------------------------------------------------------
	void onKeyPressed(sf::Keyboard::Key key);
	void onMousePressed(float x, float y);
	void onMouseMoved(float x, float y);
	void onMouseReleased(float x, float y);
	void onMouseWheelMoved(int delta);
	void onStateChanged(State state);

private:
	void updateHandlePosition();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Type m_type;
	int  m_slideStep;
	int  m_value;
	Box  m_box;
	sf::Vertex m_progression[4];
	Box  m_handle;
};

}

#endif // SFUI_SLIDER_HPP
