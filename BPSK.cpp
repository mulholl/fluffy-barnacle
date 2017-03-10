#include "BPSK.hpp"

void BPSKMod(const int *inpVec, int *outVec, const size_t numEls)
{
	for (unsigned int i = 0; i < numEls; i++)
	{
		outVec[i] = inpVec[i] ? -1 : 1;
	}
}

unsigned int BPSKDemod(const int *inpVec, int *outVec, const size_t numEls)
{
	unsigned int nonZeros = 0;

	for (unsigned int i = 0; i < numEls; i++)
	{
		if (inpVec[i] == 1)
		{
			outVec[i] = 0;
		}
		else
		{
			outVec[i] = 1;
			nonZeros++;
		}
	}

	return nonZeros;
}

unsigned int BPSKDemod(const float *inpVec, int *outVec, const size_t numEls)
{
	unsigned int nonZeros = 0;

	for (unsigned int i = 0; i < numEls; i++)
	{
		if (inpVec[i] >= 0.5)
		{
			outVec[i] = 0;
		}
		else
		{
			outVec[i] = 1;
			nonZeros++;
		}
	}

	return nonZeros;
}