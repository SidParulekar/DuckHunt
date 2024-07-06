#include <iostream>
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Game\GameService.h"

using namespace std;

using namespace Game;

int main()
{
    GameService* game_service = new GameService();

    game_service->ignite();

    while (game_service->isRunning())
    {
        game_service->update();
        game_service->render();
    }

    delete game_service;

    return 0;
}