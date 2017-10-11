#include "IconButton.hpp"

namespace SFUI {

IconButton::IconButton(const std::string string)
{
	if (m_font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		m_string.setFont(m_font);

	m_shape.setFillColor(sf::Color(240, 240, 240));
	m_shape.setOutlineThickness(1);
	m_shape.setOutlineColor(sf::Color(158, 158, 158));

	m_string.setCharacterSize(14);
	m_string.setFillColor(sf::Color::Black);
	setString(string);

	this->enabled = true;
}

IconButton::IconButton()
{
	if (m_font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		m_string.setFont(m_font);

	m_string.setFillColor(sf::Color::Black);
	m_shape.setFillColor(sf::Color(240, 240, 240));
	m_shape.setOutlineThickness(1);
	m_shape.setOutlineColor(sf::Color(158, 158, 158));

	m_string.setCharacterSize(14);

	this->enabled = true;
}

IconButton::~IconButton()
{
	//	logger::SILENT("Deconstructing button class");
}

void IconButton::setPosition(const sf::Vector2f& newpos)
{
	m_shape.setPosition(newpos);
	m_string.setPosition(static_cast<int>(m_shape.getPosition().x - (m_string.getLocalBounds().width / 2) - 2), static_cast<int>(m_shape.getPosition().y - (m_shape.getLocalBounds().height / 2)) + 1);
}

// sf::Vector2f Button::getPosition()

void IconButton::setString(const std::string string)
{
	m_string.setString(string);

	m_shape.setSize(sf::Vector2f((m_string.getLocalBounds().width + 10) * multiplier, 21 * multiplier));
	m_shape.setOrigin(sf::Vector2f(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2));

	m_string.setCharacterSize(14 * multiplier);
	//	m_string.setOrigin(sf::Vector2f(m_string.getLocalBounds().width / 2, m_string.getLocalBounds().height / 2));

	setPosition(m_shape.getPosition());
}

void IconButton::setButtonColor(const sf::Color& color)
{
	m_shape.setFillColor(color);
}

void IconButton::setStringColor(const sf::Color& color)
{
	m_string.setFillColor(color);
}

void IconButton::setStringStyle(const sf::Text::Style& style)
{
	m_string.setStyle(style);
}

void IconButton::setSizeMultiplier(const float multiplier_)
{
	multiplier = multiplier_;

	setString(m_string.getString());
}

// float Button::getSizeMultiplier()

void IconButton::disable()
{
	disabled = true;
	enabled = false;

	m_shape.setFillColor(sf::Color(m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 80));
	m_string.setFillColor(sf::Color(m_string.getFillColor().r, m_string.getFillColor().g, m_string.getFillColor().b, 80));
}

void IconButton::enable()
{
	enabled = true;
	disabled = false;

	m_shape.setFillColor(sf::Color(m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 255));
	m_string.setFillColor(sf::Color(m_string.getFillColor().r, m_string.getFillColor().g, m_string.getFillColor().b, 255));
}

void IconButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_shape);
	target.draw(m_string);
}

} // SFUI
