/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10791 - Minimum Sum LCM                                          */


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

#define USE_SIEVE_OF_ERATOSTHENES

void GenPrimes(vector<unsigned int> &roPrimes, const unsigned int nTo, const unsigned int nNoPrimes = 0) {
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

	for (; nLoop <= nTo; nLoop += 2)
		if (!oPrimeMap[nLoop])
			roPrimes.push_back(nLoop);
#endif // USE_SIEVE_OF_ERATOSTHENES
}

template <typename T>
void FactorizeAsPrimeAtMaxPower(T tNumber, const vector<unsigned int> &roPrimes, vector<T> &roFactorizationPrimeAtMaxPower) {
	roFactorizationPrimeAtMaxPower.clear();

	unsigned int nLimit = static_cast<int>(sqrt(static_cast<float>(tNumber))) + 1;
	for (unsigned int i = 0; i < roPrimes.size() && roPrimes[i] <= nLimit; i++) {
		if (!(tNumber % roPrimes[i])) {
			T tFactor(1);
			do {
				tFactor *= roPrimes[i];
				tNumber /= roPrimes[i];
			} while (!(tNumber % roPrimes[i]));

			nLimit = static_cast<int>(sqrt(static_cast<float>(tNumber))) + 1;
			roFactorizationPrimeAtMaxPower.push_back(move(tFactor));
		}
	}

	if (tNumber != 1)
		roFactorizationPrimeAtMaxPower.push_back(move(tNumber));
}

int main() {
	vector<unsigned int> oVecnPrimes;
	GenPrimes(oVecnPrimes, 1 << 16);

	for (unsigned int nN, nCaseLoop = 1; (cin >> nN), nN; nCaseLoop++) {
		vector<unsigned int> oVecoFactorization;
		FactorizeAsPrimeAtMaxPower(nN, oVecnPrimes, oVecoFactorization);

		unsigned int nSol = 0;
		for (auto nDivisor : oVecoFactorization)
			nSol += nDivisor;

		if (oVecoFactorization.size() == 1)
			nSol++;
		else if (oVecoFactorization.size() == 0)
			nSol = 2;

		cout << "Case " << nCaseLoop << ": " << nSol << endl;
	}
	return 0;
}