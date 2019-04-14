/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10489 - Boxes of Chocolates                                      */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nN, nB, nK, nCurrentProduct, nNumber, nRes = 0;
		for (cin >> nN >> nB; nB--; ) {
			cin >> nK;
			for (nCurrentProduct = 1; nK--; ) {
				cin >> nNumber;
				(nCurrentProduct *= nNumber) %= nN;
			}
			(nRes += nCurrentProduct) %= nN;
		}

		cout << nRes << endl;
	}
	return 0;
}