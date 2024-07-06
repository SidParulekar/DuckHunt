#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Gameplay
{
	GameplayController::GameplayController()
	{
		gameplay_view = new GameplayView();
	}

	void GameplayController::initialize()
	{
		gameplay_view->initialize();
	}

	void GameplayController::update()
	{
		gameplay_view->update();
	}

	void GameplayController::render()
	{
		gameplay_view->render();
	}

	GameplayController::~GameplayController()
	{
		delete gameplay_view;
		gameplay_view = nullptr;
	}
}