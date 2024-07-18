#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Config.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckConfig.h"

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
		switch (duck_controller->getDuckState())
		{
		case Duck::DuckState::FLYING:
			initializeFlyingDuckImage();
			break;

		case Duck::DuckState::DEAD:
			initializeShotDuckImage();
			break;
		}
		
	}

	void DuckView::initializeFlyingDuckImage()
	{
		duck_image->initialize(getDuckTexturePath(), duck_sprite_width, duck_sprite_height, duck_controller->getDuckPosition());
	}

	void DuckView::initializeShotDuckImage()
	{
		duck_image->initialize(getDuckTexturePath(), shot_duck_sprite_width, shot_duck_sprite_height, duck_controller->getDuckPosition());
	}

	sf::String DuckView::getDuckTexturePath()
	{
		switch (duck_controller->getDuckState())
		{
		case Duck::DuckState::FLYING:
			switch (duck_controller->getDuckType())
			{
			case DuckType::NORMAL_DUCK:
				return Config::duck_texture_path;
				break;

			case DuckType::BONUS_DUCK:
				return Config::bonus_duck_texture_path;
				break;
			}
			
		case Duck::DuckState::DEAD:
			return Config::shot_duck_texture_path;
			break;
		}
		
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