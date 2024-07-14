#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"

namespace Player
{
	
	class PlayerController
	{
	private:
		PlayerModel* player_model;

		static int current_score;

		static int total_score;

		friend void Gameplay::GameplayService::endRound();
		friend void Gameplay::GameplayService::newGame();

		sf::FloatRect radial_hit_box; 

	public:

		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		

		void reset();

		void decreaseBullets();
		inline void increaseScore(int val) { PlayerModel::score += val; }

		void addTotalScore();

		int getTotalScore();

		int getPlayerScore();

		void setBulletType(sf::String type);  
		sf::String getBulletType();   

		sf::FloatRect& getRadialDamageArea();

		bool deployedRadialBullet();


	};
}