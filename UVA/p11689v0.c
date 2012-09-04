/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>

int main() {
	int nNoCases, nTestLoop;
	int nE, nF, nC, nDiv, nSol;

	scanf("%d", &nNoCases);
	for (nTestLoop = 0; nTestLoop < nNoCases; nTestLoop++) {
		scanf("%d%d%d", &nE, &nF, &nC);

		nSol = 0;
		nE += nF;
		while (nE >= nC) {
			nDiv = nE / nC;
			nSol += nDiv;
			nE = nDiv + (nE % nC);
		}

		printf("%d\n", nSol);
	}

	return 0;
}
