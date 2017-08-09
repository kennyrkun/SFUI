#include "Scrollbar.hpp"

#include <iostream>

namespace SFUI {
Scrollbar::Scrollbar()
{
	// do stuff
}

Scrollbar::~Scrollbar()
{
	// do stuff
}

void Scrollbar::create(sf::RenderWindow* target_window)
{
	std::cout << "creating scrollbar" << std::endl;

	targetWindow = target_window;

	scrollbar.setSize(sf::Vector2f(10, targetWindow->getSize().y));
	scrollbar.setOrigin(sf::Vector2f(scrollbar.getLocalBounds().width / 2, scrollbar.getLocalBounds().height / 2));
	scrollbar.setPosition((targetWindow->getDefaultView().getCenter().x * 2) - scrollbar.getLocalBounds().width / 2, targetWindow->getDefaultView().getCenter().y);
	scrollbar.setFillColor(sf::Color(60, 60, 60));

	scrollbarThumb.setSize(sf::Vector2f(scrollbar.getSize().x, targetWindow->getSize().y));
	scrollbarThumb.setOrigin(sf::Vector2f(scrollbarThumb.getLocalBounds().width / 2, scrollbarThumb.getLocalBounds().height / 2));
	scrollbarThumb.setPosition((targetWindow->getDefaultView().getCenter().x * 2) - scrollbarThumb.getLocalBounds().width / 2, targetWindow->getDefaultView().getCenter().y);
	scrollbarThumb.setFillColor(sf::Color(100, 100, 100));

	std::cout << "scrollbar thumb is " << scrollbarThumb.getSize().x << " by " << scrollbarThumb.getSize().y << std::endl;

	scrollJumpMultiplier = 16;
}

void Scrollbar::update(float contentHeight_, float viewportHeight)
{
	std::cout << "-----------------------" << std::endl;
	std::cout << "recalculating scrollbar" << std::endl;

	contentHeight_ += 8; // padding at the end
	contentHeight = contentHeight_;
	maxHeight = contentHeight;
	minHeight = 0;

	float viewableRatio = viewportHeight / contentHeight; // 1/3 or 0.333333333n
	float thumbHeight = viewportHeight * viewableRatio; // 50px

//	float viewableRatio = viewportHeight / contentHeight; // 1/3 or 0.333333333n
//	float thumbHeight = viewportHeight * viewableRatio;

	// calculate scroll step
	float scrollTrackSpace = contentHeight - viewportHeight;
	float scrollThumbSpace = viewportHeight - thumbHeight;
	scrollJump = (scrollTrackSpace / scrollThumbSpace) * scrollJumpMultiplier;

	scrollbarThumb.setSize(sf::Vector2f(scrollbarThumb.getSize().x, thumbHeight));
	scrollbarThumb.setOrigin(scrollbarThumb.getLocalBounds().width / 2, scrollbarThumb.getLocalBounds().height / 2);
	scrollbarThumb.setPosition(scrollbar.getPosition().x, scrollbarThumb.getLocalBounds().height / 2);

	std::cout << "content height: " << contentHeight << std::endl;
	std::cout << "viewport height: " << viewportHeight << std::endl;
	std::cout << "viewable ratio: " << viewableRatio << std::endl;
	std::cout << "track space: " << scrollTrackSpace << std::endl;
	std::cout << "thumb jump: " << scrollJump << std::endl;
	std::cout << "thumb height: " << thumbHeight << std::endl;
	//	std::cout << "thumb width: "	  << scrollbarThumb.getSize().x << std::endl;
	//	std::cout << "scrollbar width: "  << scrollbar.getSize().x << std::endl;
	//	std::cout << "scrollbar height: " << scrollbar.getSize().y << std::endl;
	std::cout << "-----------------------" << std::endl;
}

void Scrollbar::moveThumbUp()
{
	std::cout << "moving thumb down" << std::endl;

	scrollbarThumb.move(0, 1 * scrollJumpMultiplier);
}

void Scrollbar::moveThumbDown()
{
	std::cout << "moving thumb up" << std::endl;

	scrollbarThumb.move(0, -1 * scrollJumpMultiplier);
}

void Scrollbar::draw()
{
	targetWindow->draw(scrollbar);
	targetWindow->draw(scrollbarThumb);
}
} // namespace
