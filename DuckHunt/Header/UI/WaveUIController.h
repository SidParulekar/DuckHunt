#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\IUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckService.h"

namespace UI
{
	namespace WaveUI
	{
		using namespace Text;

		class WaveUIController: public IUIController
		{
		private:

			const float wave_interval = 4.0f;

			float wave_timer;

			//static int current_wave;

			static int wave_number;
			const int max_waves = 3;

			const float font_size = 100.f;

			const float text_y_position = 15.f;
			const float wave_text_x_position = 60.f;

			const sf::Color text_color = sf::Color::White;

			TextView* wave_text;

			friend void Duck::DuckService::reset();

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

		};
	}
}