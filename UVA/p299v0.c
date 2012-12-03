/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 299 - Train Swapping                                             */

#include <stdio.h>

#define MAX_NUMBERS		52

int main() {
	int nNoCases, nNoNumbers, nLoop1, nLoop2, nTemp, nSol;
	int arrnNumbers[MAX_NUMBERS];

	for (scanf("%d", &nNoCases); nNoCases; nNoCases--) {
		scanf("%d", &nNoNumbers);
		for (nLoop1 = 0; nLoop1 < nNoNumbers; nLoop1++)
			scanf("%d", &arrnNumbers[nLoop1]);

		nSol = 0;
		for (nLoop1 = 1; nLoop1 < nNoNumbers; nLoop1++)
			for (nLoop2 = nLoop1; nLoop2; nLoop2--)
				if (arrnNumbers[nLoop2] < arrnNumbers[nLoop2 - 1]) {
					nTemp = arrnNumbers[nLoop2]; 
					arrnNumbers[nLoop2] = arrnNumbers[nLoop2 - 1]; 
					arrnNumbers[nLoop2 - 1] = nTemp;

					nSol++;
				} else {
					break;
				}

		printf("Optimal train swapping takes %d swaps.\n", nSol);
	}

	return 0;
}