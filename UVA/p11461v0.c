/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11461 - Square Numbers                                           */


#include <stdio.h>

#define MAX		330
#define LIM		100000

int arrSquares[MAX];

int BinSearch(int iN, int iLo, int iHi) {
	int i = iLo, j = iHi, m;

	while (i <= j) {
		m = (i + j) >> 1;

		if (arrSquares[m] < iN)
			i = m + 1;
		else
			j = m - 1;
	}

	return i;
}

int main() {
	int iA, iB, iN, iIndex1, iIndex2;

	for (iN = 0; iN * iN < LIM; iN++)
		arrSquares[iN] = iN * iN;
	iN--;

	while (scanf("%d %d", &iA, &iB), iA || iB) {
		iIndex1 = BinSearch(iA, 0, iN);
		iIndex2 = BinSearch(iB, 0, iN);
		printf("%d\n", iIndex2 - iIndex1 + (arrSquares[iIndex2] == iB ? 1 : 0));
	}

	return 0;
}
