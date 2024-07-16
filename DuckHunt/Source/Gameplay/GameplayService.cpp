#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Game;

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::endRound()
	{
		GameService::setGameState(GameState::RESULT);
		PlayerController::current_score = PlayerModel::score;
		ServiceLocator::getInstance()->getDuckService()->reset();
		ServiceLocator::getInstance()->getPlayerService()->reset();
		ServiceLocator::getInstance()->getUIService()->getGameplayUIController()->reset();
	}

	void GameplayService::newGame()
	{
		PlayerController::total_score = 0;
		GameService::setGameState(GameState::WAVE);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::ROUND_START);
		ServiceLocator::getInstance()->getUIService()->getWaveUIController()->reset();
		ServiceLocator::getInstance()->getUIService()->getResultUIController()->reset(); 
		ServiceLocator::getInstance()->getDuckService()->reset();
		ServiceLocator::getInstance()->getPlayerService()->reset();
		ServiceLocator::getInstance()->getUIService()->getGameplayUIController()->reset(); 
	}

	void GameplayService::restartRound()
	{
		PlayerModel::lives -= 1;
		if (PlayerModel::lives <= 0)
		{
			PlayerModel::lives = PlayerModel::max_lives; 
			GameService::setGameState(GameState::GAME_OVER);
		}
		else
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::ROUND_START);
			ServiceLocator::getInstance()->getUIService()->getWaveUIController()->replay();
			GameService::setGameState(GameState::WAVE); 
		}	
	}

	GameplayService::~GameplayService()
	{
		delete gameplay_controller;
	}
}