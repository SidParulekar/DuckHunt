#pragma once
#include <SFML/Graphics.hpp>

namespace Duck
{
	//enum class DuckType;
	enum class MovementDirection;
	enum class DuckState;
	enum class DuckType;

	class DuckModel
	{
	private:

		sf::Vector2f reference_position = sf::Vector2f(50.f, 50.f);
		sf::Vector2f duck_position;

		MovementDirection movement_direction;
		DuckType duck_type;
		DuckState duck_state;

	public:
		DuckModel();
		~DuckModel();

		void initialize();

		const sf::Vector2f left_most_position = sf::Vector2f(50.f, 720.f);
		const sf::Vector2f right_most_position = sf::Vector2f(1800.f, 720.f);
		const sf::Vector2f top_most_position = sf::Vector2f(50.f, 50.f);
		const sf::Vector2f bottom_most_position = sf::Vector2f(50.f, 720.f);

		const float vertical_travel_distance = 150.0f;
		const float bonus_duck_vertical_travel_distance = 250.0f;
		const float drop_speed = 250.f;
		static float duck_movement_speed;
		static float bonus_duck_movement_speed;

		sf::Vector2f getDuckPosition();
		void setDuckPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		MovementDirection getRandomInitialMovementDirection();

		MovementDirection getRandomMovementDirection();

		MovementDirection getMovementDirection();
		void setMovementDirection(MovementDirection direction);

		DuckType getDuckType();
		void setDuckType(DuckType type);

		DuckState getDuckState();
		void setDuckState(DuckState state);




	};
}