#ifndef SFUI_HBOXLAYOUT_HPP
#define SFUI_HBOXLAYOUT_HPP

#include "Layout.hpp"

namespace SFUI
{

// Horizontally stacked layout
class HorizontalBoxLayout : public Layout
{
public:
	Widget* add(Widget* widget, int id = -1) override;

protected:
	// Update this widget's size according to the widgets inside of it.
	void recomputeGeometry() override;
};

}


#endif // !SFUI_HBOXLAYOUT_HPP
