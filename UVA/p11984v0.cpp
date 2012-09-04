/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>

int main() {
	int nNoCases, nLoop;
	int nC, nF;
	double fSol;

	scanf("%d", &nNoCases);
	for (nLoop = 1; nLoop <= nNoCases; nLoop++) {
		scanf("%d %d", &nC, &nF);
		fSol = 5.0 * nF / 9 + nC;
		printf("Case %d: %.2f\n", nLoop, fSol);
	}

	return 0;
}
