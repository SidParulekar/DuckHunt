#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckController.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckModel.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckView.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckConfig.h"

namespace Duck
{
	using namespace Global;

	DuckController::DuckController()
	{
		duck_model = new DuckModel();
		duck_view = new DuckView();
	}

	void DuckController::initialize()
	{
		duck_model->initialize();
		duck_model->setDuckPosition(getRandomInitialPosition());
		duck_model->setMovementDirection(duck_model->getRandomMovementDirection());
		duck_view->initialize(this);
	}

	sf::Vector2f DuckController::getRandomInitialPosition()
	{
		// Calculate distance between left most position and a random position between left most and right most
		float x_offset_distance = (std::rand() % static_cast<int>(duck_model->right_most_position.x - duck_model->left_most_position.x));

		// Add the calculated distance to left most position to get starting position of enemy
		float x_position = duck_model->left_most_position.x + x_offset_distance;

		// The y position remains the same.
		float y_position = duck_model->left_most_position.y;

		return sf::Vector2f(x_position, y_position);
	}

	void DuckController::update()
	{
		move();
		duck_view->update();
		handleShotDucks();
	}

	void DuckController::move()
	{
		switch (duck_model->getMovementDirection())
		{
			// If the movement direction is LEFT
		case::Duck::MovementDirection::UP_LEFT:
			moveUpLeft();
			break;

			// If the movement direction is RIGHT
		case::Duck::MovementDirection::UP_RIGHT:
			moveUpRight();
			break;

		case::Duck::MovementDirection::DOWN_LEFT:
			moveDownLeft();
			break;

			// If the movement direction is RIGHT
		case::Duck::MovementDirection::DOWN_RIGHT:
			moveDownRight();
			break;

		}
	}
	void DuckController::moveUpLeft()
	{
		// Duck moves diagonally left
		sf::Vector2f currentPosition = getDuckPosition();
		currentPosition.x -= duck_model->duck_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		currentPosition.y -= duck_model->vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.y <= duck_model->top_most_position.y)
		{
			duck_model->setMovementDirection(MovementDirection::DOWN_LEFT);
			//duck_model->setReferencePosition(currentPosition);
		}

		// If duck has reached left most position then start moving diagonally right
		else if (currentPosition.x <= duck_model->left_most_position.x)
		{
			duck_model->setMovementDirection(MovementDirection::UP_RIGHT);
			//duck_model->setReferencePosition(currentPosition);
		}

		// Else duck keeps moving diagonally left
		else duck_model->setDuckPosition(currentPosition);
	}
	void DuckController::moveUpRight()
	{
		// Duck moves diagonally right
		sf::Vector2f currentPosition = getDuckPosition();
		currentPosition.x += duck_model->duck_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		currentPosition.y -= duck_model->vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.y <= duck_model->top_most_position.y)
		{
			duck_model->setMovementDirection(MovementDirection::DOWN_RIGHT);
			//duck_model->setReferencePosition(currentPosition);
		}

		// If duck has reached right most position then start moving diagonally left
		else if (currentPosition.x >= duck_model->right_most_position.x)
		{
			duck_model->setMovementDirection(MovementDirection::UP_LEFT);
			//duck_model->setReferencePosition(currentPosition);
		}

		// Else duck keeps moving diagonally right
		else duck_model->setDuckPosition(currentPosition);
	}

	void DuckController::moveDownLeft()
	{
		// Duck moves diagonally left
		sf::Vector2f currentPosition = getDuckPosition();
		currentPosition.x -= duck_model->duck_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		currentPosition.y += duck_model->vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.y >= duck_model->bottom_most_position.y)
		{
			duck_model->setMovementDirection(MovementDirection::UP_LEFT); 
			//duck_model->setReferencePosition(currentPosition);
		}

		// If duck has reached left most position then start moving diagonally right
		else if (currentPosition.x <= duck_model->left_most_position.x)
		{
			duck_model->setMovementDirection(MovementDirection::DOWN_RIGHT); 
			//duck_model->setReferencePosition(currentPosition);
		}

		// Else duck keeps moving diagonally left
		else duck_model->setDuckPosition(currentPosition);
	}

	void DuckController::moveDownRight()
	{
		// Duck moves diagonally right
		sf::Vector2f currentPosition = getDuckPosition();
		currentPosition.x += duck_model->duck_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		currentPosition.y += duck_model->vertical_travel_distance * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (currentPosition.y >= duck_model->bottom_most_position.y)
		{
			duck_model->setMovementDirection(MovementDirection::UP_RIGHT);
			//duck_model->setReferencePosition(currentPosition);
		}

		// If duck has reached right most position then start moving diagonally left
		else if (currentPosition.x >= duck_model->right_most_position.x)
		{
			duck_model->setMovementDirection(MovementDirection::DOWN_LEFT);
			//duck_model->setReferencePosition(currentPosition);
		}

		// Else duck keeps moving diagonally right
		else duck_model->setDuckPosition(currentPosition);
	}

	sf::Vector2f DuckController::getDuckPosition()
	{
		return duck_model->getDuckPosition();
	}

	/*void DuckController::moveDown()
	{
	}*/

	void DuckController::render()
	{
		duck_view->render();
	}
	
	void DuckController::handleShotDucks()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		sf::Sprite duck_sprite = duck_view->getDuckSprite();
		sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

		if (shotDuck(&duck_sprite, mouse_position))
		{
			ServiceLocator::getInstance()->getPlayerService()->increaseScore(100);
			destroy();
		}
	}

	bool DuckController::shotDuck(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
	{
		return ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton() &&
			button_sprite->getGlobalBounds().contains(mouse_position); 
	}
	
	void DuckController::destroy()
	{
		ServiceLocator::getInstance()->getDuckService()->destroyDuck(this);
	}

	DuckController::~DuckController()
	{
		delete duck_model;
		delete duck_view;
		duck_model = nullptr;
		duck_view = nullptr;
	}

	DuckState DuckController::getDuckState()
	{
		return duck_model->getDuckState(); 
	}
}