#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"

namespace Player
{
	int PlayerModel::bullets;
	int PlayerModel::score;

	PlayerModel::PlayerModel()
	{
	}

	PlayerModel::~PlayerModel()
	{
	}

	void PlayerModel::initialize()
	{
		reset();
	}

	void PlayerModel::reset()
	{
		bullets = max_bullets;
		score = 0;
	}
}