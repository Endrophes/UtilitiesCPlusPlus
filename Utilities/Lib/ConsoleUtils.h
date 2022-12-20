/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of Utilities project.
 *
 * Utilities project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#ifndef CONSOLE_UTILS_H
#define CONSOLE_UTILS_H

#include "../PrecompiledHeader.h"
#include <stdlib.h>

#define printMessage(pMsg)\
{\
       std::cout << pMsg << std::endl;\
};

namespace UTILS
{

	class ConsoleUtils
	{

	public:

		/// <summary>
		/// Prints a vector of options and returns what the user has selected.
		/// </summary>
		static int printAndGetOption(std::string mainMsg, std::vector<std::string> options)
		{
			printMessage("");
			printMessage(mainMsg);

			int opNum = 0;
			for (std::string option : options)
			{
				++opNum;
				printMessage((std::to_string(opNum) + ". " + option).c_str());
			}

			int optionPicked = 0;
			std::cin >> optionPicked;

			if (optionPicked == 0 || optionPicked > opNum)
			{
				printMessage("Invalid option");
				return printAndGetOption(mainMsg, options); //Recursion for the win?
			}

			return (optionPicked);
		}

		/// <summary>
		/// Takes in an option vector, but returns a given int value paired with it
		/// Helpful for dynamic console values
		/// </summary>
		static int printAndGetOption(std::string mainMsg, std::vector<std::pair<std::string, int>> options)
		{
			printMessage("");
			printMessage(mainMsg);

			int opNum = 0;
			for (std::pair<std::string, int> option : options)
			{
				++opNum;
				printMessage((std::to_string(opNum) + ". " + option.first).c_str());
			}

			int optionPicked = 0;
			std::cin >> optionPicked;

			if (optionPicked == 0 || optionPicked > opNum)
			{
				printMessage("Invalid option");
				return printAndGetOption(mainMsg, options); //Recursion for the win?
			}

			return options[(optionPicked-1)].second;
		}

		/// <summary>
		/// Clears the console screen
		/// </summary>
		static void clearConsole()
		{
			std::system("CLS");
		}
	};

}

#endif //CONSOLE_UTILS_H
