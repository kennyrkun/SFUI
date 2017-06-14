#include "Button.hpp"

//#include <ENGINE\Logger.hpp>

Button::Button(const sf::Vector2f &size, const std::string buttontext)
{
	if (stringFont.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		string.setFont(stringFont);

	string.setString(buttontext);
	string.setFillColor(sf::Color::Black);
	shape.setFillColor(sf::Color::White);

	shape.setSize(sf::Vector2f(size.x, size.y));
	string.setCharacterSize(static_cast<int>(size.y) - 6);

	setString(buttontext);

//	logger::SILENT("DEBUG", "New button created.");
}

Button::Button()
{
	if (stringFont.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
		string.setFont(stringFont);

	string.setFillColor(sf::Color::Black);
	shape.setFillColor(sf::Color::White);

//	logger::SILENT("debug", "New button created.");
}

Button::~Button()
{
	//	logger::SILENT("Deconstructing button class");
}

void Button::setPosition(const sf::Vector2f newpos)
{
	shape.setPosition(newpos);
	string.setPosition(shape.getPosition());
}

void Button::setString(const std::string newString)
{
	if (newString.find('g') != std::string::npos ||
		newString.find('j') != std::string::npos ||
		newString.find('p') != std::string::npos ||
		newString.find('q') != std::string::npos ||
		newString.find('y') != std::string::npos)
	{
		shape.setSize(sf::Vector2f(string.getLocalBounds().width + 10, string.getLocalBounds().height + 6));
		string.setOrigin(string.getLocalBounds().width / 2, string.getLocalBounds().height - 4); // middle of the text.
	}
	else
	{
		shape.setSize(sf::Vector2f(string.getLocalBounds().width + 10, string.getLocalBounds().height + 10));
		string.setOrigin(string.getLocalBounds().width / 2, string.getLocalBounds().height - 1); // middle of the text.
	}

	string.setString(newString);
	shape.setOrigin(sf::Vector2f(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2));
	string.setPosition(shape.getPosition());
}

void Button::setButtonColor(const sf::Color color)
{
	shape.setFillColor(color);
}

void Button::setStringColor(const sf::Color color)
{
	string.setFillColor(color);
}

void Button::setStringStyle(const sf::Text::Style style)
{
	string.setStyle(style);
}

void Button::setScale(const sf::Vector2f scale)
{
	shape.setScale(scale);
	string.setScale(scale);
}

void Button::setSize(const sf::Vector2f size)
{
	shape.setSize(sf::Vector2f(size.x, size.y));
	string.setCharacterSize(static_cast<int>(size.y) - 6);
}

void Button::disable()
{
	disabled = true;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 80));
	string.setFillColor(sf::Color(string.getFillColor().r, string.getFillColor().g, string.getFillColor().b, 80));
}

void Button::enable()
{
	enabled = true;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 255));
	string.setFillColor(sf::Color(string.getFillColor().r, string.getFillColor().g, string.getFillColor().b, 255));
}

void Button::draw(sf::RenderWindow *window)
{
	window->draw(shape);
	window->draw(string);
}