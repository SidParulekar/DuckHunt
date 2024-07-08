#pragma once
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"

namespace Player
{
	
	class PlayerController
	{
	private:
		PlayerModel* player_model;

	public:

		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		

		void reset();

		void decreaseBullets();
		inline void increaseScore(int val) { PlayerModel::score += val; }


	};
}