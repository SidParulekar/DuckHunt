#pragma once

namespace Duck
{
	enum class DuckState
	{
		FLYING,
		DEAD
	};

	enum class MovementDirection
	{
		UP_LEFT,
		UP_RIGHT,
		DOWN_LEFT,
		DOWN_RIGHT
	};

	enum class DuckType
	{
		NORMAL_DUCK,
		BONUS_DUCK
	};
}
