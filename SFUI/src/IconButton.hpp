#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Object.hpp"

#include <SFML\Graphics.hpp>

namespace SFUI
{

class IconButton : public Object
{
public:
	IconButton();
	~IconButton();

	sf::RectangleShape shape;
	sf::RectangleShape icon;

	void setPosition(const sf::Vector2f& pos);
	sf::Vector2f getPosition() { return shape.getPosition(); };

	void setIconTexture(const sf::Texture& texture, const bool resetRect);
	int setIconTexture(const std::string filePath, const bool resetRect);
	void setButtonSize(const sf::Vector2f& newSize);
	void setButtonColor(const sf::Color& color);

	void disable();
	bool disabled;
	void enable();
	bool enabled;

	bool depressed = false;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Font font;
	sf::Texture iconTexture;
};

}

#endif /* BUTTON_HPP */
