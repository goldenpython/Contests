/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11064 - Number Theory                                            */


#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define USE_SIEVE_OF_ERATOSTHENES

void GenPrimes(vector<unsigned int> &roPrimes, const unsigned int nTo, const unsigned int nNoPrimes) {
	roPrimes.reserve(nNoPrimes);

#ifdef USE_CLASSIC_METHOD
	roPrimes.push_back(2); roPrimes.push_back(3); roPrimes.push_back(5); roPrimes.push_back(7); roPrimes.push_back(11);

	for (unsigned int nLoop = 13; nLoop <= nTo; nLoop += 2) {
		unsigned int nLim = (int)sqrt((double)nLoop);
		unsigned int nLoopPrimes;
		for (nLoopPrimes = 1; roPrimes[nLoopPrimes] <= nLim; nLoopPrimes++)
			if (!(nLoop % roPrimes[nLoopPrimes])) {
			nLoopPrimes = -1;
				break;
			}

		if (nLoopPrimes != -1)
			roPrimes.push_back(nLoop);
	}
#endif // USE_CLASSIC_METHOD

#ifdef USE_SIEVE_OF_ERATOSTHENES
	vector<char> oPrimeMap(nTo + 1);
	roPrimes.push_back(2);

	unsigned int nLim = (int)sqrt((double)nTo);
	unsigned int nLoop;

	for (nLoop = 3; nLoop <= nLim; nLoop += 2) {
		if (!oPrimeMap[nLoop]) {
			roPrimes.push_back(nLoop);
			for (unsigned int nCurrentPrime = nLoop * nLoop; nCurrentPrime <= nTo; nCurrentPrime += nLoop * 2)
				oPrimeMap[nCurrentPrime] = 1;
		}
	}

	for ( ; nLoop <= nTo; nLoop += 2)
		if (!oPrimeMap[nLoop])
			roPrimes.push_back(nLoop);
#endif // USE_SIEVE_OF_ERATOSTHENES
}

int main() {
	const unsigned int MAX = 1U << 31;
	vector<unsigned int> oVecPrimes;

	const float MAX_PRIME = sqrt(static_cast<float>(MAX)) + 1;
	GenPrimes(oVecPrimes, MAX_PRIME, 0);
	oVecPrimes.push_back(static_cast<unsigned int>(MAX_PRIME) + 1);
	
	unsigned int nN;
	string oLine;
	while (cin >> nN) {
		if (nN == 1) {
			printf("0\n");
			continue;
		}

		unsigned int nNOrig = nN;
		double fTot = nN;
		int nNoDiv = 1;
		for (auto oItFactor = oVecPrimes.begin(); *oItFactor * *oItFactor <= nN; oItFactor++) {
			if (!(nN % *oItFactor)) {
				int nPow = 0;
				do {
					nN /= *oItFactor;
					nPow++;
				} while (!(nN % *oItFactor));

				fTot /= *oItFactor;
				fTot *= *oItFactor - 1;
				nNoDiv *= (nPow + 1);
			}
		}

		if (nN != 1) {
			fTot /= nN;
			fTot *= nN - 1;
			nNoDiv *= 2;
		}

		cout << static_cast<unsigned int>(nNOrig - nNoDiv) - static_cast<unsigned int>(fTot + 0.5) + 1 << endl;
	}

	return 0;
}