#include "SFUI.hpp"
#include "Theme.hpp"

// This is an example program uitlising every control in SFUI.
// It is intended to be reviewed, and used as a learning tool
// as well as quickly previewing any changes made SFUI itself.

// Resources are not provided twice here, if you are missing
// resources copy the or symlink the folder in SFUI.

int main()
{
	enum Callbacks
	{
		TEXT,
		COLOR,
		ROTATION,
		BOLD,
		UNDERLINED,
		SCALE,
		NEW_BUTTON,
		VSLIDER,
		THEME_TEXTURE,
		TERMINATE,
		QUIT
	};

	bool doTerminateProgram(false);

	do
	{
		sf::RenderWindow window(sf::VideoMode(640, 480), "SFUI 2", sf::Style::Titlebar | sf::Style::Close);

		SFUI::Menu menu(window);
		menu.setPosition(sf::Vector2f(10, 10));

		SFUI::Theme::loadFont("resources/interface/tahoma.ttf");
		SFUI::Theme::loadTexture("resources/interface/square.png");
		SFUI::Theme::textCharacterSize = 11;
		SFUI::Theme::click.textColor = SFUI::Theme::hexToRgb("#191B18");
		SFUI::Theme::click.textColorHover = SFUI::Theme::hexToRgb("#191B18");
		SFUI::Theme::click.textColorFocus = SFUI::Theme::hexToRgb("#000000");
		SFUI::Theme::input.textColor = SFUI::Theme::hexToRgb("#000000");
		SFUI::Theme::input.textColorHover = SFUI::Theme::hexToRgb("#CC7A00");
		SFUI::Theme::input.textColorFocus = SFUI::Theme::hexToRgb("#000000");
		SFUI::Theme::windowBgColor = SFUI::Theme::hexToRgb("#dddbde");
		SFUI::Theme::PADDING = 2.f;

		SFUI::HorizontalBoxLayout* hbox = menu.addHorizontalBoxLayout();
		SFUI::FormLayout* form = hbox->addFormLayout();
		SFUI::VerticalBoxLayout* vbox = hbox->addVerticalBoxLayout();
		SFUI::HorizontalBoxLayout* hbox2 = vbox->addHorizontalBoxLayout();
		SFUI::HorizontalBoxLayout* hbox3 = vbox->addHorizontalBoxLayout();

		// Textbox
		SFUI::InputBox* textbox = new SFUI::InputBox();
		textbox->setText("Hello, World!");
		form->addRow("Text", textbox, Callbacks::TEXT);

		// Slider for rotation
		SFUI::Slider* sliderRotation = new SFUI::Slider();
		sliderRotation->setQuantum(1);
		form->addRow("Rotation", sliderRotation, Callbacks::ROTATION);

		// Progress bar
		SFUI::ProgressBar* pbar0 = new SFUI::ProgressBar();
		form->add(pbar0);

		// Slider for scale
		SFUI::Slider* sliderScale = new SFUI::Slider();
		form->addRow("Scale", sliderScale, Callbacks::SCALE);

		// OptionsBox for color
		SFUI::OptionsBox<sf::Color>* opt = new SFUI::OptionsBox<sf::Color>();
		opt->addItem("Red", sf::Color::Red);
		opt->addItem("Blue", sf::Color::Blue);
		opt->addItem("Green", sf::Color::Green);
		opt->addItem("Yellow", sf::Color::Yellow);
		opt->addItem("White", sf::Color::White);
		form->addRow("Color", opt, Callbacks::COLOR);

		// OptionsBox for color
		SFUI::ComboBox<sf::Color>* optcb = new SFUI::ComboBox<sf::Color>(&window);
		optcb->addItem("Red", sf::Color::Red);
		optcb->addItem("Blue", sf::Color::Blue);
		optcb->addItem("Green", sf::Color::Green);
		optcb->addItem("Yellow", sf::Color::Yellow);
		optcb->addItem("White", sf::Color::White);
		form->addRow("Color", optcb);

		// Checbkox
		SFUI::CheckBox* checkboxBold = new SFUI::CheckBox();
		form->addRow("Bold text", checkboxBold, Callbacks::BOLD);

		SFUI::CheckBox* checkboxUnderlined = new SFUI::CheckBox();
		form->addRow("Underlined text", checkboxUnderlined, Callbacks::UNDERLINED);

		// Custom button
		sf::Texture spriteButton_texture;
		spriteButton_texture.loadFromFile("resources/interface/themed-button.png");

		SFUI::SpriteButton* customButton = new SFUI::SpriteButton(spriteButton_texture, "Custom Button");

		customButton->setTextSize(18);
		form->add(customButton);

		// Textbox
		SFUI::InputBox* changeTextureBox = new SFUI::InputBox();
		changeTextureBox->setText("resources/interface/texture_square.png");
		form->addRow("Theme Texture", changeTextureBox, Callbacks::THEME_TEXTURE);

		vbox->addLabel("This panel is on the left");

		// Textbox
		SFUI::InputBox* textbox2 = new SFUI::InputBox(100);
		textbox2->setText("Button name");
		hbox2->add(textbox2, Callbacks::NEW_BUTTON);
		hbox2->addButton("Create button", Callbacks::NEW_BUTTON);

		// Small progress bar
		hbox3->addLabel("Small progress bar");
		SFUI::ProgressBar* pbar = new SFUI::ProgressBar(40);
		hbox3->add(pbar);

		SFUI::Slider* vslider = new SFUI::Slider(100, SFUI::Slider::Type::Vertical);
		hbox->add(vslider, Callbacks::VSLIDER);

		SFUI::CheckBox* terminateProgram = new SFUI::CheckBox();
		form->addRow("Terminate Program?", terminateProgram, Callbacks::TERMINATE);

		menu.addButton("Quit", Callbacks::QUIT);

		sf::Text text(textbox->getText(), SFUI::Theme::getFont());
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(window.getSize().x / 2, 400);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				int id = menu.onEvent(event);
				switch (id)
				{
				case Callbacks::TEXT:
					text.setString(textbox->getText());
					text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
					break;
				case Callbacks::COLOR:
					text.setFillColor(opt->getSelectedValue());
					break;
				case Callbacks::ROTATION:
					text.setRotation(sliderRotation->getValue() * 360 / 100.f);
					pbar0->setValue(sliderRotation->getValue());
					break;
				case Callbacks::UNDERLINED:
				{
					int style = text.getStyle();
					if (checkboxUnderlined->isChecked())
						style |= sf::Text::Underlined;
					else
						style &= ~sf::Text::Underlined;
					text.setStyle(style);
					break;
				}
				case Callbacks::BOLD:
				{
					int style = text.getStyle();
					if (checkboxBold->isChecked())
						style |= sf::Text::Bold;
					else
						style &= ~sf::Text::Bold;
					text.setStyle(style);
					break;
				}
				case Callbacks::SCALE:
				{
					float scale = 1 + sliderScale->getValue() * 2 / 100.f;
					text.setScale(scale, scale);
					break;
				}
				case Callbacks::QUIT:
					window.close();
					break;
				case Callbacks::VSLIDER:
					pbar->setValue(vslider->getValue());
					break;
				case Callbacks::NEW_BUTTON:
					vbox->addButton(textbox2->getText());
					break;
				case Callbacks::THEME_TEXTURE:
					SFUI::Theme::loadTexture(changeTextureBox->getText());
				case Callbacks::TERMINATE:
					doTerminateProgram = !doTerminateProgram;
				}

				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear(SFUI::Theme::windowBgColor);

			window.draw(menu);
			window.draw(text);

			window.display();
		}
	} while (!doTerminateProgram);

	return EXIT_SUCCESS;
}
