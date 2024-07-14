#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"
#include <SFML/Graphics.hpp>

namespace Game
{
	using namespace Global;

	enum class GameState
	{
		WAVE,
		GAMEPLAY,
		RESULT,
		GAME_OVER
	};

	class GameService
	{
	private:
		ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		static GameState current_state;

		void initialize();
		void initializeVariables();
		void destroy();

	public:
		GameService();
		~GameService();

		void ignite();
		void update();
		void render();
		bool isRunning();

		static void setGameState(GameState new_state);
		static GameState getGameState();
	};

}