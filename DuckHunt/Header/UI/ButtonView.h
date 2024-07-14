#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ImageView.h"
#include <functional>

namespace Button
{
	class ButtonView :public Image::ImageView
	{
	private:
		// Define a function pointer type for the callback function
		using CallbackFunction = std::function<void()>;

		// Store the callback function
		CallbackFunction callback_function = nullptr;

		sf::String button_title;

		void handleButtonInteraction();
		bool clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);

	public:
		ButtonView();
		virtual ~ButtonView();

		void initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position);
		void update() override;
		void render() override;

		void registerCallbackFuntion(CallbackFunction button_callback);
	};
}