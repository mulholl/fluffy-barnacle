#include "BIAWGNC.hpp"

/* Constructor 
	Arguments:
		std::minstd_rand0 &rng_inp - reference to the RNG to be used
*/
BIAWGNC::BIAWGNC(std::minstd_rand0 &rng_inp):rng(rng_inp)
{
	rng_max = rng.max();
	dist = std::normal_distribution<float>(0.0,1.0);
}

/* Simulate transmission over the channel
	Arguments:	
		const int inVec - an input array assumed to contain only zeros and ones
		float outVec - an output array which will contain only zeros and ones
		const size_t numEls - the number of elements in each array (assumed to be correct)
		const float noisePowerdB - the noise power in dB
 */
unsigned int BIAWGNC::useChannel(const int *inVec, float *outVec, const size_t numEls, const float EbN0_dB, const float CodeRate)
{
	float EbN0_linear = pow(10, EbN0_dB/10);
	float noiseStdDev = sqrt(1 / (2 * CodeRate * EbN0_linear));

	for (unsigned int i = 0; i < numEls; i++)
	{
		outVec[i] = inVec[i] + noiseStdDev * dist(rng);
	}

	return 0;
}

/* Simulate transmission over the channel using the all-zero codeword
	Arguments:	
		float outVec - an output array which will contain only zeros and ones
		const size_t numEls - the number of elements in each array (assumed to be correct)
		const float noisePowerdB - the noise power in dB
 */
unsigned int BIAWGNC::useChannel(float *outVec, const size_t numEls, const float EbN0_dB, const float CodeRate)
{
	float EbN0_linear = pow(10, EbN0_dB/10);
	float noiseStdDev = sqrt(1 / (2 * CodeRate * EbN0_linear));

	for (unsigned int i = 0; i < numEls; i++)
	{
		outVec[i] = 1 + noiseStdDev * dist(rng);
	}

	return 0;
}

/* Change noise power to SNR in the above!!! */