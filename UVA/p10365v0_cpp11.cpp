/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10365 - Blocks                                                   */


#if defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))



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
#if !defined(_MSC_VER) || (_MSC_VER > 1600)
			roFactorization.emplace_back(roPrimes[i], nFactor);
#else
			roFactorization.emplace_back(move(make_pair(roPrimes[i], nFactor)));
#endif // !defined(_MSC_VER) || (_MSC_VER > 1600)
		}
	}

	if (tNumber != 1) {
#if !defined(_MSC_VER) || (_MSC_VER > 1600)
		roFactorization.emplace_back(tNumber, 1);
#else
		roFactorization.emplace_back(move(make_pair(tNumber, 1)));
#endif // !defined(_MSC_VER) || (_MSC_VER > 1600)
	}
}

template <typename T>
void GetDivisors(vector<pair<T, unsigned int>> &roVecFactorization, vector<T> &roVecDivisors) {
	roVecDivisors.push_back(1);
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
	for (const auto &roFactor : roVecFactorization) {
#else
	for (auto oIt = roVecFactorization.cbegin(); oIt != roVecFactorization.cend(); ++oIt) {
		const auto &roFactor(*oIt);
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		T tFactor = roFactor.first;
		vector<T> oVecNewDivisors;
		oVecNewDivisors.reserve(roVecDivisors.size() * roFactor.second);
		for (auto nPower = 1U; nPower <= roFactor.second; nPower++, tFactor *= roFactor.first) {
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
			for (const auto tDivisor : roVecDivisors) {
#else
			for (auto oIt = roVecDivisors.cbegin(); oIt != roVecDivisors.cend(); ++oIt) {
				const auto tDivisor(*oIt);
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
				T tNewDivisor = tFactor * tDivisor;
				oVecNewDivisors.push_back(tNewDivisor);
			}
		}
		roVecDivisors.insert(roVecDivisors.end(), oVecNewDivisors.cbegin(), oVecNewDivisors.cend());
	}
}

template <typename T>
void GetDivisors(T tNumber, const vector<T> &roVecPrimes, vector<T> &roVecDivisors) {
	vector<pair<T, unsigned int>> oVecFactorization;
	Factorize(tNumber, roVecPrimes, oVecFactorization);
	GetDivisors(oVecFactorization, roVecDivisors);
}

int main() {
	const int MAX_PRIME = 1001;
	vector<unsigned int> oVecPrimes;
	GenPrimes(oVecPrimes, MAX_PRIME);

	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		unsigned int nNumber;
		cin >> nNumber;

		vector<unsigned int> oVecDivisors;
		GetDivisors(nNumber, oVecPrimes, oVecDivisors);
		// sort(oVecDivisors.begin(), oVecDivisors.end());

		unsigned int nSol = std::numeric_limits<unsigned int>::max();
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
		for (auto nL : oVecDivisors) {
#else
		for (auto oItL = oVecDivisors.cbegin(); oItL != oVecDivisors.cend(); ++oItL) {
			const auto nL = *oItL;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
			unsigned int nRem = nNumber / nL;
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
			for (auto nW : oVecDivisors) {
#else
			for (auto oItW = oVecDivisors.cbegin(); oItW != oVecDivisors.cend(); ++oItW) {
				const auto nW = *oItW;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
				if (!(nRem % nW)) {
					unsigned int nH = nRem / nW;
					unsigned int nVol = (nL * nW + nL * nH + nW * nH) * 2;
					if (nVol < nSol)
						nSol = nVol;
				}
			}
		}

		cout << nSol << endl;
	}

	return 0;
}