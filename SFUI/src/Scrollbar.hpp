#ifndef SCROLLBAR_HPP
#define SCROLLBAR_HPP

#include "Object.hpp"

#include <SFML\Graphics.hpp>

namespace SFUI
{

// TODO: rename this to VScrollbar, then create HScrollbar
class Scrollbar : public Object
{
public:
	Scrollbar();
	~Scrollbar();

	void create(sf::RenderWindow* target_window);
	void update(float contentHeight_, float viewportHeight); // recalculate scroll parameters and thumb

	void setColor(const sf::Color& scrollThumb, const sf::Color& scrollbar);
	void setFullColor(const sf::Color& scrollThumb, const sf::Color& scrollThumbHover, const sf::Color& scrollThumbDrag, const sf::Color& scrollbar);

	void setBarHeight(float barHeight); // height of the track
	float barHeight;
	void setBarWidth(float barWidth);
	float barWidth = 10; // width of the track

	void setPosition(const sf::Vector2f& pos);
	sf::Vector2f getPosition();
	// origin of scrollbar, top right.

	bool isEnabled = false; // is there more content than the viewport can show at once?

	bool canScrollDown(); // can the scrollbar scroll down?
	void moveThumbDown(); // move the scrollthumb to the bottom of the track
	void moveToBottom(); // move the thumb down the default amount (16px)
	void pageDown(); // move the thumb down an amount equal to viewport height
	void stepDown(); // move the thumb down one pixel

	bool canScrollUp(); // can the scrollbar scroll up?
	void moveToTop(); // move the scrollthumb to the top of the track
	// move the thumb up the default amount (16px)
	void moveThumbUp(); // move the thumb up an amount equal to viewport height
	void pageUp(); // move the thumb up an amount equal to viewport height
	void stepUp(); // move the thumb up one pixel

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RectangleShape scrollbar;
	sf::RectangleShape scrollThumb;
	sf::RectangleShape topArrow; // top scroll step button
	sf::RectangleShape bottomArrow; // top scroll step button

	sf::Vector2i dragOffset; // position of the mouse relative to the origin of the scrollthumb
	sf::Vector2f originalPosition; // position of scrollbar before being dragged
	bool thumbDragging; // is the thumb being dragged by the mouse?
	float min; // minimum scrollbar position, in pixels
	float max; // maximum scrollbar position, in pixels
	float scrollStep = 0; // amount to move the content when the thumb moves 1 pixel.
//	float scrollPage = 0; // amount to move the content when the thumb moves 1 pixel.
	float scrollJump; // amount to move the content when the user scrolls normally once.
	// TODO: stop using scrollStep for how much to move the scroller.
	float scrollJumpMultiplier = 16; // amount to move the thumb, in pixels
	float contentHeight; // height of the content, in pixels

	float scrollbarTopPosition; // top of the physical scrollbar
	float scrollbarBottomPosition; // bottom of the physical scrollbar
	float scrollThumbTopPosition; // top of the physical scrollthumb
	float scrollThumbBottomPosition; // bottom of the physical scrollthumb

private:
	sf::RenderWindow* targetWindow;

	void updatePhysicalLimits(); // Updates the scrollbar & scrollthumb's physical limits.
	sf::Vector2f position; // position of the physical scrollbar's origin
};

}

#endif
