#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckService.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Duck
{
	using namespace Global;

	DuckService::DuckService()
	{
		
	}

	void DuckService::initialize()
	{
		spawn_timer = spawn_interval;
	}

	void DuckService::update()
	{
		updateSpawnTimer();
		processDuckSpawn();

		for (int i = 0; i < duck_list.size(); i++) duck_list[i]->update();

		destroyFlaggedDucks();
	}

	void DuckService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void DuckService::processDuckSpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnDuck();
			spawn_timer = 0.0f;
		}
	}

	void DuckService::spawnDuck()
	{
		DuckController* duck_controller = createDuck();
		duck_controller->initialize();

		duck_list.push_back(duck_controller);

	}

	DuckController* DuckService::createDuck()
	{
		return new DuckController();
	}

	void DuckService::render()
	{
		for (int i = 0; i < duck_list.size(); i++) duck_list[i]->render();
	}

	void DuckService::destroyDuck(DuckController* duck_controller)
	{
		flagged_duck_list.push_back(duck_controller);
		duck_list.erase(std::remove(duck_list.begin(), duck_list.end(), duck_controller), duck_list.end());
	}

	void DuckService::destroyFlaggedDucks()
	{
		for (int i = 0; i < flagged_duck_list.size(); i++)
		{
			delete (flagged_duck_list[i]);
		}
		flagged_duck_list.clear();
	}

	DuckService::~DuckService()
	{
		destroy();
		spawn_timer = 0.0f;
	}

	void DuckService::destroy()
	{
		for (int i = 0; i < duck_list.size(); i++)
		{
			delete (duck_list[i]);
		}
		duck_list.clear();
	}	

	void DuckService::reset()
	{
		destroy();
		spawn_timer = 0.0f;
	}

	

	

}