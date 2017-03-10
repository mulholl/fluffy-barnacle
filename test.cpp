#include <iostream>
#include <itpp/itcomm.h>
#include "BinaryInputChannels.hpp"
#include "BPSK.hpp"

using namespace std;

int main(void)
{
	const int vecSize = 10000;
	const unsigned int seed = 1;

	float errProb = 0.6;
	float EbN0_dB = 0.0;
	float CodeRate = 0.5;

	int numErrs = 0;
	int numErrs2 = 0;

	std::minstd_rand0 g1(seed);
	BSC channel1(g1);
	BEC channel2(g1);
	BIAWGNC channel3(g1);
	itpp::AWGN_Channel channel4(0);	

	int vec1[vecSize] = {0};
	float vec2[vecSize];
	int vec3[vecSize] = {0};
  	
  	itpp::BPSK Mod;
  	itpp::bvec bitsin = itpp::zeros_b(vecSize);
  	itpp::vec vec4 = Mod.modulate_bits(bitsin);	
  	itpp::vec vec5;
    itpp::bvec bitsout;

    int vec6[vecSize];
    for (int i = 0; i < vecSize; ++i)
    {
    	vec6[i] = 1;
    }

	// cout << "BSC:" << endl;
	// for (int i = 0; i <= 10; i++)
	// {
	// 	errProb = (float) i / 10;
	// 	numErrs = channel1.useChannel(vec1, vec2, vecSize, errProb);

	// 	cout << "\nerrProb: " << errProb << "\nNumber of errors: " << numErrs << "\nBER: " << (float)(numErrs) / vecSize << endl;
	// }

	// cout << "\n\n\nBEC:" << endl;
	// for (int i = 0; i <= 10; i++)
	// {
	// 	errProb = (float) i / 10;
	// 	numErrs = channel2.useChannel(vec1, vec2, vecSize, errProb);
	// 	numErrs2 = 0;
	// 	for (int i = 0; i < vecSize; i++)
	// 	{
	// 		if (vec2[i] == __ERASED_BIT__)
	// 		{
	// 			numErrs2++;
	// 		}
	// 	}

	// 	cout << "\nerrProb: " << errProb << "\nNumber of errors: " << numErrs << "\nNumber of errors: " << numErrs2 << "\nBER: " << (float)(numErrs) / vecSize << endl;
	// }

	cout << "BIAWGNC:" << endl;
	for (int i = 5; i <= 50; i += 5)
	{
		EbN0_dB = (float) i / 10;
		BPSKMod(vec1, vec6, vecSize);
		channel3.useChannel(vec6, vec2, vecSize, EbN0_dB, CodeRate);
		numErrs = BPSKDemod(vec2, vec3, vecSize);
		cout << "\nEbN0_dB: " << EbN0_dB << "\nNumber of errors: " << numErrs << "\nBER: " << (float)(numErrs) / vecSize << endl;

		channel4.set_noise(sqrt(1/ (2 * CodeRate * pow(10, EbN0_dB/10))));
		vec5 = channel4(vec4);
		bitsout = vec5 < 0;
    	itpp::BERC berc;  // Counters for coded and uncoded BER
		berc.count(bitsin, bitsout);
		numErrs = berc.get_errors();
		cout << "\nEbN0_dB: " << EbN0_dB << "\nNumber of errors: " << numErrs << "\nBER: " << berc.get_errorrate() << endl;

	}	
	
	return 0;
}