#ifndef SFUI_HPP
#define SFUI_HPP

#include <SFML\Graphics.hpp>

#include <string>
#include <vector>

namespace SFUI
{

class Object;

class SFUI final
{
public:
	SFUI(sf::RenderWindow* boundWindow_);
	~SFUI();

	void HandleEvents();
	void HandleEvents(sf::Event &event);
	void Update();
	void Draw();

	std::vector<Object> objects;
	sf::RenderWindow* renderWindow;
};

const std::string VERSION = "0.4.0";

} // SFUI namespace

#endif // !SFUI_HPP