#include "IconButton.hpp"

namespace SFUI {

IconButton::IconButton()
{
	shape.setFillColor(sf::Color(240, 240, 240));
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(158, 158, 158));

	this->enabled = true;
}

IconButton::~IconButton()
{
}

void IconButton::setPosition(const sf::Vector2f& newpos)
{
	shape.setPosition(newpos);
}

// sf::Vector2f Button::getPosition()

void IconButton::setIconTexture(const sf::Texture& texture)
{
	icon = texture;
	shape.setTexture(&icon);
}

void IconButton::setIconTexture(const sf::Texture& texture, const bool resetRect)
{
	icon = texture;
	shape.setTexture(&icon, resetRect);
}

void IconButton::setButtonSize(const int newSize)
{
	shape.setSize(sf::Vector2f(newSize, newSize));
}

void IconButton::setButtonColor(const sf::Color& color)
{
	shape.setFillColor(color);
}

void IconButton::disable()
{
	disabled = true;
	enabled = false;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 80));
}

void IconButton::enable()
{
	enabled = true;
	disabled = false;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 255));
}

void IconButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(shape);
}

} // SFUI
