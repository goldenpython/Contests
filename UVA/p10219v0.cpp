/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10219 - Find the ways !                                          */


#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Stirling's formula
// http://www.johndcook.com/blog/2010/08/16/how-to-compute-log-factorial/
double log10Factorial(int nN) {
	if (nN >= 256) {
		double fN = nN + 1;
		double fResult = (fN - 0.5f) * log(fN) - fN + 0.5f * log(2 * 3.141592653589793238463f) + 1.0f / 12 / fN;
		return fResult / log(10.0f);
	} else {
		static double arrfLogFactorials[256];
		static bool bInitialized = false;

		if (!bInitialized) {
			for (int nLoop = 1; nLoop < 256; nLoop++)
				arrfLogFactorials[nLoop] = arrfLogFactorials[nLoop - 1] + log10(static_cast<double>(nLoop));
		}

		return arrfLogFactorials[nN];
	}
}

int main() {
	long long nN, nK;
	string oLine;
	while (cin >> nN >> nK) {
		double fSol = 0;
		fSol = log10Factorial(nN) - log10Factorial(nK) - log10Factorial(nN - nK);
		cout << static_cast<int>(floor(fSol) + 1) << endl;
	}

	return 0;
}
