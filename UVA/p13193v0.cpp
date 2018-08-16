/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13193 - Rotations                                                */


#include <iostream>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		unsigned int nN, nBitmap = 0;
		cin >> nN;

		for (int nBitLoop = 1; nBitLoop <= 32; nBitLoop++) {
			nBitmap |= (1 << (nN & 0x1F));
			nN = (nN >> 1) | ((nN & 0x1) << 31);
		}

		cout << (nBitmap == ~0U ? "yes" : "no") << endl;
	}

	return 0;
}