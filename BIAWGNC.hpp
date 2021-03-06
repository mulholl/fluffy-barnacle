/* Binary symmetric channel */

#ifndef BINARY_INPUT_AWGN_CHANNEL_HPP
#define BINARY_INPUT_AWGN_CHANNEL_HPP

	#include <random>
	#include <cmath>

	class BIAWGNC{
		public:
			BIAWGNC(std::minstd_rand0 &rng_inp);
			unsigned int useChannel(const int *inVec, float *outVec, const size_t numEls, const float noisePowerdB, const float CodeRate);
			unsigned int useChannel(float *outVec, const size_t numEls, const float EbN0_dB, const float CodeRate);
			static float EbN0_to_NoiseVar(const float EbN0_dB, const float CodeRate);
		private:
			std::minstd_rand0& rng; /* Reference to the RNG being used by the channel */
			std::normal_distribution<float> dist;
			int rng_max;
	};

#endif