#pragma once

#include <vector>

namespace Duck
{
	class DuckController;
	//enum class DuckType;

	class DuckService
	{
	private:
		const float spawn_interval = 2.0f;

		std::vector<DuckController*> duck_list;
		std::vector<DuckController*> flagged_duck_list;

		float spawn_timer;

		int max_ducks = 4;
		int duck_number = 0;

		int duck_kills = 0;

		float bonus_duck_spawn_interval = 5.0f;
		float bonus_duck_spawn_timer;

		DuckController* createDuck();

		void updateSpawnTimer();
		void updateBonusSpawnTimer();
		void processDuckSpawn();
		void destroyFlaggedDucks();

		void destroy();

	public:

		DuckService();
		~DuckService();

		void initialize();
		void update();
		void render();

		void reset();

		//int getCurrentDucks();

		void spawnDuck();

		void destroyDuck(DuckController* duck_controller);

	};
}