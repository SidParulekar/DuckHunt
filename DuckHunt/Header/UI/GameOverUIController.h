#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\IUIController.h"

namespace UI
{
	namespace GameOverUI
	{
		using namespace Text;

		class GameOverUIController : public IUIController
		{
		private:

			const float font_size = 100.f;

			const sf::Color text_color = sf::Color::White;

			int total_score;

			TextView* game_over_text;
			TextView* total_score_text;


			void createUIElements() override;
			void initializeText();

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