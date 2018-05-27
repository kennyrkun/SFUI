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
	void recomputeGeometry() override;
};

}


#endif // SFUI_HBOXLAYOUT_HPP
