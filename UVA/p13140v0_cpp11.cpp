/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13140 - Squares, Lists and Digital Sums                          */


#include <iostream>
#include <set>

using namespace std;

int GetSumOfDigits(int nN) {
	int nSum = 0;
	while (nN) {
		nSum += nN % 10;
		nN /= 10;
	}

	return nSum;
}

int main() {
	set<int> oSetSquares;
	for (int nLoop = 1; nLoop <= 64; nLoop++)
		oSetSquares.insert(nLoop * nLoop);

	for (int nLoop = 16, nSeqLen = 0; ; nLoop++) {
		if (oSetSquares.find(GetSumOfDigits(nLoop * nLoop)) != oSetSquares.end()) {
			if (++nSeqLen == 7) {
				while (nSeqLen--)
					cout << nLoop - nSeqLen << " " << (nLoop - nSeqLen) * (nLoop - nSeqLen) << endl;
				break;
			}
		} else {
			nSeqLen = 0;
		}

	}

	return 0;
}