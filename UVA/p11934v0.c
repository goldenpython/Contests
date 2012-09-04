/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>

int main() {
	int nA, nB, nC, nD, nL;
	int nX, nSol, nVal, nLim;

	while (scanf("%d %d %d %d %d", &nA, &nB, &nC, &nD, &nL), nD) {
		if (nA) {
			for (nX = nSol = 0; nX <= nL; nX++) {
				nVal = nX * (nA * nX + nB) + nC;
				if (!(nVal % nD))
					nSol++;
			}
		} else {
			for (nX = nSol = 0, nVal = nC; nX <= nL; nX++) {
				nVal += nB;
				if (!(nVal % nD))
					nSol++;
			}
		}
		printf("%d\n", nSol);
	}

	return 0;
}
