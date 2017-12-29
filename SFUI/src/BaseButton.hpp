#ifndef BASE_BUTTON_HPP
#define BASE_BUTTON_HPP

#include "Object.hpp"

#include <SFML\Graphics.hpp>

namespace SFUI
{

namespace bcol
{
	const sf::Color background = sf::Color(240, 240, 240);
	const sf::Color outline = sf::Color(158, 158, 158);
	const sf::Color string = sf::Color::Black;
	const sf::Color selectOutline = sf::Color(0, 170, 232);
	const sf::Color backgroundHover = sf::Color(226, 245, 255);
}
	
class BaseButton : public Object
{
public:
	BaseButton();
	~BaseButton();

//	sf::RectangleShape shape;
//	sf::Text text;

//	bool depressed = false;
//	bool selected = false;
//	bool enabled = true, disabled = false;

//	int outlineThickness;

private:
//	sf::Font font;
};

} // SFUI namespace

#endif // !BASE_BUTTON_HPP
