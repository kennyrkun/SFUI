#ifndef SFUI_COMBOBOX_HPP
#define SFUI_COMBOBOX_HPP

#include "Widget.hpp"

namespace SFUI
{

// The ComboBox is a selection widget that displays the current item, and can
// pop up a list of selectable items.
// A ComboBox provides a means of presenting a list of options to the user in a
// way that takes up the minimum amount of screen space. A ComboBox is not
// editable, the user cannot modify items in the list.
// The callback is triggered when selection is changed.
template <class T>
class ComboBox
{
public:
	ComboBox();

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

}

#include "ComboBox.inl"

#endif // SFUI_COMBOBOX_HPP
