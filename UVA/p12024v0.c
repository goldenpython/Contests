/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>

#define MAX_N	13

int Combinations(int n, int k, int *factorials) {
	return factorials[n] / factorials[k] / factorials[n - k];
}

int main() {
	int nNoCases, nLoop, nLoop2;
	int arrnFactorials[MAX_N];
	int arrnSol[MAX_N];

	arrnFactorials[0] = arrnFactorials[1] = 1;
	for (nLoop = 2; nLoop < MAX_N; nLoop++)
		arrnFactorials[nLoop] = arrnFactorials[nLoop - 1] * nLoop;

	for (nLoop = 2; nLoop < MAX_N; nLoop++) {
		arrnSol[nLoop] = arrnFactorials[nLoop] - 1;
		for (nLoop2 = 2; nLoop2 < nLoop; nLoop2++)
			arrnSol[nLoop] -= arrnSol[nLoop2] * Combinations(nLoop, nLoop - nLoop2, arrnFactorials);
	}


	for (scanf("%d", &nNoCases); nNoCases--; ) {
		scanf("%d", &nLoop);
		printf("%d/%d\n", arrnSol[nLoop], arrnFactorials[nLoop]);
	}

	return 0;
}
