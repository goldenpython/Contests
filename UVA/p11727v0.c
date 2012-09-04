/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

#include <stdio.h>

#define SWAP(a, b, c)	{ c = a; a = b; b = c; }
int main() {
	int nNoCases, nCaseLoop, nSal1, nSal2, nSal3, nAux;

	scanf("%d", &nNoCases);
	for (nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		scanf("%d %d %d", &nSal1, &nSal2, &nSal3);

		if (nSal1 > nSal2)
			SWAP(nSal1, nSal2, nAux);
		if (nSal1 > nSal3)
			SWAP(nSal1, nSal3, nAux);
		if (nSal2 > nSal3)
			SWAP(nSal2, nSal3, nAux);

		printf("Case %d: %d\n", nCaseLoop, nSal2);
	}

	return 0;
}
