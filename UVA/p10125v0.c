/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10125 - Sumsets                                                  */


#include <stdio.h>

#define MAX_NUMBERS	1024


int *g_pSortPointer;

void qsort(int lo, int hi) {
	int i = lo, j = hi;
	int mid = g_pSortPointer[(i + j) >> 1];

	while (i <= j) {
		while (g_pSortPointer[i] < mid)
			i++;

		while (g_pSortPointer[j] > mid)
			j--;

		if (i <= j) {
			int aux = g_pSortPointer[i];
			g_pSortPointer[i] = g_pSortPointer[j];
			g_pSortPointer[j] = aux;

			i++; j--;
		}
	}

	if (i < hi)
		qsort(i, hi);

	if (j > lo)
		qsort(lo, j);
}

int BinSearch(int *pNumbers, int iLo, int iHi, int iN) {
	int i = iLo, j = iHi, m;

	while (i <= j) {
		m = (i + j) >> 1;

		if (pNumbers[m] < iN)
			i = m + 1;
		else
			j = m - 1;
	}

	return i;
}



int main() {
	int nN;
	int arrnNumbers[MAX_NUMBERS];
	int nLoop1, nLoop2, nLoop3, nSum, nSol, nIndex;

	while (scanf("%d", &nN), nN) {
		for (nLoop1 = 0; nLoop1 < nN; nLoop1++) 
			scanf("%d", &arrnNumbers[nLoop1]);

		g_pSortPointer = arrnNumbers;
		qsort(0, nN - 1);

		nSol = -1;
		for (nLoop1 = nN - 1; nLoop1 >= 0; nLoop1--) {
			for (nLoop2 = nN - 1; nLoop2 >= 0; nLoop2--) {
				if (nLoop1 != nLoop2) {
					for (nLoop3 = nLoop2 - 1; nLoop3 >= 0; nLoop3--) {
						nSum = arrnNumbers[nLoop1] - arrnNumbers[nLoop2] - arrnNumbers[nLoop3];
						nIndex = BinSearch(arrnNumbers, 0, nN - 1, nSum);
						if (arrnNumbers[nIndex] == nSum && nIndex < nLoop3 && nIndex >= 0) {
							nSol = nLoop1;
							nLoop3 = nLoop2 = nLoop1 = 0;
						}
					}
				}
			}
		}

		if (nSol == -1)
			printf("no solution\n");
		else
			printf("%d\n", arrnNumbers[nSol]);
	}
	
	return 0;
}
