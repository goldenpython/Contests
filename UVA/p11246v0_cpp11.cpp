/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11246 - K-Multiple Free set                                      */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nN, nK;
		cin >> nN >> nK;

		int nSol = nN;
		for (int nLoopExponent = 1, nCurrentPow = nK; nN / nCurrentPow >= 1; nLoopExponent++, nCurrentPow *= nK)
			nSol += (1 - 2 * (nLoopExponent % 2)) * nN / nCurrentPow;

		cout << nSol << endl;
	}
	return 0;
}

/*
	Eliminate multiples of k, keep k^2 multiples, eliminate multiples of k^3 and so on...
*/