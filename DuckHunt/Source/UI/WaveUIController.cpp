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

		WaveUIController::WaveUIController()
		{
			createUIElements();
		}

		void WaveUIController::createUIElements()
		{
			wave_text = new TextView();
		}

		void WaveUIController::initialize()
		{
			wave_timer = 0.0f;
			wave_number = 1;
			initializeText();
		}

		void WaveUIController::initializeText()
		{
			sf::String wave_string = "WAVE 1";

			wave_text->initialize(wave_string, sf::Vector2f(0,0), FontType::DS_DIGIB, font_size, text_color);

			wave_text->setTextCentreAligned();
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
					reset();
				}
				else
				{
					wave_timer = 0.0f;
					updateWaveNumber();
				}
				
			}
		}

		void WaveUIController::updateWaveNumber()
		{
			wave_number += 1;
			sf::String wave_string = "WAVE " + std::to_string(wave_number);
			wave_text->setText(wave_string);
		}

		void WaveUIController::render()
		{
			wave_text->render();
		}

		void WaveUIController::reset()
		{ 
			wave_timer = 0.0f;
			wave_number = 1;
			sf::String wave_string = "WAVE 1";
			wave_text->setText(wave_string);
		}
		
		WaveUIController::~WaveUIController()
		{
			destroy();
		}

		void WaveUIController::destroy()
		{
			delete wave_text;
		}
	}
}