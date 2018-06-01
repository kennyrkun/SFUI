#ifndef SFUI_HPP
#define SFUI_HPP

// TODO: don't want to include all this stuff if we don't want to

// Widgets
#include "Button.hpp"
#include "CheckBox.hpp"
#include "ComboBox.hpp"
#include "Image.hpp"
#include "Label.hpp"
#include "OptionsBox.hpp"
#include "ProgressBar.hpp"
#include "Slider.hpp"
#include "SpriteButton.hpp"
#include "InputBox.hpp"

// Layouts
#include "Layouts/FormLayout.hpp"
#include "Layouts/HorizontalBoxLayout.hpp"
#include "Layouts/VerticalBoxLayout.hpp"
#include "Layouts/Menu.hpp"

namespace SFUI
{
	extern const int LIB_VERSION;

	class EXAMPLE
	{
	public:
		void start_blocking();
	};
}

#endif // SFUI_HPP
