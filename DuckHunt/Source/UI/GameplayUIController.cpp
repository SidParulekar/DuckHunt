#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameplayUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;

		GameplayUIController::GameplayUIController()
		{
			createUIElements();
		}

		void GameplayUIController::createUIElements()
		{
			bullet_image = new ImageView();

			radial_bullet_image = new ImageView();

			score_text = new TextView(); 

			timer_text = new TextView();

			player_lives_image = new ImageView();

			player_lives_text = new TextView();

			radial_bullet_button = new ButtonView();

			normal_bullet_button = new ButtonView();
		}

		void GameplayUIController::initialize()
		{
			initializeImage();
			initializeText();
			initializeButtons();
			registerButtonCallbacks();
		}

		void GameplayUIController::initializeImage()
		{
			bullet_image->initialize(Config::bullet_texture_path, bullet_sprite_width, bullet_sprite_height, sf::Vector2f(0, 0));
			player_lives_image->initialize(Config::player_health_texture_path, lives_sprite_width, lives_sprite_height, sf::Vector2f(0, 0));
			radial_bullet_image->initialize(Config::radial_bullet_texture_path, radial_bullet_sprite_width, radial_bullet_sprite_height, sf::Vector2f(radial_bullet_x_position, radial_bullet_y_position));
		}

		void GameplayUIController::initializeText()
		{
			sf::String score_string = "Player Score  :  0";
			score_text->initialize(score_string, sf::Vector2f(score_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);

			sf::String timer_string = "15";
			timer_text->initialize(timer_string, sf::Vector2f(0,0), FontType::BUBBLE_BOBBLE, font_size, text_color);
			timer_text->setTextXCentreAligned(text_y_position);

			sf::String player_lives_string = "Player Lives  :  ";
			player_lives_text->initialize(player_lives_string, sf::Vector2f(player_lives_text_x_position, player_lives_text_y_position), FontType::BUBBLE_BOBBLE, font_size, text_color);

		}

		void GameplayUIController::initializeButtons()
		{
			normal_bullet_button->initialize("Normal Bullet Button", Config::bullet_texture_path, normal_bullet_button_sprite_width, normal_bullet_button_sprite_height, sf::Vector2f(normal_bullet_button_x_position, normal_bullet_button_y_position));
			radial_bullet_button->initialize("Radial Bullet Button", Config::radial_bullet_texture_path, radial_bullet_button_sprite_width, radial_bullet_button_sprite_height, sf::Vector2f(radial_bullet_button_x_position, radial_bullet_button_y_position));
		}
		
		void GameplayUIController::update()
		{
			updateRoundTimer();
			processRound();
			updateScoreText();
			normal_bullet_button->update();
			radial_bullet_button->update();
		}


		void GameplayUIController::updateRoundTimer()
		{
			round_time -= ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			updateTimerText();
		}

		void GameplayUIController::registerButtonCallbacks()
		{
			normal_bullet_button->registerCallbackFuntion(std::bind(&GameplayUIController::normalBulletButtonCallback, this));
			radial_bullet_button->registerCallbackFuntion(std::bind(&GameplayUIController::radialBulletButtonCallback, this));
		}

		void GameplayUIController::normalBulletButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getPlayerService()->setBulletType("Normal");
		}

		void GameplayUIController::radialBulletButtonCallback()
		{
			if (!ServiceLocator::getInstance()->getPlayerService()->deployedRadialBullet())
			{
				ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
				ServiceLocator::getInstance()->getPlayerService()->setBulletType("Radial"); 
			}	
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
				ServiceLocator::getInstance()->getGameplayService()->endRound();
			}
		}

		void GameplayUIController::reset()
		{
			round_time = 15.f;
			timer_text->setTextColor(sf::Color::White);
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
			player_lives_text->render();
			drawBullets();
			drawRadialBullet();
			drawLives();
			drawBulletButtons();
		}
		
		void GameplayUIController::drawBullets()
		{
			for (int i = 0; i < Player::PlayerModel::bullets; i++)
			{
				bullet_image->setPosition(sf::Vector2f(bullets_x_offset - (i * bullets_spacing), bullets_y_offset));
				bullet_image->render();
			}
		}

		void GameplayUIController::drawRadialBullet()
		{
			if (!ServiceLocator::getInstance()->getPlayerService()->deployedRadialBullet())
			{
				radial_bullet_image->render();
			}

		}

		void GameplayUIController::drawLives()
		{
			for (int i = 0; i < Player::PlayerModel::lives; i++)
			{
				player_lives_image->setPosition(sf::Vector2f(lives_x_offset + (i * lives_spacing), lives_y_offset));
				player_lives_image->render();
			}
		}

		void GameplayUIController::drawBulletButtons()
		{
			normal_bullet_button->render();
			radial_bullet_button->render();
		}


		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}


		void GameplayUIController::destroy()
		{
			delete bullet_image;
			delete radial_bullet_image;
			delete score_text;
			delete timer_text;
			delete player_lives_text;
			delete player_lives_image;
			delete normal_bullet_button;
			delete radial_bullet_button;
		}
	}
}