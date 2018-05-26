#include "Scrollbar.hpp"

#include <iostream>

namespace SFUI
{

Scrollbar::Scrollbar()
{
}

Scrollbar::~Scrollbar()
{
}

void Scrollbar::create(sf::RenderWindow* target_window)
{
	std::cout << "creating scrollbar" << std::endl;

	targetWindow = target_window;

	barHeight = target_window->getSize().y;
	position = sf::Vector2f((target_window->getView().getCenter().x * 2) - scrollbar.getSize().x / 2, 0);
	position = sf::Vector2f((target_window->getView().getCenter().x * 2), 0);

//	scrollbar.setSize(sf::Vector2f(10, targetWindow->getSize().y));
//	scrollbar.setOrigin(sf::Vector2f(scrollbar.getLocalBounds().width / 2, 0));
	scrollbar.setPosition(position);
	scrollbar.setFillColor(sf::Color(80, 80, 80));

//	scrollThumb.setSize(sf::Vector2f(0, 0));
	scrollThumb.setFillColor(sf::Color(110, 110, 110));

	scrollJumpMultiplier = 16;
}

void Scrollbar::update(float contentHeight_, float viewportHeight)
{
	std::cout << "updating scrollbar" << std::endl;

	scrollbar.setSize(sf::Vector2f(barWidth, barHeight));
	scrollbar.setOrigin(sf::Vector2f(scrollbar.getSize().x / 2, 0));
//	scrollbar.setPosition(sf::Vector2f((targetWindow->getView().getCenter().x * 2) - scrollbar.getSize().x / 2, 0));
	scrollbar.setPosition(sf::Vector2f(position.x - (scrollbar.getSize().x / 2), position.y));

//	scrollThumb.setSize(sf::Vector2f(barWidth, targetWindow->getSize().y));
//	scrollThumb.setOrigin(sf::Vector2f(scrollThumb.getSize().x / 2, 0));
//	scrollThumb.setPosition(sf::Vector2f((targetWindow->getView().getCenter().x * 2) - scrollThumb.getSize().x, targetWindow->getView().getCenter().y / 2));
//	scrollThumb.setPosition(sf::Vector2f(scrollbar.getPosition().x - scrollThumb.getSize().x, targetWindow->getView().getCenter().y / 2)); // center thumb

	contentHeight = contentHeight_;
	min = scrollbar.getPosition().y;
	max = contentHeight;

//	float viewableRatio = viewportHeight / contentHeight;
//	float thumbHeight = viewportHeight * viewableRatio;

	float viewableRatio = viewportHeight / contentHeight;
	float scrollBarArea = scrollbar.getLocalBounds().height;
	float thumbHeight = scrollBarArea * viewableRatio;

//	scrollThumb.setSize(sf::Vector2f(barWidth, thumbHeight));
	scrollThumb.setSize(sf::Vector2f(barWidth, thumbHeight));
	scrollThumb.setOrigin(sf::Vector2f(scrollThumb.getSize().x / 2, 0));
	scrollThumb.setPosition(scrollbar.getPosition());

	scrollThumbTopPosition	  = scrollThumb.getPosition().y;
	scrollThumbBottomPosition = scrollThumb.getPosition().y + scrollThumb.getSize().y;
	scrollbarTopPosition	  = scrollbar.getPosition().y;
	scrollbarBottomPosition	  = scrollbar.getPosition().y + scrollbar.getSize().y;

	if (viewportHeight > contentHeight)
	{
		isEnabled = false;

		// dont update barWidth and size
		// this only makes it nonvisible
		// when it becomes visible again it will be set to normal

		scrollbar.setSize(sf::Vector2f(0, barHeight));
		scrollThumb.setSize(sf::Vector2f(0, scrollThumb.getSize().y));
		std::cout << "scrollbar disabled" << std::endl;
	}
	else
	{
		isEnabled = true;
		std::cout << "scrollbar enabled" << std::endl;
	}

	// calculate scroll step
	float scrollTrackSpace = contentHeight - viewportHeight;
	float scrollThumbSpace = viewportHeight - thumbHeight;
	scrollStep = (scrollTrackSpace / scrollThumbSpace);
	
	scrollJump = scrollStep * scrollJumpMultiplier;

	std::cout << "viewableRatio: " << viewableRatio << std::endl;
	std::cout << "viewportHeight: " << viewportHeight << std::endl;
	std::cout << "contentHeight: " << contentHeight << std::endl;
	std::cout << "scrollStep: " << scrollStep << std::endl;
	std::cout << "scrollThumb: " << scrollThumb.getSize().y << std::endl;
}

void Scrollbar::setColor(const sf::Color& scrollThumb, const sf::Color& scrollbar)
{
	this->scrollThumb.setFillColor(scrollThumb);
	this->scrollbar.setFillColor(scrollbar);
}

void Scrollbar::setFullColor(const sf::Color& scrollThumb, const sf::Color& scrollThumbHover, const sf::Color& scrollThumbDrag, const sf::Color& scrollbar)
{
	this->scrollThumb.setFillColor(scrollThumb);
	this->scrollbar.setFillColor(scrollbar);

	// TODO: hover and drag colours
}

void Scrollbar::setBarHeight(float barHeight)
{
	this->barHeight = barHeight;
	scrollbar.setSize(sf::Vector2f(scrollbar.getSize().x, barHeight));
	scrollbar.setOrigin(sf::Vector2f(scrollbar.getSize().x / 2, scrollbar.getSize().y / 2));
}

void Scrollbar::setBarWidth(float barWidth)
{
	this->barWidth = barWidth;
	scrollbar.setSize(sf::Vector2f(barWidth, scrollbar.getSize().y));
	scrollbar.setOrigin(sf::Vector2f(scrollbar.getSize().x / 2, scrollbar.getSize().y / 2));
}

void Scrollbar::setPosition(const sf::Vector2f& pos)
{
	position = pos;
	scrollbar.setPosition(sf::Vector2f(pos.x - (scrollbar.getLocalBounds().width / 2), pos.y));
	scrollThumb.setPosition(sf::Vector2f(scrollbar.getPosition().x, scrollbar.getPosition().y - scrollThumb.getPosition().y)); // why does this subtract this?
}

sf::Vector2f Scrollbar::getPosition()
{
	return scrollbar.getPosition();
}

bool Scrollbar::canScrollDown()
{
	return (scrollThumbBottomPosition < scrollbarBottomPosition);
}

void Scrollbar::moveToBottom()
{
	scrollThumb.setPosition(scrollThumb.getPosition().x, scrollbarBottomPosition - scrollThumb.getSize().y);
}

void Scrollbar::moveThumbDown()
{
	if (canScrollDown())
	{
		scrollThumb.move(0, 1 * scrollJumpMultiplier);

		updatePhysicalLimits();

		if (scrollThumbBottomPosition > scrollbarBottomPosition) // clamp
		{
			std::cout << "scrollbar went too far down (" << scrollThumbBottomPosition - scrollbarBottomPosition << "), clamping..." << std::endl;
			moveToBottom();
			updatePhysicalLimits();
		}
	}
	else
	{
		std::cout << "cannot scroll down (" << scrollThumbBottomPosition << " > " << scrollbarBottomPosition << ")" << std::endl;
	}
}

void Scrollbar::pageDown()
{
}

void Scrollbar::stepDown()
{
	if (canScrollDown())
	{
		scrollThumb.move(0, 1);

		updatePhysicalLimits();

		if (scrollThumbBottomPosition > scrollbarBottomPosition) // clamp
		{
			std::cout << "scrollbar went too far down (" << scrollThumbBottomPosition - scrollbarBottomPosition << "), clamping..." << std::endl;
			moveToBottom();
			updatePhysicalLimits();
		}
	}
	else
	{
		std::cout << "cannot step down (" << scrollThumbBottomPosition << " > " << scrollbarBottomPosition << ")" << std::endl;
	}
}

bool Scrollbar::canScrollUp()
{
	return (scrollThumbTopPosition > scrollbarTopPosition);
}

void Scrollbar::moveThumbUp()
{
	if (canScrollUp())
	{
		scrollThumb.move(0, -1 * scrollJumpMultiplier);

		updatePhysicalLimits();

		if (scrollThumbTopPosition < scrollbarTopPosition) // clamp
		{
			std::cout << "scrollbar went too far up (" << scrollbarTopPosition - scrollThumbTopPosition << "), clamping..." << std::endl;
			moveToTop();
			updatePhysicalLimits();
		}
	}
	else
	{
		std::cout << "cannot scroll up (" << scrollThumbTopPosition << " < " << scrollbarTopPosition << ")" << std::endl;
	}
}

void Scrollbar::pageUp()
{
	// TODO: pageup
	// move up viewable ratio?
}

void Scrollbar::stepUp()
{
	if (canScrollUp())
	{
		scrollThumb.move(0, -1);

		updatePhysicalLimits();

		if (scrollThumbTopPosition < scrollbarTopPosition) // clamp
		{
			std::cout << "scrollbar went too far up (" << scrollbarTopPosition - scrollThumbTopPosition << "), clamping..." << std::endl;
			moveToTop();
			updatePhysicalLimits();
		}
	}
	else
	{
		std::cout << "cannot step up (" << scrollThumbTopPosition << " < " << scrollbarTopPosition << ")" << std::endl;
	}
}

void Scrollbar::moveToTop()
{
	scrollThumb.setPosition(scrollThumb.getPosition().x, scrollbarTopPosition);
}

void Scrollbar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(scrollbar);
	target.draw(scrollThumb);
}

// PRIVATE

void Scrollbar::updatePhysicalLimits()
{
	scrollThumbTopPosition = scrollThumb.getPosition().y;
	scrollThumbBottomPosition = scrollThumb.getPosition().y + scrollThumb.getSize().y;
	scrollbarTopPosition = scrollbar.getPosition().y;
	scrollbarBottomPosition = scrollbar.getPosition().y + scrollbar.getSize().y;
}

}
