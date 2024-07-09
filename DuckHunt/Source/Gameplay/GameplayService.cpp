#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

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

	void GameplayService::restart()
	{
		ServiceLocator::getInstance()->getDuckService()->reset();
		ServiceLocator::getInstance()->getPlayerService()->reset();
	}

	GameplayService::~GameplayService()
	{
		delete gameplay_controller;
	}
}