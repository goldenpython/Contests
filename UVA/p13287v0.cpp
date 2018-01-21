/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13287 - Shattered Cake                                           */


#include <iostream>

using namespace std;

int main() {
	int nW;

	while (cin >> nW) {
		int nN, nTotalArea = 0;
		for (cin >> nN; nN--; ) {
			int nPieceW, nPieceH;
			cin >> nPieceW >> nPieceH;
			nTotalArea += nPieceW * nPieceH;
		}

		cout << nTotalArea / nW << endl;
	}

	return 0;
}