#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ResultUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\WaveUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace UI
{
	using namespace Global;
	using namespace Game;
	using namespace UI::WaveUI;

	namespace ResultUI
	{
		ResultUIController::ResultUIController()
		{
			createUIElements();
		}

		void ResultUIController::createUIElements()
		{
			result_text = new TextView();
			player_score_text = new TextView();
		}

		void ResultUIController::initialize()
		{
			result_timer = 0.0f;
			initializeText();
		}

		void ResultUIController::initializeText()
		{
			sf::String result_string = "ROUND";

			result_text->initialize(result_string, sf::Vector2f(0, 0), FontType::DS_DIGIB, font_size, text_color);

			result_text->setTextXCentreAligned(300.f);

			sf::String player_score_string = "Player Score: ";

			player_score_text->initialize(player_score_string, sf::Vector2f(0, 0), FontType::DS_DIGIB, font_size, text_color);

			player_score_text->setTextXCentreAligned(400.f);

		}

		void ResultUIController::update()
		{	
			if (result_timer == 0.0f)
			{
				updateResult(); 
			}
			updateResultTimer();
			processResultScreen(); 
		}

		void ResultUIController::updateResultTimer()
		{
			result_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}

		void ResultUIController::processResultScreen()
		{
			if (result_timer >= result_interval)
			{

				if (ServiceLocator::getInstance()->getUIService()->getWaveUIController()->isFinalRound() && round_won)
				{
					ServiceLocator::getInstance()->getPlayerService()->addTotalScore(); 
					GameService::setGameState(GameState::GAME_OVER);
				}

				else
				{
					if (round_won)
					{
						ServiceLocator::getInstance()->getPlayerService()->addTotalScore(); 
						GameService::setGameState(GameState::WAVE);
						ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::ROUND_START);
					}
					else
					{
						ServiceLocator::getInstance()->getGameplayService()->restartRound(); 
					}
					
				}
				result_timer = 0.0f;
			}
		}

		void ResultUIController::updateResult()
		{
			sf::String result_string = checkResult();
			result_text->setText(result_string);

			sf::String player_score_string = "Player Score: " + std::to_string(player_score);
			player_score_text->setText(player_score_string);
		}

		sf::String ResultUIController::checkResult()
		{
			player_score = ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();

			if (player_score >= WaveUIController::win_score)
			{
				result_text->setTextColor(sf::Color::Green);
				round_won = 1;
				return "ROUND WON";
			}

			else
			{
				result_text->setTextColor(sf::Color::Red);
				round_won = 0;
				return "ROUND LOST";
			}

		}

		void ResultUIController::reset()
		{
			player_score = 0;
			round_won = 0;
		}

		void ResultUIController::render()
		{
			result_text->render();
			player_score_text->render();
		}
		
		ResultUIController::~ResultUIController()
		{
			destroy();
		}

		void ResultUIController::destroy()
		{
			delete result_text;
			delete player_score_text;
		}
		
		
		
	}
}