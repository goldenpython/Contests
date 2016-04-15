/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13035 - Another Combination Problem                              */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;

	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nNoBoxes;
		cin >> nNoBoxes;

		const int MODULO = 1000000007;
		long long llSol = 1;
		for (int nLoop = 0; nLoop <= 2; nLoop++) {
			int nCurrent = nNoBoxes + nLoop;
			if (!(nCurrent % 3))
				nCurrent /= 3;
			llSol = (llSol * nCurrent) % MODULO;
		}

		cout << "Case " << nCaseLoop << ": " << llSol << endl;
	}

	return 0;
}