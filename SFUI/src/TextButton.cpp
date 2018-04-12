#include "TextButton.hpp"

namespace SFUI {

TextButton::TextButton(const std::string string)
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

TextButton::TextButton()
{
	if (m_font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		m_string.setFont(m_font);

	m_string.setFillColor(sf::Color::Black);
	m_shape.setFillColor(sf::Color(240, 240, 240));
	m_shape.setOutlineThickness(1);
	m_shape.setOutlineColor(sf::Color(158, 158, 158));

	m_string.setCharacterSize(14);

	enabled = true;
}

TextButton::~TextButton()
{
	//	logger::SILENT("Deconstructing button class");
}

void TextButton::setPosition(const sf::Vector2f& position)
{
	m_shape.setPosition(position);
	m_string.setPosition(static_cast<int>(m_shape.getPosition().x - (m_string.getLocalBounds().width / 2.0f) - 2.0f), static_cast<int>(m_shape.getPosition().y - (m_shape.getLocalBounds().height / 2.0f)) + 1.0f);
}

// sf::Vector2f Button::getPosition()

void TextButton::setString(const std::string string)
{
	m_string.setString(string);

	m_shape.setSize(sf::Vector2f((m_string.getLocalBounds().width + 10) * multiplier, 21 * multiplier));
	m_shape.setOrigin(sf::Vector2f(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2));

	m_string.setCharacterSize(14 * multiplier);
//	m_string.setOrigin(sf::Vector2f(m_string.getLocalBounds().width / 2, m_string.getLocalBounds().height / 2));

	setPosition(m_shape.getPosition());
}

void TextButton::setButtonColor(const sf::Color& color)
{
	m_shape.setFillColor(color);
}

void TextButton::setColor(const sf::Color& buttonColor, const sf::Color& buttonOutlineColor, const sf::Color& textColor)
{
	m_string.setFillColor(textColor);
	m_shape.setOutlineColor(buttonOutlineColor);
	m_shape.setFillColor(buttonColor);
}

void TextButton::setStringStyle(const sf::Text::Style& style)
{
	m_string.setStyle(style);
}

void TextButton::setSizeMultiplier(const float multiplier_)
{
	multiplier = multiplier_;

	setString(m_string.getString());
}

void TextButton::setScale(sf::Vector2f scale_)
{
	scale = scale_;

	m_shape.setScale(scale_);
	m_string.setScale(scale_);
}

sf::Vector2f TextButton::getScale()
{
	return scale;
}

// float Button::getSizeMultiplier()

void TextButton::disable()
{
	disabled = true;
	enabled = false;

	m_shape.setFillColor(sf::Color(m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 80));
	m_string.setFillColor(sf::Color(m_string.getFillColor().r, m_string.getFillColor().g, m_string.getFillColor().b, 80));
}

void TextButton::enable()
{
	enabled = true;
	disabled = false;

	m_shape.setFillColor(sf::Color(m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 255));
	m_string.setFillColor(sf::Color(m_string.getFillColor().r, m_string.getFillColor().g, m_string.getFillColor().b, 255));
}

void TextButton::select()
{
	m_shape.setOutlineColor(sf::Color(0, 170, 232));
	m_shape.setOutlineThickness(2);
	selected = true;
}

void TextButton::deselect()
{
	m_shape.setOutlineColor(sf::Color(158, 158, 158));
	m_shape.setOutlineThickness(1);
	selected = false;
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_shape);
	target.draw(m_string);
}

} // SFUI
