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
void BIAWGNC::useChannel(const int *inVec, float *outVec, const size_t numEls, const float noisePowerdB)
{
	float noisePower = pow(10, noisePowerdB/10);

	for (unsigned int i = 0; i < numEls; i++)
	{
		outVec[i] = inVec[i] + sqrt(noisePower) * dist(rng);
	}
}

/* Simulate transmission over the channel using the all-zero codeword
	Arguments:	
		float outVec - an output array which will contain only zeros and ones
		const size_t numEls - the number of elements in each array (assumed to be correct)
		const float noisePowerdB - the noise power in dB
 */
void BIAWGNC::useChannel(float *outVec, const size_t numEls, const float noisePowerdB)
{
	float noisePower = pow(10, noisePowerdB/10);

	for (unsigned int i = 0; i < numEls; i++)
	{
		outVec[i] = sqrt(noisePower) * dist(rng);
	}
}

/* Change noise power to SNR in the above!!! */