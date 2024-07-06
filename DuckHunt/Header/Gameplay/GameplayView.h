#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ImageView.h"

namespace Gameplay
{
	class GameplayView
	{
	private:
		sf::RenderWindow* game_window;
		
		Image::ImageView* background_image;

		void createBackgroundImage();
		void initializeBackgroundImage();
		//sf::String getBackgroundTexturePath();

	public:
		GameplayView();
		~GameplayView();

		void initialize();
		void update();
		void render();


	};
}