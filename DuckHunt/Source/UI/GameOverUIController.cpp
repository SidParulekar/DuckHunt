#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameOverUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h"
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

			replay_button = new ButtonView();
		}

		void GameOverUIController::initialize()
		{
			initializeText();
			initializeButtons();
			registerButtonCallback();
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

		void GameOverUIController::initializeButtons()
		{
			replay_button->initialize("Replay Button", Config::replay_button_texture_path, button_width, button_height, sf::Vector2f(0, 630.f));
			replay_button->setCentreAlinged(); 
		}

		void GameOverUIController::registerButtonCallback()
		{
			replay_button->registerCallbackFuntion(std::bind(&GameOverUIController::replayButtonCallback, this));
		}

		void GameOverUIController::replayButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getGameplayService()->newGame();
		}
		
		void GameOverUIController::update()
		{
			total_score = ServiceLocator::getInstance()->getPlayerService()->getTotalScore();

			sf::String total_score_string = "Final Score: " + std::to_string(total_score);
			total_score_text->setText(total_score_string);

			replay_button->update();
		}
		void GameOverUIController::render()
		{
			game_over_text->render();
			total_score_text->render();

			replay_button->render();
		}

		GameOverUIController::~GameOverUIController()
		{
			destroy();
		}

		void GameOverUIController::destroy()
		{
			delete game_over_text;
			delete total_score_text;

			delete replay_button;
		}
	}
}