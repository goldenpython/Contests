/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11565 - Simple Equations                                         */



#if defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))




#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <functional>

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
			roFactorization.emplace_back(make_pair(roPrimes[i], nFactor));
		}
	}

	if (tNumber != 1)
		roFactorization.emplace_back(make_pair(tNumber, 1));
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

using namespace std;

int main() {
	vector<unsigned int> oVecnPrimes;
	GenPrimes(oVecnPrimes, 10001);

	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nA, nB, nC;
		cin >> nA >> nB >> nC;

		vector<unsigned int> oVecnDivisors;
		GetDivisors<unsigned int>(nB, oVecnPrimes, oVecnDivisors);

		vector<int> oVecnDivisorsPosAndNeg(oVecnDivisors.cbegin(), oVecnDivisors.cend());
		transform(oVecnDivisorsPosAndNeg.cbegin(), oVecnDivisorsPosAndNeg.cend(), oVecnDivisorsPosAndNeg.begin(), negate<int>());
		oVecnDivisorsPosAndNeg.insert(oVecnDivisorsPosAndNeg.end(), oVecnDivisors.cbegin(), oVecnDivisors.cend());
		sort(oVecnDivisorsPosAndNeg.begin(), oVecnDivisorsPosAndNeg.end());

		int nSolX, nSolY, nSolZ;
		bool bSolFound = false;
		for (auto oItX = oVecnDivisorsPosAndNeg.cbegin(); oItX != oVecnDivisorsPosAndNeg.cend() && !bSolFound; ++oItX) {
			const int nX = *oItX, nXPow2 = nX * nX;
			if (nXPow2 > nC)
				continue;

			for (auto oItY = next(oItX); oItY != oVecnDivisorsPosAndNeg.cend(); ++oItY) {
				const int nY = *oItY, nYPow2 = nY * nY;
				if (nXPow2 + nYPow2 > nC)
					continue;

				int nZ = nA - nX - nY;
				if (nZ <= nY)
					continue;

				if (nX * nY * nZ == nB && nXPow2 + nYPow2 + nZ * nZ == nC) {
					nSolX = nX, nSolY = nY, nSolZ = nZ;
					bSolFound = true;
					break;
				}
			}
		}

		if (!bSolFound)
			cout << "No solution." << endl;
		else
			cout << nSolX << " " << nSolY << " " << nSolZ << endl;
	}

	return 0;
}