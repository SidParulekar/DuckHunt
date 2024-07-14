#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ButtonView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Button
{
	using namespace Global;

	ButtonView::ButtonView()
	{
	}

	void ButtonView::initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position)
	{
		ImageView::initialize(texture_path, button_width, button_height, position);
		button_title = title;
	}

	void ButtonView::render()
	{
		ImageView::render();
	}

	void ButtonView::registerCallbackFuntion(CallbackFunction button_callback)
	{
		callback_function = button_callback;
	}

	void ButtonView::update()
	{
		ImageView::update();
		handleButtonInteraction();
	}

	void ButtonView::handleButtonInteraction()
	{
		sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

		if (clickedButton(&image_sprite, mouse_position))
		{
			if (callback_function) callback_function();
		}
	}

	bool ButtonView::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
	{
		return ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton() &&
			button_sprite->getGlobalBounds().contains(mouse_position);
	}
	
	ButtonView::~ButtonView()
	{
	}

}