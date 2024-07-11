#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\IUIController.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Image;
		using namespace Text;

		class GameplayUIController: public IUIController
		{
		private:

			const float font_size = 40.f;

			const float text_y_position = 15.f;
			const float score_text_x_position = 60.f;

			const float bullets_y_offset = 25.f;
			const float bullets_x_offset = 1850.f;
			const float bullets_spacing = 60.f;

			const float bullet_sprite_width = 60.f;
			const float bullet_sprite_height = 60.f;

			float round_time = 15.f;
			

			const sf::Color text_color = sf::Color::White;

			ImageView* bullet_image;
			TextView* score_text; 

			TextView* timer_text;

			void createUIElements() override;
			void initializeImage();
			void initializeText();

			void updateRoundTimer();
			

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;

			void processRound();

			void endRound();

			void reset();

			void updateTimerText();
			void updateScoreText();
			void drawBullets();
		};
	}
}
