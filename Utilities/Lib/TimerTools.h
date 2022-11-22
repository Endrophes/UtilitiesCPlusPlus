
#ifndef TIMER_TOOLS
#define TIMER_TOOLS

#include <chrono>
typedef std::chrono::time_point<std::chrono::system_clock> TimePoint;

// Short hand for getting the current time point
#define CURRENT_TIME std::chrono::time_point<std::chrono::system_clock>::clock::now()

class TimerTools
{
public:

	static int getDurationInMill(TimePoint start, TimePoint end)
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	}
};

#endif TIMER_TOOLS
