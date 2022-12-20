
#define STOPWATCH_ENABLED 1 // Move to Cmake Flag

#if STOPWATCH_ENABLED

#ifndef STOPWATCH_SERVICE
#define STOPWATCH_SERVICE

#include <string>
#include <map>
#include "TimerTools.h"

namespace UTILS
{

	//#define STOPWATCH_START
	//#define STOPWATCH_END

	// Timer tool for mesauring the amount of time between two points in code
	class StopwatchService
	{
	private:

		/// <summary>
		/// Class used to hold TimePoints
		/// </summary>
		class Stopwatch
		{
		public:
			Stopwatch(std::string pName, TimePoint pStart)
				: Name     (pName)
				, start    (pStart)
				, duration (0)
			{

			}

			~Stopwatch(){}

			/// <summary>
			/// Uniqe identifyer for the Stopwatch
			/// </summary>
			std::string Name;
			
			/// <summary>
			/// The time the stopwatch was created/reset
			/// </summary>
			TimePoint start;
			
			/// <summary>
			/// How long did the time las from the last start point
			/// </summary>
			int duration;
		};

		/// <summary>
		/// Place where all stopwaches are held.
		/// </summary>
		std::map<std::string, Stopwatch> stopwatchStorage;
		
	public:

		/// <summary>
		/// Start a stopwatch with the given name
		/// </summary>
		/// <param name="watchName">String name of the stopwatch</param>
		void startWatch(std::string watchName);
		
		/// <summary>
		/// Pass in the name of the stopwatch to then get it's duration logged.
		/// </summary>
		/// <param name="watchName">String name of the stopwatch</param>
		void endWatch(std::string watchName);

	};

	/// <summary>
	/// Public decleration for the service.
	/// </summary>
	static StopwatchService stopwatchService;
}

#endif // !STOPWATCH_SERVICE

#endif // !STOPWATCH_ENABLED
