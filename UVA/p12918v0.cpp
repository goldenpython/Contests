/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12918 - Lucky Thief                                              */

#include <iostream>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nN, nM;
		cin >> nN >> nM;
		cout << static_cast<long long>(nN) * (2 * nM - nN - 1) / 2 << endl;
	}

	return 0;
}