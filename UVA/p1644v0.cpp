/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1644 - Prime Gap                                                 */

#include <iostream>
#include <vector>
#include <algorithm>

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
	const int MAX_PRIME = 1299709 + 1;
	const int NO_PRIMES = 100000;

	vector<int> oPrimes;
	GenPrimes(oPrimes, MAX_PRIME, NO_PRIMES);

	for (int nN; cin >> nN, nN;) {
		auto oIt = lower_bound(oPrimes.begin(), oPrimes.end(), nN);
		if (*oIt == nN)
			cout << "0\n";
		else
			cout << *oIt - *(oIt - 1) << endl;
	}

	return 0;
}