#include "BSC.hpp"

/* Constructor 
	Arguments:
		std::minstd_rand0 &rng_inp - reference to the RNG to be used
*/
BSC::BSC(std::minstd_rand0 &rng_inp):rng(rng_inp)
{
	rng_max = rng.max();
}

/* Simulate transmission over the channel
	Arguments:	
		const int inVec - an input array assumed to contain only zeros and ones
		float outVec - an output array which will contain only zeros and ones
		const size_t numEls - the number of elements in each array (assumed to be correct)
		const float errProb - the probability of error
	Return Value:
		int numErrs - the number of errors generated
 */
unsigned int BSC::useChannel(const int *inVec, float *outVec, const size_t numEls, const float errProb)
{
	double r;
	int numErrs = 0;

	/* Case where no bits are changed */
	if (errProb <= 0.0)
	{
		for (unsigned int i = 0; i < numEls; i++)
		{
			outVec[i] = inVec[i];
		}
	}
	/* Case where all bits are changed */
	else if (errProb >= 1.0)
	{
		for (unsigned int i = 0; i < numEls; i++)
		{
			outVec[i] = inVec[i] ? 0 : 1;
		}
		numErrs = numEls;
	}
	/* In all other cases, we must use the RNG to determine which bits to change */
	else
	{
		for (unsigned int i = 0; i < numEls; i++)
		{
			r = (double)(rng()) / rng_max;

			/* If the random value is less than the error probability, flip the current bit */
			if (r <= errProb)
			{
				outVec[i] = inVec[i] ? 0 : 1;
				numErrs++;
			}
			else
			{
				outVec[i] = inVec[i];
			}
		}
	}

	return numErrs;
}

/* Simulate transmission over the channel using the all-zero codeword
	Arguments:
		float outVec - an output array which will contain only zeros and ones
		const size_t numEls - the number of elements in each array (assumed to be correct)
		const float errProb - the probability of error
	Return Value:
		int numErrs - the number of errors generated
 */
unsigned int BSC::useChannel(float *outVec, const size_t numEls, const float errProb)
{
	double r;
	int numErrs = 0;

	/* Case where no bits are changed */
	if (errProb <= 0.0)
	{
		for (unsigned int i = 0; i < numEls; i++)
		{
			outVec[i] = 0;
		}
	}
	/* Case where all bits are changed */
	else if (errProb >= 1.0)
	{
		for (unsigned int i = 0; i < numEls; i++)
		{
			outVec[i] = 1;
		}
		numErrs = numEls;
	}
	/* In all other cases, we must use the RNG to determine which bits to change */
	else
	{
		for (unsigned int i = 0; i < numEls; i++)
		{
			r = (double)(rng()) / rng_max;

			/* If the random value is less than the error probability, flip the current bit */
			if (r <= errProb)
			{
				outVec[i] = 1;
				numErrs++;
			}
			else
			{
				outVec[i] = 0;
			}
		}
	}

	return numErrs;
}