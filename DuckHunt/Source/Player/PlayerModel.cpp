#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Player
{
	using namespace Global;

	int PlayerModel::bullets;
	int PlayerModel::score;
	int PlayerModel::lives;

	PlayerModel::PlayerModel()
	{
	}

	PlayerModel::~PlayerModel()
	{
	}

	void PlayerModel::initialize()
	{
		lives = max_lives;
		reset();
	}

	void PlayerModel::reset()
	{
		bullets = max_bullets;
		score = 0;	
	}
}