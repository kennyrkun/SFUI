#include "Button.hpp"

//#include <ENGINE\Logger.hpp>

Button::Button(const sf::Vector2f &size, const std::string string)
{
	if (stringFont.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		buttonString.setFont(stringFont);

	buttonString.setString(string);
	buttonString.setFillColor(sf::Color::Black);
	shape.setFillColor(sf::Color::White);

	shape.setSize(sf::Vector2f(size.x, size.y));
	buttonString.setCharacterSize(static_cast<int>(size.y) - 6);

	setString(string);
}

Button::Button()
{
	if (stringFont.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		buttonString.setFont(stringFont);

	buttonString.setFillColor(sf::Color::Black);
	shape.setFillColor(sf::Color::White);
}

Button::~Button()
{
	//	logger::SILENT("Deconstructing button class");
}

void Button::setPosition(const sf::Vector2f newpos)
{
	shape.setPosition(newpos);
	buttonString.setPosition(shape.getPosition());
}

void Button::setString(const std::string newString)
{
	buttonString.setString(newString);

	if (newString.find('g') != std::string::npos ||
		newString.find('j') != std::string::npos ||
		newString.find('p') != std::string::npos ||
		newString.find('q') != std::string::npos ||
		newString.find('y') != std::string::npos)
	{
		shape.setSize(sf::Vector2f(buttonString.getLocalBounds().width + 10, buttonString.getLocalBounds().height + 6));
		buttonString.setOrigin(buttonString.getLocalBounds().width / 2, buttonString.getLocalBounds().height - 4); // middle of the text.
	}
	else
	{
		shape.setSize(sf::Vector2f(buttonString.getLocalBounds().width + 10, buttonString.getLocalBounds().height + 10));
		buttonString.setOrigin(buttonString.getLocalBounds().width / 2, buttonString.getLocalBounds().height - 1); // middle of the text.
	}

	shape.setOrigin(sf::Vector2f(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2));
	buttonString.setPosition(shape.getPosition());
}

void Button::setButtonColor(const sf::Color color)
{
	shape.setFillColor(color);
}

void Button::setStringColor(const sf::Color color)
{
	buttonString.setFillColor(color);
}

void Button::setStringStyle(const sf::Text::Style style)
{
	buttonString.setStyle(style);
}

void Button::setScale(const sf::Vector2f scale)
{
	shape.setScale(scale);
	buttonString.setScale(scale);
}

void Button::setSize(const sf::Vector2f size)
{
	shape.setSize(sf::Vector2f(size.x, size.y));
	buttonString.setCharacterSize(static_cast<int>(size.y) - 6);
}

void Button::disable()
{
	disabled = true;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 80));
	buttonString.setFillColor(sf::Color(buttonString.getFillColor().r, buttonString.getFillColor().g, buttonString.getFillColor().b, 80));
}

void Button::enable()
{
	enabled = true;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 255));
	buttonString.setFillColor(sf::Color(buttonString.getFillColor().r, buttonString.getFillColor().g, buttonString.getFillColor().b, 255));
}

void Button::draw(sf::RenderWindow *window)
{
	window->draw(shape);
	window->draw(buttonString);
}