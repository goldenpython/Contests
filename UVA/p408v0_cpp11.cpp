/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 408 - Uniform Generator                                          */


#include <iostream>
#include <cmath>
#include <iomanip>

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
	// https://en.wikipedia.org/wiki/Linear_congruential_generator
	for (int nStep, nMod; cin >> nStep >> nMod; )
		cout << setw(10) << right << nStep << setw(10) << right << nMod << "    " << (gcd(nMod, nStep) == 1 ? "Good" : "Bad") << " Choice" << endl << endl;

	return 0;
}