/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13148 - A Giveaway                                               */



#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

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

	unsigned int nLim = static_cast<int>(sqrt(static_cast<double>(nTo)));
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

bool IsSpecial(const std::vector<unsigned int> &roPrimes, unsigned int nN) {
	if (nN < 2)
		return true;

	auto oItPrime = roPrimes.cbegin();

	for (; oItPrime < roPrimes.cend() && *oItPrime * *oItPrime <= nN && nN > 1; oItPrime++) {
		int nCurrentPower = 0;
		while (nN % *oItPrime == 0) {
			++nCurrentPower;
			nN /= *oItPrime;
		}

		if (nCurrentPower % 6)
			return false;
	}

	return nN == 1;
}

int main() {
	const int MAX = 100000000;
	std::vector<unsigned int> oVecnPrimes;
	GenPrimes(oVecnPrimes, static_cast<unsigned int>(sqrt(static_cast<double>(MAX))) + 1);

	int nN;
	do {
		std::cin >> nN;
		if (!nN)
			break;

		std::cout << (IsSpecial(oVecnPrimes, nN) ? "Special\n" : "Ordinary\n");
	} while (true);

	return 0;
}