#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Player
{
	using namespace Global;

	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}
	
	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update(); 
	}

	void PlayerService::increaseScore(int val)
	{
		player_controller->increaseScore(val);
	}

	int PlayerService::getPlayerScore()
	{
		return player_controller->getPlayerScore();
	}

	void PlayerService::addTotalScore()
	{
		player_controller->addTotalScore();
	}

	int PlayerService::getTotalScore()
	{
		return player_controller->getTotalScore();
	}

	void PlayerService::setBulletType(sf::String type)
	{
		player_controller->setBulletType(type);
	}

	sf::String PlayerService::getBulletType()
	{
		return player_controller->getBulletType();
	}

	bool PlayerService::inPlayableArea()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

		return mouse_position.y <= 700.f;
	}

	sf::FloatRect& PlayerService::getRadialDamageArea()
	{
		return player_controller->getRadialDamageArea();
	}

	bool PlayerService::deployedRadialBullet()
	{
		return player_controller->deployedRadialBullet();
	}

	int PlayerService::normalBulletsLeft()
	{
		return player_controller->normalBulletsLeft(); 
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}

	PlayerService::~PlayerService()
	{
		delete player_controller;
	}
}