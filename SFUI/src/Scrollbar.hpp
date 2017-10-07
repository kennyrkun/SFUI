#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include <SFML\Graphics.hpp>

class Scrollbar : public sf::Drawable
{
public:
	Scrollbar();
	~Scrollbar();

	void create(sf::RenderWindow* target_window);
	void update(float contentHeight_, float viewportHeight);

	bool isEnabled;

	bool canScrollDown();
	void moveThumbDown();
	bool canScrollUp();
	void moveThumbUp();
	void moveToTop();
	void moveToBottom();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::RectangleShape scrollbar;
	sf::RectangleShape scrollThumb;

	bool thumbDragging;
	float min; // minimum scrollbar position, in pixels
	float max; // maximum scrollbar position, in pixels
	float scrollJump = 0; // amount to move the thing that moves, in pixels
	float scrollJumpMultiplier = 16; // amount to move the thumb, in pixels
	float contentHeight; // height of the content, in pixels

	float scrollbarTopPosition;
	float scrollbarBottomPosition;
	float scrollThumbTopPosition;
	float scrollThumbBottomPosition;

private:
	sf::RenderWindow* targetWindow;

	void updateLimits();
};

#endif