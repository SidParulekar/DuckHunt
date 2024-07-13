#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\IUIController.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Image;
		using namespace Text;
		using namespace Button;

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

			const float player_lives_text_y_position = 910.f;
			const float player_lives_text_x_position = 60.f;

			const float lives_y_offset = 910.f;
			const float lives_x_offset = 300.f;
			const float lives_spacing = 60.f;

			const float lives_sprite_width = 50.f;
			const float lives_sprite_height = 50.f;

			const float normal_bullet_button_y_position = 900.f;
			const float radial_bullet_button_y_position = 920.f;

			const float normal_bullet_x_position = 800.f;

			const float radial_bullet_x_position = 1090.f;

			const float normal_bullet_button_sprite_width = 150.f;
			const float normal_bullet_button_sprite_height = 150.f;

			const float radial_bullet_button_sprite_width = 50.f;
			const float radial_bullet_button_sprite_height = 100.f;
			



			float round_time = 15.f;
			

			const sf::Color text_color = sf::Color::White;

			ImageView* bullet_image;
			TextView* score_text; 

			TextView* timer_text;

			ImageView* player_lives_image;
			TextView* player_lives_text;

			ButtonView* radial_bullet_button;
			ButtonView* normal_bullet_button;

			void createUIElements() override;
			void initializeImage();
			void initializeText();
			void initializeButtons();

			void updateRoundTimer();

			void registerButtonCallbacks();

			void normalBulletButtonCallback();
			void radialBulletButtonCallback();
			

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;

			void processRound();

			void reset();

			void updateTimerText();
			void updateScoreText();
			void drawBullets();
			void drawLives();
			void drawBulletButtons();
		};
	}
}
