/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13067 - Prime Kebab Menu                                         */


#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

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

	unsigned int nLim = static_cast<unsigned int>(sqrt(static_cast<double>(nTo)));
	unsigned int nLoop;

	for (nLoop = 3; nLoop <= nLim; nLoop += 2) {
		if (!oPrimeMap[nLoop]) {
			roPrimes.push_back(nLoop);
			const unsigned int nStep = nLoop * 2;
			for (unsigned int nCurrentPrime = nLoop * nLoop; nCurrentPrime <= nTo; nCurrentPrime += nStep)
				oPrimeMap[nCurrentPrime] = 1;
		}
	}

	for (; nLoop <= nTo; nLoop += 2)
		if (!oPrimeMap[nLoop])
			roPrimes.push_back(nLoop);
#endif // USE_SIEVE_OF_ERATOSTHENES
}

template <typename T>
void Factorize(T nNumber, const vector<unsigned int> &roPrimes, vector<pair<T, unsigned int>> &roFactorization) {
	roFactorization.clear();

	unsigned int nLimit = static_cast<int>(sqrt(static_cast<float>(nNumber))) + 1;
	for (unsigned int i = 0; i < roPrimes.size() && roPrimes[i] <= nLimit; i++) {
		if (!(nNumber % roPrimes[i])) {
			unsigned int nFactor = 0;
			do {
				nFactor++;
				nNumber /= roPrimes[i];
			} while (!(nNumber % roPrimes[i]));

			nLimit = static_cast<int>(sqrt(static_cast<float>(nNumber))) + 1;
			roFactorization.emplace_back(roPrimes[i], nFactor);
		}
	}

	if (nNumber != 1)
		roFactorization.emplace_back(nNumber, 1);
}

int main() {
	const unsigned int MAX_PRIME = 10000000U + 1;
	vector<unsigned int> oVecPrimes;

	GenPrimes(oVecPrimes, MAX_PRIME);

	unsigned long long llN;
	while ((std::cin >> llN), llN != 1) {
		vector<pair<unsigned long long, unsigned int>> oFactorization;
		Factorize(llN, oVecPrimes, oFactorization);
		int nSol = accumulate(
			oFactorization.cbegin(), 
			oFactorization.cend(), 
			0, 
			[](unsigned int nS, const pair<unsigned long long, unsigned int> &roFactor) { return nS + roFactor.second; }		//only works with C++14 and above			[](unsigned int nS, auto &o) { return nS + o.second; }
		);

		cout << nSol << endl;
	}

	return 0;
}