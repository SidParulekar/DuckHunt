#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Global
{
	using namespace Graphic;
	using namespace Event;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		createServices();

	}

	// Creates instances of Services
	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
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
	}

	// Updates services
	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		
	}

	// Renders the services
	void ServiceLocator::render()
	{
		graphic_service->render();
		
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
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
		
		graphic_service = nullptr;
		event_service = nullptr;
		
	}

}