
#include "StopwatchService.h"
#include <iostream>

#if STOPWATCH_ENABLED

void StopwatchService::startWatch(std::string watchName)
{
	auto stopIt = stopwatchStorage.find(watchName);
	if (stopIt == stopwatchStorage.end())
	{
		// Create new Watch

		stopwatchStorage.emplace(
			std::pair<std::string, Stopwatch>(
				watchName,
				StopwatchService::Stopwatch(
					watchName,
					CURRENT_TIME
				)
			)
		);
	}
	else
	{
		// Reset Old Watch

		Stopwatch& stopW = stopIt->second;
		stopW.duration = 0;
		stopW.start = CURRENT_TIME;
	}
}

void StopwatchService::endWatch(std::string watchName)
{
	auto stopIt = stopwatchStorage.find(watchName);
	if (stopIt == stopwatchStorage.end())
	{
		// There is no watch here by that name
		return;
	}

	auto& stopW = stopIt->second;
	stopW.duration = TimerTools::getDurationInMill(stopW.start, CURRENT_TIME);

	//Need to add logic for min-value checks
	std::cout << "STOPWATCH_SERVICE: " << stopW.Name << " - " << stopW.duration;
}

#endif //TOPWATCH_ENABLED
