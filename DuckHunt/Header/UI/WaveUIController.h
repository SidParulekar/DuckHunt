#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\IUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ResultUIController.h"

namespace UI
{
	namespace WaveUI
	{
		using namespace Text;

		class WaveUIController: public IUIController
		{
		private:

			const float wave_interval = 4.0f;
			//const float result_interval = 3.0f;

			float wave_timer;
			//float result_timer;

			//static int current_wave;

			static int wave_number;
			const int max_waves = 3;

			int required_score = 400;
			static int win_score;

			const float font_size = 100.f;

			const sf::Color text_color = sf::Color::White;

			TextView* wave_text;
			TextView* required_score_text;

			//TextView* result_text;
			//TextView* player_score_text;

			friend void Duck::DuckService::reset();
			friend sf::String ResultUI::ResultUIController::checkResult();

			void createUIElements() override;
			void initializeText();

			void updateWaveTimer();
			void processWaveScreen();

			void destroy();

		public:
			WaveUIController();
			~WaveUIController();

			void initialize() override;
			void update() override;
			void render() override;

			void reset();

			void updateWaveNumber();
			void updateRequiredScore();

		};
	}
}