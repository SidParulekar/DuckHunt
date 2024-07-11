#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\IUIController.h"

namespace UI
{
	namespace ResultUI
	{
		using namespace Text;

		class ResultUIController : public IUIController
		{
		private:
			const float result_interval = 3.0f;

			float result_timer;

			const float font_size = 100.f;

			const sf::Color text_color = sf::Color::White;

			int player_score;

			TextView* result_text;
			TextView* player_score_text;

			bool round_won = 0;


			void createUIElements() override;
			void initializeText();

			void updateResultTimer();
			void processResultScreen();

			void updateResult();

			void destroy();

		public:
			ResultUIController();
			~ResultUIController();

			void initialize() override;
			void update() override;
			void render() override; 

			sf::String checkResult();

			//void reset();

			
		};
	}
}