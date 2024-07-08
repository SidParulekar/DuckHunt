#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ImageView.h"
#include <SFML/Graphics.hpp>

namespace Duck
{
	class DuckController;
	//enum class DuckType;

	class DuckView
	{
	private:

		const float duck_sprite_width = 60.f;
		const float duck_sprite_height = 60.f;

		DuckController* duck_controller;

		Image::ImageView* duck_image;

		void createDuckImage();
		void initializeDuckImage();
		sf::String getDuckTexturePath();

	public:
		DuckView();
		~DuckView(); 

		void initialize(DuckController* controller);
		void update();
		void render();


		const sf::Sprite& getDuckSprite();

	};
}