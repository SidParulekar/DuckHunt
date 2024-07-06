#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Gameplay\GameplayView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Image;

	GameplayView::GameplayView()
	{
		game_window = nullptr;
		createBackgroundImage();
	}

	void GameplayView::createBackgroundImage()
	{
		background_image = new ImageView(); 
	}

	void GameplayView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBackgroundImage();
	}

	void GameplayView::initializeBackgroundImage()
	{
		background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
	}

	void GameplayView::update()
	{
		background_image->update();
	}

	void GameplayView::render()
	{
		background_image->render();
	}

	GameplayView::~GameplayView()
	{
		delete background_image;
	}
}