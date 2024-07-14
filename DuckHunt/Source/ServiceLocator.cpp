#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"

namespace Global
{
	using namespace Game;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		gameplay_service = nullptr;
		duck_service = nullptr;
		time_service = nullptr;
		player_service = nullptr;
		ui_service = nullptr;
		createServices();

	}

	// Creates instances of Services
	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		gameplay_service = new GameplayService();
		duck_service = new DuckService();
		time_service = new TimeService();
		player_service = new PlayerService();
		ui_service = new UIService();
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	// Initializes service locator
	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		ui_service->initialize();
		gameplay_service->initialize();
		time_service->initialize(); 
		duck_service->initialize();
		player_service->initialize();
	}

	// Updates services
	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		gameplay_service->update();
		time_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			duck_service->update();
			player_service->update();
		}
		ui_service->update();	
	}

	// Renders the services
	void ServiceLocator::render()
	{
		graphic_service->render();
		gameplay_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			duck_service->render();
		}
		ui_service->render();
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	DuckService* ServiceLocator::getDuckService()
	{
		return duck_service;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}


	//Destructor to clean up resources on object deletion
	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	//deletes service instances and deallocates memory
	void ServiceLocator::clearAllServices()
	{
		delete graphic_service;
		delete event_service;
		delete gameplay_service;
		delete duck_service;
		delete time_service;
		delete player_service;
		delete ui_service;
		
		graphic_service = nullptr;
		event_service = nullptr;
		gameplay_service = nullptr;
		duck_service = nullptr;
		time_service = nullptr;
		player_service = nullptr;
		ui_service = nullptr;
		
	}

}