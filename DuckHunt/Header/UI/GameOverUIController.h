#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\IUIController.h"

namespace UI
{
	namespace GameOverUI
	{
		using namespace Text;
		using namespace Button;

		class GameOverUIController : public IUIController
		{
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;

			const float font_size = 100.f;

			const sf::Color text_color = sf::Color::White;

			int total_score;

			TextView* game_over_text;
			TextView* total_score_text;

			ButtonView* replay_button;


			void createUIElements() override;
			void initializeText();
			void initializeButtons();

			void registerButtonCallback();

			void replayButtonCallback();

			void destroy();

		public:
			GameOverUIController();
			~GameOverUIController();

			void initialize() override;
			void update() override;
			void render() override;

		};
	}
}