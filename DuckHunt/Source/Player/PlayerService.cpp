#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}
	
	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update(); 
	}

	void PlayerService::increaseScore(int val)
	{
		player_controller->increaseScore(val);
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}

	PlayerService::~PlayerService()
	{
		delete player_controller;
	}
}