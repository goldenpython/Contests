/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10170 - The Hotel with Infinite Rooms                            */


#include <iostream>
#include <cmath>

using namespace std;

template <typename TYPE_COEFF, typename TYPE_SQRT, typename TYPE_RETURN>
TYPE_RETURN QuadraticEquationPositiveRoot(TYPE_COEFF A, TYPE_COEFF B, TYPE_COEFF C) {
	TYPE_COEFF Delta = B * B - 4 * A * C;
	return static_cast<TYPE_RETURN>((-B + std::sqrt(static_cast<TYPE_SQRT>(Delta))) / 2 / A);
}

int main() {
	int nS;
	for (long long llD; cin >> nS >> llD; ) {
		auto nB = 2 * nS - 1;
		auto nSol = QuadraticEquationPositiveRoot<long long, double, int>(1, nB, -(llD - 1) * 2);
		cout << nS + nSol << endl; 
	}

	return 0;
}