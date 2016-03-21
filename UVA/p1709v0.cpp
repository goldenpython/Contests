/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1709 - Amalgamated Artichokes                                    */


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int nP, nA, nB, nC, nD, nN;
	while (cin >> nP >> nA >> nB >> nC >> nD >> nN) {
		double fSol = 0;
		double fMax = (sin(nA + nB) + cos(nC + nD) + 2);
		for (int nLoop = 2; nLoop <= nN; nLoop++) {
			double fPrice = (sin(nA * nLoop + nB) + cos(nC * nLoop + nD) + 2);
			if (fMax - fPrice > fSol)
				fSol = fMax - fPrice;
			else if (fPrice > fMax)
				fMax = fPrice;
		}

		cout << setprecision(6) << fixed << nP * fSol << endl;
	}

	return 0;
}