/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13161 - Candle Box                                               */

#include <iostream>
#include <cmath>

int QuadraticEquationPositiveRoot(int nA, int nB, int nC) {
	int nDelta = nB * nB - 4 * nA * nC;
	return (-nB + static_cast<int>(std::sqrt(static_cast<float>(nDelta)))) / 2 / nA;
}

int main() {
	int nD, nR, nT;
	while (std::cin >> nD >> nR >> nT) {
		int nAgeRita = QuadraticEquationPositiveRoot(2, 2 - 2 * nD, nD * nD - nD - 18 - 2 * (nT + nR));
		int nCandlesRita = (nAgeRita + 4) * (nAgeRita - 3) / 2;
		std::cout << nR - nCandlesRita << std::endl;
	}
	
	return 0;
}