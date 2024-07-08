#include "..\..\..\..\..\GitHub\DuckHunt\DuckHunt\Header\Time\TimeService.h"

namespace Time
{
	void TimeService::initialize()
	{
		previous_time = std::chrono::steady_clock::now();
		delta_time = 0;
	}

	void TimeService::update()
	{
		updateDeltaTime();
	}

	void TimeService::updateDeltaTime()
	{
		delta_time = calculateDeltaTime();
		updatePreviousTime();
	}

	float TimeService::calculateDeltaTime()
	{
		// To store time difference in microseconds between the current and previous frame.
		int delta = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - previous_time).count();

		// Converting the delta time calulated from microseconds to seconds and returning it.
		return static_cast<float>(delta) / static_cast<float>(1000000);
	}

	void TimeService::updatePreviousTime()
	{
		previous_time = std::chrono::steady_clock::now();
	}

	float TimeService::getDeltaTime()
	{
		return delta_time;
	}
}