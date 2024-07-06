#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

namespace Graphic
{

	class GraphicService
	{
	private:
		const string game_window_title = "Duck Hunter";

		const int game_window_width = 1920;
		const int game_window_height = 1080;

		const int frame_rate = 60;

		const sf::Color window_color = sf::Color::Black;

		sf::VideoMode* video_mode;
		sf::RenderWindow* game_window;

		void setVideoMode();
		void onDestroy(); //method to run when window is deleted

	public:
		GraphicService();
		~GraphicService();

		sf::RenderWindow* createGameWindow();

		void initialize();
		void update();
		void render();
		bool isGameWindowOpen();

		sf::RenderWindow* getGameWindow();
		sf::Color getWindowColor();

	};
}