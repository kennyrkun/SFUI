#include "ObjectPropertiesPanel.hpp"

#include <SFML/Graphics.hpp>
#include <SFUI.hpp>

#include <vector>

class Designer
{

};

enum TriggerType
{
	Button,
	Checkbox,
	ComboBox,
	Image,
	InputBox,
	MultilineInputBox,
	Label,
	OptionsBox,
	ProgressBar,
	Slider,
	SpriteButton
};

class Sidebar : public sf::Drawable
{
public:
	Sidebar(sf::RenderWindow& window)
	{
		spriteTexture.loadFromFile("./resources/interface/themed-button.png");

		menu = new SFUI::Menu(window);
		menu->setPosition(sf::Vector2f(10, 10));

		menu->add(button = new SFUI::Button("Button"));
		menu->add(checkBox = new SFUI::CheckBox);
		//menu->add(comboBox = new SFUI::ComboBox);
		menu->add(image = new SFUI::Image);
		menu->add(inputBox = new SFUI::InputBox);
		menu->add(multilineInpuxBox = new SFUI::MultilineInputBox);
		menu->add(label = new SFUI::Label);
		menu->add(optionsBox = new SFUI::OptionsBox<std::string>);
		menu->add(progressBar = new SFUI::ProgressBar);
		menu->add(slider = new SFUI::Slider);
		menu->add(spriteButton = new SFUI::SpriteButton(spriteTexture));

		sf::RectangleShape shape;
		shape.setSize(button->getSize());
		shape.setPosition(button->getAbsolutePosition());
		triggers.push_back({shape, TriggerType::Button});
		shape.setSize(checkBox->getSize());
		shape.setPosition(checkBox->getAbsolutePosition());
		triggers.push_back({ shape, TriggerType::Checkbox });

		barShape.setSize(sf::Vector2f(menu->getSize().x + 20, window.getSize().y));
	}

	SFUI::Button* button;
	SFUI::CheckBox* checkBox;
//	SFUI::ComboBox* comboBox;
	SFUI::Image* image;
	SFUI::InputBox* inputBox;
	SFUI::MultilineInputBox* multilineInpuxBox;
	SFUI::Label* label;
	SFUI::OptionsBox<std::string>* optionsBox;
	SFUI::ProgressBar* progressBar;
	SFUI::Slider* slider;
	SFUI::SpriteButton* spriteButton;

	sf::Texture spriteTexture;

	/*
	SFUI::Button* debugTextures;
	SFUI::Button* reloadTextures;
	SFUI::InputBox* spriteTextureLocation;
	SFUI::CheckBox* snapToGrid;
	*/

	sf::RectangleShape verticalLayoutBox;
	sf::RectangleShape horizontalLayoutBox;
	sf::Text layoutVertical;
	sf::Text layoutHorizontal;

	// the actual shape of the sidebar
	sf::RectangleShape barShape;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(barShape);
		target.draw(*menu);
	}

//	std::map<int, int> triggers;
	std::vector<std::pair<sf::RectangleShape, int>> triggers;

private:
	SFUI::Menu* menu;
};

