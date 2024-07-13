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

		static const int max_lives = 4;

		static int lives;
		static int bullets;
		static int score;


	public:
		
		PlayerModel();
		~PlayerModel();

		void initialize();

		void reset(); // Resets all the player data stats to initial values

	};
}