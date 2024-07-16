#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\WaveUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"



namespace UI
{
	namespace WaveUI
	{
		using namespace Global;
		using namespace Game;

		int WaveUIController::wave_number;
		int WaveUIController::win_score;

		WaveUIController::WaveUIController()
		{
			createUIElements();
		}

		void WaveUIController::createUIElements()
		{
			wave_text = new TextView();
			required_score_text = new TextView();
		}

		void WaveUIController::initialize()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::ROUND_START);
			wave_timer = 0.0f;
			wave_number = 1;
			current_wave = wave_number;
			win_score = required_score;
			initializeText();
		}

		void WaveUIController::initializeText()
		{
			sf::String wave_string = "WAVE 1";

			wave_text->initialize(wave_string, sf::Vector2f(0, 0), FontType::DS_DIGIB, font_size, text_color);

			wave_text->setTextXCentreAligned(250.f);

			sf::String required_score_string = "Required score to win: 400";

			required_score_text->initialize(required_score_string, sf::Vector2f(0, 0), FontType::DS_DIGIB, font_size, text_color);

			required_score_text->setTextXCentreAligned(400.f);
			
		}

		void WaveUIController::update()
		{
			updateWaveTimer();
			processWaveScreen(); 
		}

		void WaveUIController::updateWaveTimer()
		{
			wave_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		}

		void WaveUIController::processWaveScreen()
		{
			if (wave_timer >= wave_interval)
			{
				GameService::setGameState(GameState::GAMEPLAY);
				if (wave_number == max_waves)
				{
					current_wave = wave_number;
					win_score = required_score;
					final_round = 1;
					wave_timer = 0.0f;
				}
				else
				{
					wave_timer = 0.0f;
					current_wave = wave_number;
					win_score = required_score;
					updateWaveNumber();	
					updateRequiredScore();
				}
				
			}
		}

		void WaveUIController::updateWaveNumber()
		{
			wave_number += 1;
			sf::String wave_string = "WAVE " + std::to_string(wave_number);
			wave_text->setText(wave_string);
		}

		void WaveUIController::updateRequiredScore()
		{
			required_score -= 100;
			sf::String required_score_string = "Required score to win: " + std::to_string(required_score);
			required_score_text->setText(required_score_string); 
		}

		bool WaveUIController::isFinalRound()
		{
			return final_round;
		}

		void WaveUIController::render()
		{
			wave_text->render();
			required_score_text->render();
		}

		void WaveUIController::reset()
		{ 
			wave_timer = 0.0f;
			wave_number = 1;
			required_score = 400;
			final_round = 0;

			sf::String wave_string = "WAVE 1";
			wave_text->setText(wave_string);

			sf::String required_score_string = "Required score to win: 400";
			required_score_text->setText(required_score_string);
		}

		void WaveUIController::replay()
		{
			wave_number = current_wave;
			required_score = win_score;

			sf::String wave_string = "WAVE " + std::to_string(wave_number); 
			wave_text->setText(wave_string); 

			sf::String required_score_string = "Required score to win: " + std::to_string(required_score); 
			required_score_text->setText(required_score_string); 
		}
		
		WaveUIController::~WaveUIController()
		{
			destroy();
		}

		void WaveUIController::destroy()
		{
			delete wave_text;
			delete required_score_text;
		}
	}
}