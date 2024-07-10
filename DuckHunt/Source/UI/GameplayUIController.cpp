#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameplayUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
		using namespace Game;

		GameplayUIController::GameplayUIController()
		{
			createUIElements();
		}

		void GameplayUIController::createUIElements()
		{
			bullet_image = new ImageView();

			score_text = new TextView(); 

			timer_text = new TextView();
		}

		void GameplayUIController::initialize()
		{
			initializeImage();
			initializeText();
		}

		void GameplayUIController::initializeImage()
		{
			bullet_image->initialize(Config::bullet_texture_path, bullet_sprite_width, bullet_sprite_height, sf::Vector2f(0, 0));
		}

		void GameplayUIController::initializeText()
		{
			sf::String score_string = "Player Score  :  0";
			score_text->initialize(score_string, sf::Vector2f(score_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);

			sf::String timer_string = "15";
			timer_text->initialize(timer_string, sf::Vector2f(0,0), FontType::BUBBLE_BOBBLE, font_size, text_color);
			timer_text->setTextXCentreAligned(text_y_position);

		}
		
		void GameplayUIController::update()
		{
			updateRoundTimer();
			processRound();
			updateScoreText();
		}


		void GameplayUIController::updateRoundTimer()
		{
			round_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			updateTimerText();
		}

		void GameplayUIController::updateTimerText()
		{
			sf::String timer_string = std::to_string(round_time);
			timer_text->setText(timer_string);
		}

		void GameplayUIController::processRound()
		{
			if (round_time < 6.f)
			{
				timer_text->setTextColor(sf::Color::Red);
			}
			if (round_time <= 0.f)
			{
				endRound();
			}
		}

		void GameplayUIController::endRound()
		{
			GameService::setGameState(GameState::RESULT);
			round_time = 15.f;
			timer_text->setTextColor(sf::Color::White);
			PlayerController::current_score = PlayerModel::score;
			ServiceLocator::getInstance()->getGameplayService()->restart();
		}

		void GameplayUIController::updateScoreText()
		{
			sf::String score_string = "Player Score  :  " + std::to_string(Player::PlayerModel::score);
			score_text->setText(score_string);
		}

		void GameplayUIController::render()
		{
			timer_text->render();
			score_text->render();
			drawBullets();
		}
		
		void GameplayUIController::drawBullets()
		{
			for (int i = 0; i < Player::PlayerModel::bullets; i++)
			{
				bullet_image->setPosition(sf::Vector2f(bullets_x_offset - (i * bullets_spacing), bullets_y_offset));
				bullet_image->render();
			}
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::destroy()
		{
			delete bullet_image;
			delete score_text;
			delete timer_text;
		}
	}
}