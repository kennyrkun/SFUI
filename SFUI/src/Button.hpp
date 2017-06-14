#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML\Graphics.hpp>

class Button
{
public:
	Button(const sf::Vector2f &size, const std::string buttontext);
	Button();
	~Button();

	sf::Text string;
	bool disabled;
	bool enabled;

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
	sf::RectangleShape shape;
	sf::Font stringFont;
};

#endif /* BUTTON_HPP */
