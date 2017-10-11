#ifndef SFUI_HPP
#define SFUI_HPP

#include <SFML\Graphics.hpp>

#include <string>

namespace SFUI
{

class SFUI final
{
public:
	SFUI(sf::RenderWindow* boundWindow_);
	~SFUI();

private:
	sf::RenderWindow* boundWindow;
};

const std::string VERSION = "0.1.0";

}

#endif