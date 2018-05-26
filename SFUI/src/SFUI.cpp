#include "SFUI.hpp"

#include "Object.hpp"

namespace SFUI
{

SFUI::SFUI(sf::RenderWindow* boundWindow_) : renderWindow(boundWindow_)
{
}

SFUI::~SFUI()
{
	delete renderWindow;
}

void SFUI::HandleEvents()
{
	sf::Event event;

//	for (size_t i = 0; i < objects.size(); i++)
//		objects[i].handleEvents(event);
}

void SFUI::HandleEvents(sf::Event &event)
{
	//	for (size_t i = 0; i < objects.size(); i++)
	//		objects[i].handleEvents(event);
}

void SFUI::Update()
{
//	for (size_t i = 0; i < objects.size(); i++)
//		objects[i].update();
}

void SFUI::Draw()
{
//	for (size_t i = 0; i < objects.size(); i++)
//		objects[i].update();
}

} // SFUI namespace
