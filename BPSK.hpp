#ifndef MODULATORS_BPSK_HPP
#define MODULATORS_BPSK_HPP

	#include <cstddef>

	void BPSKMod(const int *inpVec, int *outVec, const size_t numEls);
	unsigned int BPSKDemod(const int *inpVec, int *outVec, const size_t numEls);
	unsigned int BPSKDemod(const float *inpVec, int *outVec, const size_t numEls);

#endif