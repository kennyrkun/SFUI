#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Object.hpp"

#include <SFML\Graphics.hpp>

namespace SFUI
{

class IconButton : public Object
{
public:
	IconButton(const std::string string);
	IconButton();
	~IconButton();

	sf::RectangleShape m_shape;
	sf::Text m_string;

	void setPosition(const sf::Vector2f& pos);
	sf::Vector2f getPosition() { return m_shape.getPosition(); };

	void setString(const std::string string);
	void setButtonColor(const sf::Color& color);
	void setStringColor(const sf::Color& color);
	void setStringStyle(const sf::Text::Style& style);

	void setSizeMultiplier(const float multiplier_);
	float getSizeMutliplier() { return multiplier; };

	void disable();
	bool disabled;
	void enable();
	bool enabled;

	bool depressed = false;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	float multiplier = 1;
	sf::Font m_font;
};

}

#endif /* BUTTON_HPP */
