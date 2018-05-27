#ifndef SFUI_THEME_HPP
#define SFUI_THEME_HPP

#include <map>
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Widget.hpp"
#include "Utils/Box.hpp"

namespace SFUI
{

class Theme
{
public:
	// Load the GUI global font
	static bool loadFont(const std::string& path);
	static const sf::Font& getFont();

	// Load the GUI spritesheet
	static bool loadTexture(const std::string& path);
	static const sf::Texture& getTexture();

	static const sf::IntRect& getTextureRect(Box::Type type, State state);

	static const sf::IntRect& getCrossTextureRect();

	static const sf::IntRect& getArrowTextureRect();

	// Widget height based on text size
	static float getBoxHeight();

	// Height of a line of text
	static float getLineSpacing();

	static sf::Color hexToRgb(const std::string& hexcolor);

	static size_t fontSize;

	struct Style
	{
		sf::Color textColor;
		sf::Color textColorHover;
		sf::Color textColorFocus;
	};

	static Style click;
	static Style input;

	static sf::Color windowBgColor;
	static int borderSize;
	static int minWidgetWidth;

	static float PADDING; // Spacing inside widget
	static float MARGIN;  // Spacing between widgets
	static sf::Keyboard::Key previousWidgetKey;
	static sf::Keyboard::Key nextWidgetKey;

private:
	enum TextureID
	{
		// Pink
		BOX_CLICK_DEFAULT,
		BOX_CLICK_HOVERED,
		BOX_CLICK_PRESSED,
		BOX_CLICK_FOCUSED,

		// Blue
		BOX_PROGRESS_DEFAULT,
		BOX_PROGRESS_HOVERED,
		BOX_PROGRESS_PRESSED,
		BOX_PROGRESS_FOCUSED,

		// Red
		BOX_INPUT_DEFAULT,
		BOX_INPUT_HOVERED,
		BOX_INPUT_FOCUSED,
		BOX_INPUT_PRESSED,

		// Lime
		BOX_SLIDER_DEFAULT,
		BOX_SLIDER_HOVERED,
		BOX_SLIDER_FOCUSED,
		BOX_SLIDER_PRESSED,

		// Yellow
		BOX_SLIDER_HANDLE_DEFAULT,
		BOX_SLIDER_HANDLE_HOVERED,
		BOX_SLIDER_HANDLE_FOCUSED,
		BOX_SLIDER_HANDLE_PRESSED,

		// Cyan
		BOX_TICK_DEFAULT,
		BOX_TICK_HOVERED,
		BOX_TICK_FOCUSED,
		BOX_TICK_PRESSED,

		CROSS,
		ARROW,
		_TEX_COUNT
	};

	static sf::Font    m_font;
	static sf::Texture m_texture;
	static sf::IntRect m_subrects[TextureID::_TEX_COUNT];
};

}

#endif // GUI_THEME_HPP
