/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11173 - Grey Codes                                               */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nN, nK, nAnswer = 0;
		cin >> nN >> nK;
		for (int nDigitLoop = 0; nDigitLoop < nN; nDigitLoop++) {
			int nBit = ((nK + (1 << nDigitLoop)) >> (1 + nDigitLoop)) & 0x1;
			nAnswer |= nBit << nDigitLoop;
		}

		cout << nAnswer << endl;
	}

	return 0;
}