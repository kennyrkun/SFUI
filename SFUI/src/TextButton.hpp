#ifndef TEXT_BUTTON_HPP
#define TEXT_BUTTON_HPP

#include "Object.hpp"
#include "BaseButton.hpp"

#include <SFML\Graphics.hpp>

namespace SFUI 
{
	
class TextButton : public BaseButton
{
public:
	TextButton(const std::string string);
	TextButton();
	~TextButton();

	sf::RectangleShape m_shape;
	sf::Text m_string;

	void setPosition(const sf::Vector2f& position);
	sf::Vector2f getPosition() { return m_shape.getPosition(); };

	void setString(const std::string string);
	void setButtonColor(const sf::Color& color);
	void setColor(const sf::Color& buttonColor, const sf::Color& buttonOutlineColor, const sf::Color& textColor);
	void setStringStyle(const sf::Text::Style& style);

	void setSizeMultiplier(const float multiplier);
	float getSizeMutliplier() { return multiplier; };

	void setScale(sf::Vector2f scale);
	sf::Vector2f getScale();

	void disable();
	bool disabled = false;
	void enable();
	bool enabled = true;

	void select();
	bool selected = false;
	void deselect();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	float multiplier = 1;
	sf::Vector2f scale;
	sf::Font m_font;
};

}

#endif // !TEXT_BUTTON_HPP
