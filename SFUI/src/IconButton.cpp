#include "IconButton.hpp"

namespace SFUI {

IconButton::IconButton()
{
//	shape.setFillColor(sf::Color(240, 240, 240));
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineThickness(3);
	shape.setOutlineColor(sf::Color(158, 158, 158));

	this->enabled = true;
}

IconButton::~IconButton()
{
}

void IconButton::setPosition(const sf::Vector2f& newpos)
{
	icon.setPosition(newpos);
	shape.setPosition(newpos);
}

// sf::Vector2f Button::getPosition()

void IconButton::setIconTexture(const sf::Texture& texture)
{
	iconTexture = texture;
	icon.setTexture(&iconTexture, false);
}

void IconButton::setIconTexture(const sf::Texture& texture, const bool resetRect)
{
	iconTexture = texture;
	icon.setTexture(&iconTexture, resetRect);
	shape.setSize(icon.getSize());
}

void IconButton::setIconTexture(const std::string filePath)
{
	iconTexture.loadFromFile(filePath);
	icon.setTexture(&iconTexture, false);
}

void IconButton::setIconTexture(const std::string filePath, const bool resetRect)
{
	iconTexture.loadFromFile(filePath);
	icon.setTexture(&iconTexture, resetRect);
	shape.setSize(icon.getSize());
}

void IconButton::setButtonSize(const sf::Vector2f& newSize)
{
	shape.setSize(newSize);
	icon.setSize(newSize);
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
	target.draw(icon);
}

} // SFUI
