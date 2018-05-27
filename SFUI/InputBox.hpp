#ifndef SFUI_TEXTBOX_HPP
#define SFUI_TEXTBOX_HPP

#include "Widget.hpp"
#include "Utils/Box.hpp"

// TODO: support lots of text
// TODO: setRows(int rowCount);
//		 amount of rows in the editor

namespace SFUI
{

 // The InputBox widget is a one-line text editor.
 // It allows the user to enter and edit a single line of plain text.
class InputBox : public Widget
{
public:
	InputBox(float width = 200.f);

	void setDefaultText(const sf::String& string);

	// whether or not the InputBox is empty
	bool isEmpty();

	const sf::String& getText() const;

	// set curser position
	void setCursor(size_t index);

	size_t getCursor() const;

	void setBlinkPeriod(float period);
	float getBlinkPeriod();

protected:
	// Callbacks
	void onKeyPressed(sf::Keyboard::Key key);
	void onMousePressed(float x, float y);
	void onTextEntered(sf::Uint32 unicode);
	void onStateChanged(State state);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	// TODO: oldtext
	// set when deselecting textbox
	// if user presses escape while in text box reset to this text
	std::string m_oldText;

	sf::Text    m_text;
	Box         m_box;
	mutable sf::RectangleShape m_cursor;
	mutable sf::Clock  m_cursor_timer;
	size_t             m_cursor_pos;
	int                m_max_length;
	float			   m_blink_period;
};

}

#endif // SFUI_TEXTBOX_HPP
