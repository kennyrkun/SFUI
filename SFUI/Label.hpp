#ifndef SFUI_LABEL_HPP
#define SFUI_LABEL_HPP

#include "Widget.hpp"


namespace SFUI
{

// Widget for displaying a simple text
// Passive widget: cannot be focused or trigger event
class Label: public Widget
{
public:
	Label(const sf::String& string = "");

	// Label's text
	void setText(const sf::String& string);
	const sf::String& getText() const;

	// Label's color
	void setColor(const sf::Color& color);
	const sf::Color& getColor() const;

	void setTextSize(size_t size);
	size_t getTextSize() const;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void updateGeometry();

	sf::Text m_text;
};

}

#endif // SFUI_LABEL_HPP
