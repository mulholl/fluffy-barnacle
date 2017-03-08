#include "BinaryInputChannels.hpp"

unsigned int hardDecision(const float *inpVec, int *outVec, const size_t numEls)
{
	unsigned int nonZeros = 0;

	for (unsigned int i = 0; i < numEls; i++)
	{
		if (inpVec[i] >= 0.5)
		{
			outVec[i] = 1;
			nonZeros++;
		}
		else
		{
			outVec[i] = 0;
		}
	}

	return nonZeros;
}