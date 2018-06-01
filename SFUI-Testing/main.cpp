#include "SFUI.hpp"
#include "Theme.hpp"

// This is an example program uitlising every control in SFUI.
// It is intended to be reviewed, and used as a learning tool
// as well as quickly previewing any changes made SFUI itself.

// Resources are not provided twice here, if you are missing
// resources copy the or symlink the folder in SFUI.

int main()
{
	enum Callback
	{
		C_TEXT,
		C_COLOR,
		C_ROTATION,
		C_BOLD,
		C_UNDERLINED,
		C_SCALE,
		C_NEW_BUTTON,
		C_VSLIDER,
		C_THEME_TEXTURE,
		C_QUIT
	};

	bool quit = false;

	do
	{
		quit = true;

		// Create the main window
		sf::RenderWindow window(sf::VideoMode(640, 480), "SFUI 2", sf::Style::Titlebar | sf::Style::Close);

		// create a menu 
		SFUI::Menu menu(window);
		// set the origin of the menu to 10, 10
		menu.setPosition(sf::Vector2f(10, 10));

		SFUI::Theme::loadFont("resources/interface/tahoma.ttf");
		SFUI::Theme::loadTexture("resources/interface/texture_square.png");
		SFUI::Theme::fontSize = 11;
		SFUI::Theme::click.textColor = SFUI::Theme::hexToRgb("#191B18");
		SFUI::Theme::click.textColorHover = SFUI::Theme::hexToRgb("#191B18");
		SFUI::Theme::click.textColorFocus = SFUI::Theme::hexToRgb("#000000");
		SFUI::Theme::input.textColor = SFUI::Theme::hexToRgb("#000000");
		SFUI::Theme::input.textColorHover = SFUI::Theme::hexToRgb("#CC7A00");
		SFUI::Theme::input.textColorFocus = SFUI::Theme::hexToRgb("#000000");
		SFUI::Theme::windowBgColor = SFUI::Theme::hexToRgb("#dddbde");
		SFUI::Theme::PADDING = 2.f;

		// create a horizonal box
		SFUI::HorizontalBoxLayout* hbox = menu.addHorizontalBoxLayout();
		// create a form
		SFUI::FormLayout* form = hbox->addFormLayout();

		// Textbox
		SFUI::InputBox* textbox = new SFUI::InputBox();
		textbox->setDefaultText("Hello, World!");
		form->addRow("Text", textbox, C_TEXT);

		// Slider for rotation
		SFUI::Slider* sliderRotation = new SFUI::Slider();
		sliderRotation->setQuantum(1);
		form->addRow("Rotation", sliderRotation, C_ROTATION);

		// Progress bar
		SFUI::ProgressBar* pbar0 = new SFUI::ProgressBar();
		form->add(pbar0);

		// Slider for scale
		SFUI::Slider* sliderScale = new SFUI::Slider();
		form->addRow("Scale", sliderScale, C_SCALE);

		// OptionsBox for color
		SFUI::OptionsBox<sf::Color>* opt = new SFUI::OptionsBox<sf::Color>();
		opt->addItem("Red", sf::Color::Red);
		opt->addItem("Blue", sf::Color::Blue);
		opt->addItem("Green", sf::Color::Green);
		opt->addItem("Yellow", sf::Color::Yellow);
		opt->addItem("White", sf::Color::White);
		form->addRow("Color", opt, C_COLOR);

		// Checbkox
		SFUI::CheckBox* checkboxBold = new SFUI::CheckBox();
		form->addRow("Bold text", checkboxBold, C_BOLD);

		SFUI::CheckBox* checkboxUnderlined = new SFUI::CheckBox();
		form->addRow("Underlined text", checkboxUnderlined, C_UNDERLINED);

		// Custom button
		sf::Texture spriteButton_texture;
		spriteButton_texture.loadFromFile("resources/interface/themed-button.png");

		SFUI::SpriteButton* customButton = new SFUI::SpriteButton(spriteButton_texture, "Play game");

		customButton->setTextSize(18);
		form->addRow("Custom button", customButton);

		// Textbox
		SFUI::InputBox* changeTextureBox = new SFUI::InputBox();
		changeTextureBox->setDefaultText("resources/interface/texture_square.png");
		form->addRow("Theme Texture", changeTextureBox, C_THEME_TEXTURE);

		SFUI::VerticalBoxLayout* vbox = hbox->addVerticalBoxLayout();
		vbox->addLabel("This panel is on the left");

		// Textbox
		SFUI::HorizontalBoxLayout* hbox2 = vbox->addHorizontalBoxLayout();
		SFUI::InputBox* textbox2 = new SFUI::InputBox(100);
		textbox2->setDefaultText("Button name");
		hbox2->add(textbox2, C_NEW_BUTTON);
		hbox2->addButton("Create button", C_NEW_BUTTON);

		// Small progress bar
		SFUI::HorizontalBoxLayout* hbox3 = vbox->addHorizontalBoxLayout();
		hbox3->addLabel("Small progress bar");
		SFUI::ProgressBar* pbar = new SFUI::ProgressBar(40);
		hbox3->add(pbar);

		SFUI::Slider* vslider = new SFUI::Slider(100, SFUI::Slider::Type::Vertical);
		hbox->add(vslider, C_VSLIDER);

		menu.addButton("Quit", C_QUIT);

		sf::Texture texture;
		texture.loadFromFile("resources/textures/sfml.png");

		sf::Sprite sprite(texture);
		sprite.setOrigin(texture.getSize().x, texture.getSize().y);
		sprite.setPosition(window.getSize().x - 10, window.getSize().y - 10);

		sf::Text text(textbox->getText(), SFUI::Theme::getFont());
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(window.getSize().x / 2, 400);

		// Start the game loop
		while (window.isOpen())
		{
			// Process events
			sf::Event event;
			while (window.pollEvent(event))
			{
				int id = menu.onEvent(event);
				switch (id)
				{
				case C_TEXT:
					text.setString(textbox->getText());
					text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
					break;
				case C_COLOR:
					text.setFillColor(opt->getSelectedValue());
					break;
				case C_ROTATION:
					text.setRotation(sliderRotation->getValue() * 360 / 100.f);
					pbar0->setValue(sliderRotation->getValue());
					break;
				case C_UNDERLINED:
				{
					int style = text.getStyle();
					if (checkboxUnderlined->isChecked())
						style |= sf::Text::Underlined;
					else
						style &= ~sf::Text::Underlined;
					text.setStyle(style);
					break;
				}
				case C_BOLD:
				{
					int style = text.getStyle();
					if (checkboxBold->isChecked())
						style |= sf::Text::Bold;
					else
						style &= ~sf::Text::Bold;
					text.setStyle(style);
					break;
				}
				case C_SCALE:
				{
					float scale = 1 + sliderScale->getValue() * 2 / 100.f;
					text.setScale(scale, scale);
					break;
				}
				case C_QUIT:
					window.close();
					break;
				case C_VSLIDER:
					pbar->setValue(vslider->getValue());
					break;
				case C_NEW_BUTTON:
					vbox->addButton(textbox2->getText());
					break;
				case C_THEME_TEXTURE:
					SFUI::Theme::loadTexture(changeTextureBox->getText());
				}

				// Close window : exit
				if (event.type == sf::Event::Closed)
					window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				std::cout << "quit" << std::endl;

				quit = true;
			}

			window.clear(SFUI::Theme::windowBgColor);

			window.draw(menu);
			window.draw(text);
			window.draw(sprite);

			window.display();
		}
	} while (!quit);

	return EXIT_SUCCESS;
}
