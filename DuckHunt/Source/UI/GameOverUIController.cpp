#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameOverUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace UI
{
	namespace GameOverUI
	{
		using namespace Global;

		GameOverUIController::GameOverUIController()
		{
			createUIElements();
		}

		void GameOverUIController::createUIElements()
		{
			game_over_text = new TextView();
			total_score_text = new TextView();
		}

		void GameOverUIController::initialize()
		{
			initializeText();
		}

		void GameOverUIController::initializeText()
		{
			sf::String game_over_string = "GAME OVER!";

			game_over_text->initialize(game_over_string, sf::Vector2f(0, 0), FontType::DS_DIGIB, font_size, text_color);

			game_over_text->setTextXCentreAligned(250.f);

			sf::String total_score_string = "Final Score:    ";

			total_score_text->initialize(total_score_string, sf::Vector2f(0, 0), FontType::DS_DIGIB, font_size, text_color);

			total_score_text->setTextXCentreAligned(400.f);
		}
		
		void GameOverUIController::update()
		{
			total_score = ServiceLocator::getInstance()->getPlayerService()->getTotalScore();

			sf::String total_score_string = "Final Score: " + std::to_string(total_score);
			total_score_text->setText(total_score_string);
		}
		void GameOverUIController::render()
		{
			game_over_text->render();
			total_score_text->render();
		}

		GameOverUIController::~GameOverUIController()
		{
			destroy();
		}

		void GameOverUIController::destroy()
		{
			delete game_over_text;
			delete total_score_text;
		}
	}
}