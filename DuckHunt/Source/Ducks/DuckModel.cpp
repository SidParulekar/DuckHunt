#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckModel.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Ducks\DuckConfig.h"

namespace Duck
{
	DuckModel::DuckModel()
	{
		
	}
	
	void DuckModel::initialize()
	{
		duck_state = DuckState::FLYING;
		//movement_direction = MovementDirection::RIGHT;
		//duck_position = reference_position;
	}

	sf::Vector2f DuckModel::getDuckPosition()
	{
		return duck_position;
	}

	void DuckModel::setDuckPosition(sf::Vector2f position)
	{
		duck_position = position;
	}

	sf::Vector2f DuckModel::getReferencePosition()
	{
		return reference_position;
	}

	void DuckModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}

	MovementDirection DuckModel::getRandomMovementDirection()
	{
		int randomDirection = std::rand() % 2;
		return static_cast<Duck::MovementDirection>(randomDirection);
	}

	MovementDirection DuckModel::getMovementDirection()
	{
		return movement_direction;
	}

	void DuckModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}

	DuckState DuckModel::getDuckState()
	{
		return duck_state;
	}

	void DuckModel::setDuckState(DuckState state)
	{
		duck_state = state;
	}

	DuckModel::~DuckModel()
	{
	}
}