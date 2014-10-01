/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11287 - Pseudoprime Numbers                                      */


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void GenPrimes(vector<int> &roPrimes, int nTo) {
	roPrimes.push_back(2); roPrimes.push_back(3); roPrimes.push_back(5); roPrimes.push_back(7); roPrimes.push_back(11);
  
	for (int i = 13; i <= nTo; i += 2) {
		int lim = static_cast<int>(sqrt(static_cast<float>(i)));
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

bool IsPrime(int nNumber, vector<int> &roPrimesList) {
	for (vector<int>::const_iterator oIt = roPrimesList.begin(); oIt != roPrimesList.end() && *oIt  * *oIt <= nNumber; oIt++)
		if (!(nNumber % *oIt))
			return false;

	return true;
}

int main() {
	const int MAX = 1000000000;

	vector<int> oPrimes;
	GenPrimes(oPrimes, static_cast<int>(sqrt(static_cast<float>(MAX)) + 1));

	for (int nA, nP; (cin >> nP >> nA), nA && nP; ) {
		long long llResult = 1, llPower = nA;
		int nExponent = nP;
		while (nExponent) {
			if (nExponent & 0x1)
				llResult = (llResult * llPower) % nP;
			llPower = (llPower * llPower) % nP;
			nExponent >>= 1;
		}

		if (llResult == nA && !IsPrime(nP, oPrimes)) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}

	return 0;
}
