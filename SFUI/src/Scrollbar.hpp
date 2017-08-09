#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include <SFML\Graphics.hpp>

namespace SFUI
{
	class Scrollbar
	{
	public:
		Scrollbar();
		~Scrollbar();

		void create(sf::RenderWindow* target_window);
		void update(float contentHeight, float viewportHeight);
		void moveThumbUp();
		void moveThumbDown();
		void draw();

		sf::RectangleShape scrollbar;
		sf::RectangleShape scrollbarThumb;
		float scrollJump = 0;
		float scrollJumpMultiplier = 16;
		float maxHeight;
		float minHeight;
		float contentHeight;

		sf::RenderWindow* targetWindow;
	};
}

#endif