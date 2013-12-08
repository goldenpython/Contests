/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11889 - Benefit                                                  */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


int Power(int nBase, int nExponent) {
	int nResult = 1;
	for ( ; nExponent--; nResult *= nBase)
		;
	return nResult;
}

void GenPrimes(vector<int> &roPrimes, int nTo, int nNoPrimes) {
	roPrimes.reserve(nNoPrimes);
	roPrimes.push_back(2); roPrimes.push_back(3); roPrimes.push_back(5); roPrimes.push_back(7); roPrimes.push_back(11);

	for (int i = 13; i <= nTo; i += 2) {
		int lim = (int)sqrt((double)i);
		int j;
		for (j = 1; roPrimes[j] <= lim; j++)
			if (!(i % roPrimes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			roPrimes.push_back(i);
	}
}

void Factorize(int nNumber, const vector<int> &roPrimes, vector< pair<int, int> > &roPrimeFactors) {
	roPrimeFactors.clear();

	int nLimit = static_cast<int>(sqrt(nNumber)) + 1;
	for (int i = 0; i < roPrimes.size() && roPrimes[i] <= nLimit; i++) {
		if (!(nNumber % roPrimes[i])) {
			pair<int, int> oFactor(roPrimes[i], 0);

			do {
				oFactor.second++;
				nNumber /= roPrimes[i];
			} while (!(nNumber % roPrimes[i]));

			nLimit = static_cast<int>(sqrt(nNumber)) + 1;
			roPrimeFactors.push_back(oFactor);
		}
	}

	if (nNumber != 1)
		roPrimeFactors.push_back(pair<int, int>(nNumber, 1));
}

int main() {
	const int MAX = 10000000;
	const int MAX_PRIME = static_cast<int>(sqrt(MAX) + 1);
	const int MAX_NO_PRIMES = 50;

	vector<int> oPrimes;
	GenPrimes(oPrimes, MAX_PRIME, 10000);

	int nNoCases;
	cin >> nNoCases;

	while (nNoCases--) {
		int nA, nC;
		cin >> nA >> nC;

		if (nC % nA) {
			cout << "NO SOLUTION" << endl;
			continue;
		}

		vector< pair<int, int> > oFactorsA, oFactorsC;
		Factorize(nA, oPrimes, oFactorsA);
		Factorize(nC, oPrimes, oFactorsC);

		oFactorsA.push_back(pair<int, int>(MAX, 0)); oFactorsC.push_back(pair<int, int>(MAX, 0));

		int nB = 1;
		vector< pair<int, int> >::iterator oItA = oFactorsA.begin(), oItC = oFactorsC.begin();
		while (oItA != oFactorsA.end() || oItC != oFactorsC.end()) {
			if (oItA->first == oItC->first) {
				nB *= Power(oItA->first, oItC->second == oItA->second ? 0 : oItC->second);
				oItA++; oItC++;
			} else {
				nB *= Power(oItC->first, oItC->second);
				oItC++;
			}

		}

		cout << nB << endl;
	}

	return 0;
}