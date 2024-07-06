#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"

namespace Game
{
	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService() //Constructor
	{
		service_locator = nullptr;
		game_window = nullptr;
	}

	GameService::~GameService() // Destroys instances and frees up memory
	{
		destroy();
	}

	void GameService::ignite() // Starts the game
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}

	void GameService::initialize() //Sets up the game
	{
		service_locator->initialize();
		initializeVariables(); 
	}

	void GameService::initializeVariables() //Initialize game window pointer with new game window instance 
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameService::render() // Renders each frame in the game window
	{

		//Sets Game window with background color as specified in GraphicService
		game_window->clear(service_locator->getGraphicService()->getWindowColor());

		service_locator->render();

		game_window->display();
	}

	void GameService::setGameState(GameState new_state)
	{
		current_state = new_state;
	}

	GameState GameService::getGameState()
	{
		return current_state;
	}

	void GameService::update() //Updates game state
	{
		service_locator->getEventService()->processEvents();

		service_locator->update();
	}

	bool GameService::isRunning() // Checks whether the game is still running 
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	void GameService::destroy() //Performs clean up tasks
	{
		delete game_window;
	}

}
