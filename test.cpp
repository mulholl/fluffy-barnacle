#include <iostream>
#include "BinaryInputChannels.hpp"

using namespace std;

int main(void)
{
	const int vecSize = 10000;
	const unsigned int seed = 1;

	float errProb = 0.6;
	float noisedB = 0.0;

	int numErrs = 0;
	int numErrs2 = 0;

	std::minstd_rand0 g1(seed);
	BSC channel1(g1);
	BEC channel2(g1);
	BIAWGNC channel3(g1);

	int vec1[vecSize] = {0};
	float vec2[vecSize];
	int vec3[vecSize] = {0};

	cout << "BSC:" << endl;
	for (int i = 0; i <= 10; i++)
	{
		errProb = (float) i / 10;
		numErrs = channel1.useChannel(vec1, vec2, vecSize, errProb);

		cout << "\nerrProb: " << errProb << "\nNumber of errors: " << numErrs << "\nBER: " << (float)(numErrs) / vecSize << endl;
	}

	cout << "\n\n\nBEC:" << endl;
	for (int i = 0; i <= 10; i++)
	{
		errProb = (float) i / 10;
		numErrs = channel2.useChannel(vec1, vec2, vecSize, errProb);
		numErrs2 = 0;
		for (int i = 0; i < vecSize; i++)
		{
			if (vec2[i] == __ERASED_BIT__)
			{
				numErrs2++;
			}
		}

		cout << "\nerrProb: " << errProb << "\nNumber of errors: " << numErrs << "\nNumber of errors: " << numErrs2 << "\nBER: " << (float)(numErrs) / vecSize << endl;
	}

	cout << "BIAWGNC:" << endl;
	for (int i = 5; i <= 50; i += 5)
	{
		noisedB = (float) i / 10;
		channel3.useChannel(vec1, vec2, vecSize, noisedB);
		numErrs = hardDecision(vec2, vec3, vecSize);

		cout << "\nnoisedB: " << noisedB << "\nNumber of errors: " << numErrs << "\nBER: " << (float)(numErrs) / vecSize << endl;
	}	
	
	return 0;
}