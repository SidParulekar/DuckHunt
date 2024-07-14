#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Player
{
	using namespace Global;
	using namespace Game;
	using namespace UI::GameplayUI;

	int PlayerController::current_score;
	int PlayerController::total_score;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
	}
	
	void PlayerController::initialize()
	{
		total_score = 0;
		player_model->initialize();
	}

	void PlayerController::update()
	{
		if(ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton()
			&& ServiceLocator::getInstance()->getPlayerService()->inPlayableArea())
		{
			decreaseBullets();
		}
		
	}

	void PlayerController::decreaseBullets()
	{
		if (getBulletType() == "Normal")
		{
			PlayerModel::bullets -= 1;
		}

		else if (getBulletType() == "Radial")
		{
			PlayerModel::radial_bullet = 0;
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			sf::CircleShape circle;
			circle.setRadius(200);
			//circle.setOutlineColor(sf::Color::Red);
			//circle.setOutlineThickness(5);
			circle.setOrigin(circle.getRadius() / 2, circle.getRadius() / 2);
			circle.setPosition(mouse_position);

			//game_window->draw(circle);

			radial_hit_box = circle.getGlobalBounds();

			//ServiceLocator::getInstance()->getPlayerService()->setBulletType("Normal");
		}

		if (PlayerModel::bullets <= 0)
		{
			ServiceLocator::getInstance()->getGameplayService()->endRound();
		}

		//else reset();
	}

	void PlayerController::addTotalScore()
	{
		total_score += current_score;
	}

	int PlayerController::getTotalScore()
	{
		return total_score;
	}

	int PlayerController::getPlayerScore()
	{
		return current_score;
	}

	void PlayerController::setBulletType(sf::String type)
	{
		player_model->setBulletType(type);
	}

	sf::String PlayerController::getBulletType()
	{
		return player_model->getBulletType();
	}

	sf::FloatRect& PlayerController::getRadialDamageArea()
	{
		return radial_hit_box;
	}

	bool PlayerController::deployedRadialBullet()
	{
		return PlayerModel::radial_bullet==0;
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}

	PlayerController::~PlayerController()
	{
		delete player_model;
	}
}