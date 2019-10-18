#ifndef SFUI_FORMLAYOUT_HPP
#define SFUI_FORMLAYOUT_HPP

#include "Layout.hpp"

namespace SFUI
{

 // Horizontally stacked layout with a label before each widget.
class FormLayout : public Layout
{
public:
	FormLayout();

	Widget* add(Widget* widget, int id = -1) override;

	// label: label displayed before the widget
	// widget: widget to be added
	Widget* addRow(const sf::String& label, Widget* widget, int id = -1);

private:
 	// Update the bounds of this Widget according to the widgets inside of it.
	void recomputeGeometry() override;

	float m_labelWidth;
};

}

#endif // SFUI_FORMLAYOUT_HPP
