#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Player
{
	using namespace Global;
	using namespace Game;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
	}
	
	void PlayerController::initialize()
	{
		player_model->initialize();
	}

	void PlayerController::update()
	{
		if(ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton())
		{
			decreaseBullets();
		}
	}

	void PlayerController::decreaseBullets()
	{
		PlayerModel::bullets -= 1;

		if (PlayerModel::bullets <= 0)
		{
			GameService::setGameState(GameState::WAVE); 
			ServiceLocator::getInstance()->getGameplayService()->restart();
		}

		//else reset();
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