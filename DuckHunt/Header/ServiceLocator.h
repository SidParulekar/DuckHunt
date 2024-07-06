#pragma once
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Graphics\GraphicService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Events\EventService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayService.h"

namespace Global
{
    using namespace Graphic;
    using namespace Event;
    using namespace Gameplay;

    class ServiceLocator
    {
    private:
        // Declaring pointers to instances of different services:
        GraphicService* graphic_service;
        EventService* event_service;
        GameplayService* gameplay_service;

        // Constructor for initializing the ServiceLocator.
        ServiceLocator();

        // Destructor for cleaning up resources upon object deletion.
        ~ServiceLocator();

        // Private Methods:
        void createServices(); 			// Creates instances of all services.
        void clearAllServices(); 		//	Deletes and deallocates memory for all services.



    public:
        // Public Methods:
        static ServiceLocator* getInstance();  // Provides a method to access the unique ServiceLocator instance (object).

        void initialize(); 			//	Initializes the ServiceLocator.
        void update(); 				//	Updates all services.
        void render(); 				//	Renders the services.

        // Methods to Get Specific Services: 
        GraphicService* getGraphicService();   // Retrieve the GraphicService instance
        EventService* getEventService(); // Retrieve the EventService instance
        GameplayService* getGameplayService(); // Retrieve the GameplayService instance

    };
}