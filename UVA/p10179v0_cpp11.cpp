/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10179 - Irreducable Basic Fractions                              */


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define USE_SIEVE_OF_ERATOSTHENES

void GenPrimes(vector<int> &roPrimes, const int nTo, const int nNoPrimes) {
	roPrimes.reserve(nNoPrimes);

#ifdef USE_CLASSIC_METHOD
	roPrimes.push_back(2); roPrimes.push_back(3); roPrimes.push_back(5); roPrimes.push_back(7); roPrimes.push_back(11);

	for (int nLoop = 13; nLoop <= nTo; nLoop += 2) {
		int nLim = (int)sqrt((double)nLoop);
		int nLoopPrimes;
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

	int nLim = (int)sqrt((double)nTo);
	int nLoop;

	for (nLoop = 3; nLoop <= nLim; nLoop += 2) {
		if (!oPrimeMap[nLoop]) {
			roPrimes.push_back(nLoop);
			for (int nCurrentPrime = nLoop * nLoop; nCurrentPrime <= nTo; nCurrentPrime += nLoop * 2)
				oPrimeMap[nCurrentPrime] = 1;
		}
	}

	for ( ; nLoop <= nTo; nLoop += 2)
		if (!oPrimeMap[nLoop])
			roPrimes.push_back(nLoop);
#endif // USE_SIEVE_OF_ERATOSTHENES
}

int main() {
	const int MAX = 1000000000;
	vector<int> oVecPrimes;

	GenPrimes(oVecPrimes, sqrt(static_cast<float>(MAX)) + 1, 0);
	
	int nN;
	while ((cin >> nN), nN) {
		double fSol = nN;
		for (auto oItFactor = oVecPrimes.begin(); *oItFactor * *oItFactor <= nN && oItFactor < oVecPrimes.end(); oItFactor++) {
			if (!(nN % *oItFactor)) {
				int nPow = 0;
				do {
					nN /= *oItFactor;
					nPow++;
				} while (!(nN % *oItFactor));

				fSol /= *oItFactor;
				fSol *= *oItFactor - 1;
			}
		}

		if (nN != 1) {
			fSol /= nN;
			fSol *= nN - 1;
		}

		cout << static_cast<int>(fSol + 0.5) << endl;
	}

	return 0;

}