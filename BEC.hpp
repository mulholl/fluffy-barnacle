/* Binary erasure channel */

#ifndef BINARY_ERASURE_CHANNEL_HPP
#define BINARY_ERASURE_CHANNEL_HPP

	#include <random>

	#define __ERASED_BIT__ 0.5 /* The default value assigned to erased bits - this can be overriden by specifying a value to be used when instantiating the class */

	class BEC{
		public:
			BEC(std::minstd_rand0 &rng_inp);
			BEC(std::minstd_rand0 &rng_inp, const float erasureVal_inp);
			unsigned int useChannel(const int *inVec, float *outVec, const size_t numEls, const float erasureProb);
			unsigned int useChannel(float *outVec, const size_t numEls, const float erasureProb);
		private:
			std::minstd_rand0& rng; /* Reference to the RNG being used by the channel */
			const float erasureVal;
			int rng_max;
	};

#endif