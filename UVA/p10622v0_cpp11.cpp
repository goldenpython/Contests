/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10622 - Perfect P-th Powers                                      */


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
void Factorize(T tNumber, const vector<unsigned int> &roPrimes, vector<pair<T, unsigned int>> &roFactorization) {
	roFactorization.clear();

	unsigned int nLimit = static_cast<int>(sqrt(static_cast<float>(tNumber))) + 1;
	for (unsigned int i = 0; i < roPrimes.size() && roPrimes[i] <= nLimit; i++) {
		if (!(tNumber % roPrimes[i])) {
			unsigned int nFactor = 0;
			do {
				nFactor++;
				tNumber /= roPrimes[i];
			} while (!(tNumber % roPrimes[i]));

			nLimit = static_cast<int>(sqrt(static_cast<float>(tNumber))) + 1;
			roFactorization.emplace_back(roPrimes[i], nFactor);
		}
	}

	if (tNumber != 1)
		roFactorization.emplace_back(tNumber, 1);
}

template <typename T>
void GetDivisors(T tNumber, const vector<T> &roVecPrimes, vector<T> &roVecDivisors) {
	vector<pair<T, unsigned int>> oVecFactorization;
	Factorize(tNumber, roVecPrimes, oVecFactorization);
	GetDivisors(oVecFactorization, roVecDivisors);
}

template <typename T>
T gcd(T a, T b) {
	T r;

	while (b) {
		r = b;
		b = a % b;
		a = r;
	}

	return a;
}

int main() {
	vector<unsigned int> oVecnPrimes;
	GenPrimes(oVecnPrimes, 1 << 16);

	for (int nN; (cin >> nN), nN; ) {
		vector<pair<unsigned int, unsigned int>> oVecFactorization;
		Factorize<unsigned int>(abs(nN), oVecnPrimes, oVecFactorization);

		unsigned int nCurrent = oVecFactorization.cbegin()->second;
		if (nN < 0) { // for negative numbers an odd power is needed
			while (!(nCurrent % 2))
				nCurrent /= 2;
		}

		for_each(
			next(oVecFactorization.cbegin()),
			oVecFactorization.cend(),
			[&rnCurrent = nCurrent] (const pair<unsigned int, unsigned int> &roPair) {
				rnCurrent = gcd(rnCurrent, roPair.second);
			}
		);

		cout << nCurrent << endl;
	}

	return 0;
}
