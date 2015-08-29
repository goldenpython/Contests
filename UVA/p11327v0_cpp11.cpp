/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11327 - Enumerating Rational Numbers                             */


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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

vector<unsigned int> g_oVecPrimes;
vector<unsigned int> g_oVecTotients;

unsigned int Totient(unsigned int nN) {
	float fTot = nN;

	for (auto oItFactor = g_oVecPrimes.begin(); *oItFactor * *oItFactor <= nN; oItFactor++) {
		if (!(nN % *oItFactor)) {
			do {
				nN /= *oItFactor;
			} while (!(nN % *oItFactor));

			fTot /= *oItFactor;
			fTot *= *oItFactor - 1;

			fTot = g_oVecTotients[nN] * fTot / nN;
			return static_cast<unsigned int>(fTot + 0.5);
		}
	}

	if (nN != 1) {
		fTot /= nN;
		fTot *= nN - 1;
	}

	return static_cast<unsigned int>(fTot + 0.5);
}

int gcd(unsigned int a, unsigned int b) {
	unsigned int r;

	while (b) {
		r = b;
		b = a % b;
		a = r;
	}

	return a;
}

int main() {
	const long long MAX = 12158598919LL;

	const unsigned int MAX_DENOMINATOR = 200000 + 2;
	const double MAX_PRIME = sqrt(static_cast<double>(MAX_DENOMINATOR)) + 15;
	GenPrimes(g_oVecPrimes, MAX_PRIME, 0);
	g_oVecPrimes.push_back(static_cast<unsigned int>(MAX_PRIME) + 1);

	g_oVecTotients.push_back(1); g_oVecTotients.push_back(1); g_oVecTotients.push_back(1); g_oVecTotients.push_back(2); g_oVecTotients.push_back(2); g_oVecTotients.push_back(4); g_oVecTotients.push_back(2); g_oVecTotients.push_back(6); g_oVecTotients.push_back(4); g_oVecTotients.push_back(6); g_oVecTotients.push_back(4);

	for (unsigned int nLoop = 11; nLoop < MAX_DENOMINATOR; nLoop++) {
		g_oVecTotients.push_back(Totient(nLoop));
	}

	vector<long long> oVecSums;
	oVecSums.push_back(g_oVecTotients[0]);
	for (unsigned int nLoop = 1; nLoop < g_oVecTotients.size(); nLoop++) {
		oVecSums.push_back(oVecSums[nLoop - 1] + g_oVecTotients[nLoop]);
	}

	long long nN;

	while ((cin >> nN), nN) {
		if (nN <= 2) {
			cout << (nN - 1) << "/1" << endl;
			continue;
		}

		auto oIt = lower_bound(oVecSums.begin(), oVecSums.end(), nN);
		nN = (*oIt) - nN;
		int nDenominator = (oIt - oVecSums.begin());
		int nNominator = nDenominator - 1;
		for (int nLoop = 0; ; nNominator--) {
			if (gcd(nNominator, nDenominator) == 1) {
				nLoop++;
				if (nLoop > nN)
					break;
			}
		}

		cout << nNominator << "/" << (oIt - oVecSums.begin()) << endl;
	}

	return 0;
}