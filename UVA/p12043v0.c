/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>
#include <math.h>

#define MAX	100001

int g_arrnG[MAX], g_arrnH[MAX];

void Precalc() {
	int nLoop1, nLoop2, nLim, nDiv;

	g_arrnG[1] = g_arrnH[1] = 1;

	for (nLoop1 = 2; nLoop1 < MAX; nLoop1++) {
		g_arrnG[nLoop1] = 2;
		g_arrnH[nLoop1] = nLoop1 + 1;

		nLim = (int)sqrt(nLoop1);
		for (nLoop2 = 2; nLoop2 <= nLim; nLoop2++)
			if (nLoop1 % nLoop2 == 0) {
				nDiv = nLoop1 / nLoop2;

				if (nLoop2 != nDiv) {
					g_arrnG[nLoop1] += 2;
					g_arrnH[nLoop1] += nLoop2 + nDiv;
				} else {
					g_arrnG[nLoop1]++;
					g_arrnH[nLoop1] += nLoop2;
				}
			}
			

	}

}

int main() {
	int nA, nB, nK, nLoop, nSolG, nNoCases;
	long long llnSolH;

	Precalc();

	for (scanf("%d", &nNoCases); nNoCases--; ) {
		scanf("%d %d %d", &nA, &nB, &nK);
		nSolG = llnSolH = 0;
		if (nA % nK)
			nA += nK - (nA % nK);
		for (nLoop = nA; nLoop <= nB; nLoop += nK)
			nSolG += g_arrnG[nLoop], llnSolH += g_arrnH[nLoop];

		printf("%d %lld\n", nSolG, llnSolH);
	}

	return 0;
}
