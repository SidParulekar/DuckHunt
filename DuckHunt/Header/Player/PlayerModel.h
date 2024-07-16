#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameplayUIController.h"
namespace Player
{
	class PlayerModel
	{
	private:

		friend void UI::GameplayUI::GameplayUIController::updateScoreText();
		friend void UI::GameplayUI::GameplayUIController::drawBullets();
		friend void UI::GameplayUI::GameplayUIController::drawLives(); 
		friend void Gameplay::GameplayService::endRound(); 
		friend void Gameplay::GameplayService::restartRound(); 

		friend class PlayerController;

		const int max_bullets = 4;

		static const int max_lives = 3;

		static int lives;
		static int bullets;
		static int score;

		sf::String bullet_type = "Normal";

		static int radial_bullet;


	public:
		
		PlayerModel();
		~PlayerModel();

		void initialize();

		void setBulletType(sf::String type);
		sf::String getBulletType();

		void reset(); // Resets all the player data stats to initial values

	};
}