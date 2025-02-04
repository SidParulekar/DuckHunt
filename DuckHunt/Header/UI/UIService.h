#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameplayUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\WaveUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\ResultUIController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\UI\GameOverUIController.h"

namespace UI
{
	using namespace GameplayUI;
	using namespace WaveUI;
	using namespace ResultUI;
	using namespace GameOverUI;

	class UIService
	{
	private:
		GameplayUIController* gameplay_ui_controller;
		WaveUIController* wave_ui_controller;
		ResultUIController* result_ui_controller;
		GameOverUIController* game_over_ui_controller;

		void createControllers(); 
		void initializeControllers();
		void destroy();


	public:

		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		IUIController* getCurrentUIController();

		WaveUIController* getWaveUIController();

		ResultUIController* getResultUIController();

		GameplayUIController* getGameplayUIController();

	};

}
