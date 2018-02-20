/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13108 - Juanma and the Drinking Fountains                        */


/* From: http://mathworld.wolfram.com/CircleDivisionbyChords.html */

#include <iostream>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nN;
		cin >> nN;
		cout << (static_cast<long long>(nN) * (nN * nN * nN) - 6 * nN * nN * nN + 23 * nN * nN - 18 * nN) / 24 + 1 << endl;
	}

	return 0;
}