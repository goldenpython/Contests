/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 679 - Dropping Balls                                             */


#include <iostream>

using namespace std;

int ReverseBits(int nN, int nNoBits) {
	int nRetValue = 0;
	while (nNoBits--) {
		nRetValue = (nRetValue << 1) | (nN & 0x1);
		nN >>= 1;
	}
	return nRetValue;
}

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nD, nI;
		cin >> nD >> nI;
		cout << ((1 << (nD - 1)) | ReverseBits(nI - 1, nD - 1)) << endl;
	}

	return 0;
}

/*
		10000		4 1
		11000		4 2
		10100		4 3
		11100		4 4
		10010		4 5
		11010		4 6
		10110		4 7
		11110		4 8
		10001		4 9
		11001		4 10
		10101		4 11
		11101		4 12
		10011		4 13
		11011		4 14
		10111		4 15
		11111		4 16
*/