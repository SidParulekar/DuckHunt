#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Player\PlayerModel.h"
#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\ServiceLocator.h"

namespace Player
{
	using namespace Global;

	int PlayerModel::bullets;
	int PlayerModel::score;
	int PlayerModel::lives;
	int PlayerModel::radial_bullet;

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

	void PlayerModel::setBulletType(sf::String type)
	{
		bullet_type = type;
	}

	sf::String PlayerModel::getBulletType()
	{
		return bullet_type;
	}

	void PlayerModel::reset()
	{
		bullets = max_bullets;
		score = 0;	
		radial_bullet = 1;
		bullet_type = "Normal";
	}
}