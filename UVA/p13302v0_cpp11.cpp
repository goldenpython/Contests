/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13302 - Jawbreaking Candy                                        */


#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
T gcd(T a, T b) {
	T r;

	while (b) {
		r = b;
		b = a % b;
		a = r;
	}

	return a;
}

int main() {
	for (int nL, nN, nD; (cin >> nL >> nN >> nD), nL && nN && nD; ) {
		int  nMinA, nMinB;
		double lfMin = nL + 1;
		for (int nB = 1; nB <= nN; nB++) {
			int nA = static_cast<int>(ceil(static_cast<double>(nB) * nD / nL));
			auto lfValue = static_cast<double>(nA) * nL / nB;
			if (lfValue < lfMin) {
				nMinA = nA;
				nMinB = nB;
				lfMin = lfValue;
			}
		}

		auto llNumerator = static_cast<long long>(nL) * nMinA;
		auto llDenominator = static_cast<long long>(nMinB);
		auto llGCD = gcd(llNumerator, llDenominator);
		llNumerator /= llGCD; llDenominator /= llGCD;
		cout << llNumerator << '/' << llDenominator << endl;
	}

	return 0;
}