#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML\Graphics.hpp>

class Button
{
public:
	sf::RectangleShape m_shape;
	sf::Text m_string;

	bool disabled;
	bool enabled;

	Button(const sf::Vector2f &size, const std::string string);
	Button();
	~Button();

	void setPosition(const sf::Vector2f pos);
	void setString(const std::string string);
	void setButtonColor(const sf::Color color);
	void setStringColor(const sf::Color color);
	void setStringStyle(const sf::Text::Style style);
	void setScale(const sf::Vector2f scale);
	void setSize(const sf::Vector2f size);
	void disable();
	void enable();

	void draw(sf::RenderWindow *window);

private:
	sf::Font m_font;
};

#endif /* BUTTON_HPP */
