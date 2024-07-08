#pragma once
#include <chrono>

namespace Time
{
	class TimeService
	{
	private:
		// A point in time which indicates the starting time of previous frame.
		std::chrono::time_point<std::chrono::steady_clock> previous_time;

		float delta_time; // To store delta time which is the time elapsed between two frames

		void updateDeltaTime();
		float calculateDeltaTime();
		void updatePreviousTime();

	public:
		void initialize();
		void update();

		float getDeltaTime();
	};
}