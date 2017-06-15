#include "Button.hpp"

//#include <ENGINE\Logger.hpp>
namespace SFUI {

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
	#ifdef __APPLE__
	if (stringFont.loadFromFile("C://System//Library//Fonts//Arial.ttf")) // I have no idea if this is correct.
	#else
	if (stringFont.loadFromFile("C:\\Windows\\Fonts\\Arial.ttf"))
	#endif
		buttonString.setFont(stringFont);

	buttonString.setCharacterSize(18);

	buttonString.setFillColor(sf::Color::Black);
	shape.setFillColor(sf::Color::White);
//	shape.setOutlineColor(sf::Color::Black);
//	shape.setOutlineThickness(2.0f);
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
	buttonString.setOrigin(sf::Vector2f(buttonString.getLocalBounds().width / 2, buttonString.getLocalBounds().height - 1)); // middle of the text.

	shape.setSize(sf::Vector2f(buttonString.getLocalBounds().width + 14, buttonString.getLocalBounds().height + 6));
	shape.setOrigin(sf::Vector2f(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2));

	if (hasLettersThatHangBelowTheLine(newString))
		buttonString.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y + 4));
	else
		buttonString.setPosition(sf::Vector2f(shape.getPosition().x, shape.getPosition().y + 2));
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

void Button::disable()
{
	enabled = false;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 120));
	buttonString.setFillColor(sf::Color(buttonString.getFillColor().r, buttonString.getFillColor().g, buttonString.getFillColor().b, 120));

	disabled = true;
}

void Button::enable()
{
	disabled = false;

	shape.setFillColor(sf::Color(shape.getFillColor().r, shape.getFillColor().g, shape.getFillColor().b, 255));
	buttonString.setFillColor(sf::Color(buttonString.getFillColor().r, buttonString.getFillColor().g, buttonString.getFillColor().b, 255));

	enabled = true;
}

void Button::draw(sf::RenderWindow *window)
{
	window->draw(shape);
	window->draw(buttonString);
}

// private:

bool Button::hasLettersThatHangBelowTheLine(std::string str)
{
	if (str.find('g') != std::string::npos ||
		str.find('j') != std::string::npos ||
		str.find('p') != std::string::npos ||
		str.find('q') != std::string::npos ||
		str.find('y') != std::string::npos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

}
