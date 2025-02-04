#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\UIService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"

namespace UI
{
	using namespace Game;

	UIService::UIService()
	{
		gameplay_ui_controller = nullptr;
		wave_ui_controller = nullptr;
		result_ui_controller = nullptr;
		game_over_ui_controller = nullptr;
		createControllers();
	}

	void UIService::createControllers()
	{
		gameplay_ui_controller = new GameplayUIController();
		wave_ui_controller = new WaveUIController();
		result_ui_controller = new ResultUIController();
		game_over_ui_controller = new GameOverUIController();
	}

	void UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UIService::initializeControllers()
	{
		gameplay_ui_controller->initialize();
		wave_ui_controller->initialize();
		result_ui_controller->initialize();
		game_over_ui_controller->initialize();
	}
	
	void UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
		{
			ui_controller->update();
		}
	}

	void UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
		{
			ui_controller->render();
		}
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::WAVE:
			return wave_ui_controller;

		case GameState::GAMEPLAY:
			return gameplay_ui_controller;

		case GameState::RESULT: 
			return result_ui_controller;

		case GameState::GAME_OVER:
			return game_over_ui_controller;

		default:
			return nullptr;
		}
	}

	WaveUIController* UIService::getWaveUIController()
	{
		return wave_ui_controller;
	}

	ResultUIController* UIService::getResultUIController()
	{
		return result_ui_controller;
	}

	GameplayUIController* UIService::getGameplayUIController()
	{
		return gameplay_ui_controller;
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::destroy()
	{
		delete gameplay_ui_controller;
		delete wave_ui_controller;
		delete result_ui_controller;
		delete game_over_ui_controller;
	}

}