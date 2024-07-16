#pragma once
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Graphics\GraphicService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Events\EventService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Time\TimeService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\UIService.h"
#include "..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Sounds\SoundService.h"

namespace Global
{
    using namespace Graphic;
    using namespace Event;
    using namespace Gameplay;
    using namespace Duck;
    using namespace Time;
    using namespace Player;
    using namespace UI;
    using namespace Sound;

    class ServiceLocator
    {
    private:
        // Declaring pointers to instances of different services:
        GraphicService* graphic_service;
        EventService* event_service;
        GameplayService* gameplay_service;
        DuckService* duck_service;
        TimeService* time_service;
        PlayerService* player_service;
        UIService* ui_service;
        SoundService* sound_service;

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
        DuckService* getDuckService(); // Retrieve the DuckService instance
        TimeService* getTimeService(); // Retrieve the TimeService instance
        PlayerService* getPlayerService(); // Retrieve the PlayerService instance
        UIService* getUIService(); // Retrieve the UIService instance
        SoundService* getSoundService(); // Retrieve the SoundService instance

    };
}