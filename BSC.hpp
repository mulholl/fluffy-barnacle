/* Binary symmetric channel */

#ifndef BINARY_SYMMETRIC_CHANNEL_HPP
#define BINARY_SYMMETRIC_CHANNEL_HPP

	#include <random>

	class BSC{
		public:
			BSC(std::minstd_rand0 &rng_inp);
			unsigned int useChannel(const int *inVec, float *outVec, const size_t numEls, const float errProb);
			unsigned int useChannel(float *outVec, const size_t numEls, const float errProb);
		private:
			std::minstd_rand0& rng; /* Reference to the RNG being used by the channel */
			int rng_max;
	};

#endif