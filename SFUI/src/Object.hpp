#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML\Graphics.hpp>

namespace SFUI {

//------------------------------------------------------------------
// Every SFUI object should extend this one.
// This is how SFUI will draw things, and handle events.
//------------------------------------------------------------------
class Object : public sf::Drawable
{
public:
	Object();
	~Object();
};

}

#endif // !OBJECT_HPP
