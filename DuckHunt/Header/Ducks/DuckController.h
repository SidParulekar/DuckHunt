#pragma once
#include <SFML/Graphics.hpp>

namespace Duck
{
	class DuckView;
	class DuckModel;

	//enum class DuckType;
	enum class DuckState;

	class DuckController 
	{
	protected:

		DuckView* duck_view;
		DuckModel* duck_model;

		void move();
		void moveUpLeft();
		void moveUpRight();
		void moveDownLeft();
		void moveDownRight();
		//void moveDown();

		sf::Vector2f getRandomInitialPosition();
		//void handleOutOfBounds();

		void handleShotDucks();
		bool shotDuck(sf::Sprite* button_sprite, sf::Vector2f mouse_position);

		virtual void destroy();

	public:
		DuckController();
		virtual ~DuckController();

		void initialize();
		void update();
		void render();

		sf::Vector2f getDuckPosition();

		//DuckType getDuckType();
		DuckState getDuckState();


	};
}