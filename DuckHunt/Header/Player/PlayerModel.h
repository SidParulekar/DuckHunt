#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameplayUIController.h"
namespace Player
{
	class PlayerModel
	{
	private:

		friend void UI::GameplayUI::GameplayUIController::updateScoreText();
		friend void UI::GameplayUI::GameplayUIController::drawBullets();
		friend void UI::GameplayUI::GameplayUIController::endRound();

		friend class PlayerController;

		const int max_bullets = 4;

		static int bullets;
		static int score;


	public:
		
		PlayerModel();
		~PlayerModel();

		void initialize();

		void reset(); // Resets all the player data stats to initial values

	};
}