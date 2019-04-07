/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13194 - DPA Numbers II                                           */


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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
#if !defined(_MSC_VER) || (_MSC_VER > 1600)
			roFactorization.emplace_back(roPrimes[i], nFactor);
#else
			roFactorization.emplace_back(move(make_pair(roPrimes[i], nFactor)));
#endif // !defined(_MSC_VER) || (_MSC_VER > 1600)
		}
	}

	if (nNumber != 1) {
#if !defined(_MSC_VER) || (_MSC_VER > 1600)
		roFactorization.emplace_back(nNumber, 1);
#else
			roFactorization.emplace_back(move(make_pair(nNumber, 1)));
#endif // !defined(_MSC_VER) || (_MSC_VER > 1600)
	}
}

int main() {
	const int MAX_PRIME = 1000000;
	vector<unsigned int> oVecPrimes;
	GenPrimes(oVecPrimes, MAX_PRIME);

	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		unsigned long long llNumber;
		cin >> llNumber;

		vector<pair<unsigned long long, unsigned int>> oVecFactorization;
		Factorize(llNumber, oVecPrimes, oVecFactorization);

		vector<unsigned long long> oVecDivisors(1, 1);
		unsigned long long llSumDivisors = 1;
#if !defined(_MSC_VER) || (_MSC_VER > 1600)
		for (const auto &roFactor : oVecFactorization) {
#else
		for (auto oItFactor = oVecFactorization.cbegin(); oItFactor != oVecFactorization.cend(); ++oItFactor) {
			auto &roFactor = *oItFactor;
#endif // !defined(_MSC_VER) || (_MSC_VER > 1600)
			unsigned long long llFactor = roFactor.first;
			vector<unsigned long long> oVecNewDivisors;
			oVecNewDivisors.reserve(oVecDivisors.size() * roFactor.second);
			for (auto nPower = 1U; nPower <= roFactor.second; nPower++, llFactor *= roFactor.first) {
#if !defined(_MSC_VER) || (_MSC_VER > 1600)
				for (const unsigned long long llDivisor : oVecDivisors) {
#else
				for (auto oItDivisor = oVecDivisors.cbegin(); oItDivisor != oVecDivisors.cend(); ++oItDivisor) {
					auto llDivisor = *oItDivisor;
#endif // !defined(_MSC_VER) || (_MSC_VER > 1600)
					unsigned long long llNewDivisor = llFactor * llDivisor;
					oVecNewDivisors.push_back(llNewDivisor);
					llSumDivisors += llNewDivisor;
				}
			}
			oVecDivisors.insert(oVecDivisors.end(), oVecNewDivisors.cbegin(), oVecNewDivisors.cend());
		}

		llSumDivisors -= llNumber;
		if (llSumDivisors < llNumber)
			cout << "deficient\n";
		else if (llSumDivisors == llNumber)
			cout << "perfect\n";
		else
			cout << "abundant\n";
	}

	return 0;
}