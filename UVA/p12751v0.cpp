/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12751 - An Interesting Game                                      */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nN, nK, nX;
		cin >> nN >> nK >> nX;
		cout << "Case " << nCaseLoop << ": " << ((1 + nN) * nN - (nX + nX + nK - 1) * nK) / 2 << endl;
	}

	return 0;
}