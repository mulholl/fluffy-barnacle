#ifndef BINARY_INPUT_CHANNELS_HPP
#define BINARY_INPUT_CHANNELS_HPP

	#include <random>

	#include "BSC.hpp"
	#include "BEC.hpp"
	#include "BIAWGNC.hpp"

	// class GenericChannel
	// {
	// 	public:
	// 		unsigned int (*useChannel)(const int *, float *, const size_t, const float);
	// 		unsigned int (*useChannel)(float *, const size_t, const float);
	// 		GenericChannel(const std::string channelType_inp, std::minstd_rand0 &rng_inp);
	// 	private:
	// 		unsigned int channelType;
	// 		std::minstd_rand0& rng; /* Reference to the RNG being used by the channel */
	// 		int rng_max;			
	// };

	unsigned int hardDecision(const float *inpVec, int *outVec, const size_t numEls);

#endif