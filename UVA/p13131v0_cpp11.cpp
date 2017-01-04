/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13131 - Divisors                                                 */


#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

#define USE_SIEVE_OF_ERATOSTHENES
#define USE_CLASSIC_METHOD__

void GenPrimes(std::vector<unsigned int> &roPrimes, const unsigned int nTo, const unsigned int nNoPrimes = 0) {
	roPrimes.reserve(nNoPrimes);

#ifdef USE_CLASSIC_METHOD
	roPrimes.push_back(2); roPrimes.push_back(3); roPrimes.push_back(5); roPrimes.push_back(7); roPrimes.push_back(11);

	for (unsigned int nLoop = 13; nLoop <= nTo; nLoop += 2) {
		unsigned int nLim = (int)std::sqrt(static_cast<double>(nLoop));
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
	std::vector<char> oPrimeMap(nTo + 1);
	roPrimes.push_back(2);

	unsigned int nLim = (int)sqrt(static_cast<double>(nTo));
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


void Factorize(int nNumber, const std::vector<unsigned int> &roPrimes, std::vector< std::pair<unsigned int, unsigned int> > &roPrimeFactors) {
	roPrimeFactors.clear();

	unsigned int nLimit = static_cast<int>(sqrt(static_cast<float>(nNumber))) + 1;
	for (size_t i = 0; i < roPrimes.size() && roPrimes[i] <= nLimit; i++) {
		if (!(nNumber % roPrimes[i])) {
			std::pair<unsigned int, unsigned int> oFactor(roPrimes[i], 0);

			do {
				oFactor.second++;
				nNumber /= roPrimes[i];
			} while (!(nNumber % roPrimes[i]));

			nLimit = static_cast<int>(sqrt(static_cast<float>(nNumber))) + 1;
			roPrimeFactors.push_back(oFactor);
		}
	}

	if (nNumber != 1)
		roPrimeFactors.push_back(std::pair<unsigned int, unsigned int>(nNumber, 1));
}

unsigned int Sol(unsigned int nStep, unsigned int nK, unsigned int nCurrentNumber, std::vector< std::pair<unsigned int, unsigned int> > &roPrimeFactors) {
	if (nStep == roPrimeFactors.size())
		return nCurrentNumber;

	unsigned int nCurrentCandidate = nCurrentNumber, nSum = 0;
	for (unsigned int nLoopPow = 0; nLoopPow <= roCurrentFactor.second; nLoopPow++, nCurrentCandidate *= roCurrentFactor.first) {
		if (!(nCurrentCandidate % nK))
			break;
		nSum += Sol (nStep + 1, nK, nCurrentCandidate, roPrimeFactors);
	}

	return nSum;
}

int main() {
	const int MAX = 5 * 100000;

	std::vector<unsigned int> oVecnPrimes;
	GenPrimes(oVecnPrimes, static_cast<unsigned int>(std::sqrt(static_cast<float>(MAX))));

	int nNoTestCases;
	for (std::cin >> nNoTestCases; nNoTestCases--; ) {
		unsigned int nN, nK;
		std::cin >> nN >> nK;

		std::vector< std::pair<unsigned int, unsigned int> > oVecoFactors;
		Factorize(nN, oVecnPrimes, oVecoFactors);

		std::cout << Sol(0, nK, 1, oVecoFactors) << std::endl;
	}

	return 0;
}
