#include "SFUI.hpp"

namespace SFUI
{

SFUI::SFUI(sf::RenderWindow* boundWindow_)
{
	boundWindow = boundWindow_;
}

SFUI::~SFUI()
{
	delete boundWindow;
}

void SFUI::bindWindow(sf::RenderWindow * window)
{
	delete boundWindow;
	boundWindow = window;
}

}
