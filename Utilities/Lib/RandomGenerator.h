/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of Utilities project.
 *
 * Utilities project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include <random>

namespace UTILS
{

	/// <summary>
	/// Use for random number generation for the UUID_V1
	/// </summary>
	static std::random_device s_RandomDevice;
	static std::mt19937_64 s_Engine(s_RandomDevice());
	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;

	//Define
	class RandomGenerator
	{

	public:

		/// <summary>
		/// A simple version of generating a UUID.
		/// </summary>
		/// <returns>uint64_t</returns>
		static uint64_t generateUUID_V1()
		{
			return s_UniformDistribution(s_Engine);
		}

	};

}

#endif //RANDOM_GENERATOR_H