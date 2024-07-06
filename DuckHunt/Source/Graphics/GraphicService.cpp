#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Graphics\GraphicService.h"

namespace Graphic
{
	GraphicService::GraphicService()
	{
		game_window = nullptr;
		video_mode = nullptr;
	}

	void GraphicService::initialize()
	{
		game_window = createGameWindow();
		game_window->setFramerateLimit(frame_rate);
	}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*video_mode, game_window_title, sf::Style::Fullscreen);
	}

	void GraphicService::setVideoMode()
	{
		video_mode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return game_window;
	}

	void GraphicService::update()
	{
	}

	void GraphicService::render()
	{

	}

	sf::Color GraphicService::getWindowColor()
	{
		return window_color;
	}

	bool GraphicService::isGameWindowOpen()
	{
		return game_window->isOpen();
	}

	GraphicService::~GraphicService()
	{
		onDestroy();
	}

	void GraphicService::onDestroy()
	{
		delete video_mode;
	}
}

