#ifndef SFUI_VBOXLAYOUT_HPP
#define SFUI_VBOXLAYOUT_HPP

#include "Layout.hpp"

namespace SFUI
{

// Vertically stacked layout
class VerticalBoxLayout: public Layout
{
public:
	Widget* add(Widget* widget, int id = -1) override;

private:
	void recomputeGeometry() override;
};

}


#endif // SFUI_VBOXLAYOUT_HPP