bool mouseIsOver(const sf::Shape &object, sf::RenderWindow& window)
{
	if (object.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
		return true;

	return false;
}

int main()
{
	SFUI::Theme::loadFont("resources/interface/tahoma.ttf");
	SFUI::Theme::loadTexture("resources/interface/windows8.png");
	SFUI::Theme::textCharacterSize = 11;
	SFUI::Theme::click.textColor = SFUI::Theme::hexToRgb("#191B18");
	SFUI::Theme::click.textColorHover = SFUI::Theme::hexToRgb("#191B18");
	SFUI::Theme::click.textColorFocus = SFUI::Theme::hexToRgb("#000000");
	SFUI::Theme::input.textColor = SFUI::Theme::hexToRgb("#000000");
	SFUI::Theme::input.textColorHover = SFUI::Theme::hexToRgb("#CC7A00");
	SFUI::Theme::input.textColorFocus = SFUI::Theme::hexToRgb("#000000");
	SFUI::Theme::windowBgColor = SFUI::Theme::hexToRgb("#dddbde");
	SFUI::Theme::PADDING = 2.f;

	sf::RenderWindow window(sf::VideoMode(800, 600), "SFUI Designer");

	Designer designer;
	Sidebar sidebar(window);

	bool snapToGrid = true;
	float gridSize = 5.0f;

	bool holdingWidget = false;
	SFUI::Widget* heldWidget = nullptr;

	SFUI::Widget* selectedWidget = nullptr;

	WidgetEditor objectpanel(&window);

	std::vector<SFUI::Widget*> widgets;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
			else if (event.type == sf::Event::EventType::Resized)
			{
				sf::Vector2u newSize(event.size.width, event.size.height);

				sf::FloatRect visibleArea(0.0f, 0.0f, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}
			else if (event.type == sf::Event::EventType::MouseButtonPressed)
			{
				if (!holdingWidget)
				{
					if (mouseIsOver(sidebar.barShape, window))
					{
						for (auto& trigger : sidebar.triggers)
						{
							if (mouseIsOver(trigger.first, window))
							{
								std::cout << "clicked over sidebar object: " << trigger.second << std::endl;

								holdingWidget = true;

								switch (trigger.second)
								{
								case TriggerType::Button:
									heldWidget = new SFUI::Button("Button");
									break;
								case TriggerType::Checkbox:
									heldWidget = new SFUI::CheckBox;
									break;
									/*
									case Sidebar::TriggerType::ComboBox:
										heldWidget = new SFUI::ComboBox<std::string>(&window);
										break;
									*/
								case TriggerType::Image:
									heldWidget = new SFUI::Image;
									break;
								case TriggerType::InputBox:
									heldWidget = new SFUI::InputBox;
									break;
								case TriggerType::Label:
									heldWidget = new SFUI::Label("Label");
									break;
								case TriggerType::MultilineInputBox:
									heldWidget = new SFUI::MultilineInputBox;
									break;
								case TriggerType::OptionsBox:
									heldWidget = new SFUI::OptionsBox<std::string>;
									break;
								case TriggerType::ProgressBar:
									heldWidget = new SFUI::ProgressBar;
									break;
								case TriggerType::Slider:
									heldWidget = new SFUI::Slider;
									break;
								case TriggerType::SpriteButton:
									heldWidget = new SFUI::SpriteButton(sidebar.spriteTexture);
									break;
								default:
									std::cerr << "no object type was found" << std::endl;
									break;
								}

								if (heldWidget == nullptr)
									std::cerr << "fuck" << std::endl;

								break;
							}
						}
					}
					else
					{
						bool selectedSomeShit = false;

						for (auto& widget : widgets)
						{
							sf::FloatRect bounds(widget->getAbsolutePosition(), widget->getSize());

							if (bounds.contains(window.mapPixelToCoords(sf::Mouse::getPosition(window))))
							{
								selectedWidget = widget;
								heldWidget = widget;
								holdingWidget = true;
								selectedSomeShit = true;
								break;
							}
						}

						if (!selectedSomeShit)
							// hide the widget panel
							selectedWidget = nullptr;
						else
							objectpanel.setWidget(selectedWidget);
					}
				}
			}
			else if (event.type == sf::Event::EventType::MouseButtonReleased)
			{
				if (holdingWidget)
				{
					widgets.push_back(heldWidget);

					heldWidget = nullptr;
					holdingWidget = false;
				}
			}
			else if (event.type == sf::Event::EventType::MouseMoved)
			{
				if (holdingWidget)
					if (snapToGrid)
					{
						// nothing for now, but eventually find the proper grid size;
						heldWidget->setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
					}
					else
						heldWidget->setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y));
			}
		}

		window.clear(SFUI::Theme::windowBgColor);

		window.draw(sidebar);
		window.draw(objectpanel);

		if (holdingWidget)
			window.draw(*heldWidget);

		for (size_t i = 0; i < widgets.size(); i++)
			window.draw(*widgets[i]);

		window.display();
	}

	return 0;
}
