#ifndef SFUI_HPP
#define SFUI_HPP

#include <SFML\Graphics.hpp>

// version 0.1
namespace SFUI
{

class SFUI
{
public:
	SFUI(sf::RenderWindow* boundWindow_);
	~SFUI();

private:
	sf::RenderWindow* boundWindow;
};

}

#endif