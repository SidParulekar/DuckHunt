#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h"

namespace Duck
{
	using namespace Global;
	using namespace Image;

	DuckView::DuckView()
	{
		createDuckImage();
	}

	void DuckView::createDuckImage()
	{
		duck_image = new ImageView();
	}

	void DuckView::initialize(DuckController* controller)
	{
		duck_controller = controller;
		initializeDuckImage();
	}

	void DuckView::initializeDuckImage()
	{
		duck_image->initialize(getDuckTexturePath(), duck_sprite_width, duck_sprite_height, duck_controller->getDuckPosition());
	}

	sf::String DuckView::getDuckTexturePath()
	{
		return Config::duck_texture_path;
	}
	
	void DuckView::update()
	{
		duck_image->setPosition(duck_controller->getDuckPosition());
		duck_image->update();
	}

	void DuckView::render()
	{
		duck_image->render();
	}

	const sf::Sprite& DuckView::getDuckSprite()
	{
		return duck_image->getImageSprite();
	}

	DuckView::~DuckView()
	{
		delete duck_image;
	}
}