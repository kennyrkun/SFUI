#include "Button.hpp"

//#include <ENGINE\Logger.hpp>

Button::Button(const sf::Vector2f &size, const std::string string)
{
	if (m_font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		m_string.setFont(m_font);

	m_string.setString(string);
	m_string.setFillColor(sf::Color::Black);
	m_shape.setFillColor(sf::Color::White);

	m_shape.setSize(sf::Vector2f(size.x, size.y));
	m_string.setCharacterSize(static_cast<int>(size.y) - 6);

	setString(string);

//	logger::SILENT("DEBUG", "New button created.");
}

Button::Button()
{
	if (m_font.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		m_string.setFont(m_font);

	m_string.setFillColor(sf::Color::Black);
	m_shape.setFillColor(sf::Color::White);

//	logger::SILENT("debug", "New button created.");
}

Button::~Button()
{
	//	logger::SILENT("Deconstructing button class");
}

void Button::setPosition(const sf::Vector2f newpos)
{
	m_shape.setPosition(newpos);
	m_string.setPosition(m_shape.getPosition());
}

void Button::setString(const std::string string)
{
	m_string.setString(string);

	if (string.find('g') != std::string::npos ||
		string.find('j') != std::string::npos ||
		string.find('p') != std::string::npos ||
		string.find('q') != std::string::npos ||
		string.find('y') != std::string::npos)
	{
		m_shape.setSize(sf::Vector2f(m_string.getLocalBounds().width + 10, m_string.getLocalBounds().height + 6));
		m_string.setOrigin(m_string.getLocalBounds().width / 2, m_string.getLocalBounds().height - 4); // middle of the text.
	}
	else
	{
		m_shape.setSize(sf::Vector2f(m_string.getLocalBounds().width + 10, m_string.getLocalBounds().height + 10));
		m_string.setOrigin(m_string.getLocalBounds().width / 2, m_string.getLocalBounds().height - 1); // middle of the text.
	}

	m_shape.setOrigin(sf::Vector2f(m_shape.getLocalBounds().width / 2, m_shape.getLocalBounds().height / 2));
	m_string.setPosition(m_shape.getPosition());
}

void Button::setButtonColor(const sf::Color color)
{
	m_shape.setFillColor(color);
}

void Button::setStringColor(const sf::Color color)
{
	m_string.setFillColor(color);
}

void Button::setStringStyle(const sf::Text::Style style)
{
	m_string.setStyle(style);
}

void Button::setScale(const sf::Vector2f scale)
{
	m_shape.setScale(scale);
	m_string.setScale(scale);
}

void Button::setSize(const sf::Vector2f size)
{
	m_shape.setSize(sf::Vector2f(size.x, size.y));
	m_string.setCharacterSize(static_cast<int>(size.y) - 6);
}

void Button::disable()
{
	disabled = true;

	m_shape.setFillColor(sf::Color(m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 80));
	m_string.setFillColor(sf::Color(m_string.getFillColor().r, m_string.getFillColor().g, m_string.getFillColor().b, 80));
}

void Button::enable()
{
	enabled = true;

	m_shape.setFillColor(sf::Color(m_shape.getFillColor().r, m_shape.getFillColor().g, m_shape.getFillColor().b, 255));
	m_string.setFillColor(sf::Color(m_string.getFillColor().r, m_string.getFillColor().g, m_string.getFillColor().b, 255));
}

void Button::draw(sf::RenderWindow *window)
{
	window->draw(m_shape);
	window->draw(m_string);
}