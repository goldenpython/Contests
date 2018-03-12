/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12542 - Prime Substring                                          */


#include <iostream>
#include <vector>
#include <string>
#include <math.h>

template <typename PRIMES_MAP_TYPE = std::vector<bool>>
class GenPrimes {
	public:
		static void GenNonPrimesAsMapUsingSieveOfEratosthenes(PRIMES_MAP_TYPE &roNotPrimeMap, const unsigned int nTo) {
			roNotPrimeMap.resize(nTo + 1);

			unsigned int nLim = (int)sqrt(static_cast<double>(nTo));
			unsigned int nLoop;

			for (nLoop = 4; nLoop <= nTo; nLoop += 2)
				roNotPrimeMap[nLoop] = 1;

			for (nLoop = 3; nLoop <= nLim; nLoop += 2)
				if (!roNotPrimeMap[nLoop])
					for (unsigned int nCurrentPrime = nLoop * nLoop; nCurrentPrime <= nTo; nCurrentPrime += nLoop * 2)
						roNotPrimeMap[nCurrentPrime] = 1;
		}
};

int main() {
	std::vector<unsigned char> oVeccNonPrimesMap;
	const int MAX_PRIME = 100000 + 1;
	GenPrimes<std::vector<unsigned char>>::GenNonPrimesAsMapUsingSieveOfEratosthenes(oVeccNonPrimesMap, MAX_PRIME);

	std::string oLine;
	while (std::getline(std::cin, oLine), oLine != "0") {
		int nSol = 0;
		for (auto oItBegin = oLine.cbegin(); oItBegin != oLine.cend(); ++oItBegin) {
			if (*oItBegin == '0')
				continue;
			for (auto oItEnd = oItBegin; oItEnd != oLine.cend(); ++oItEnd) {
				int nSubStr = std::stoi(std::string(oItBegin, oItEnd + 1));
				if (nSubStr >= MAX_PRIME)
					break;
				if (!oVeccNonPrimesMap[nSubStr] && nSubStr > nSol)
					nSol = nSubStr;
			}
		}

		std::cout << nSol << std::endl;
	}

	return 0;
}