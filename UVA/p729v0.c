/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 729 - The Hamming Distance Problem                               */


#include <stdio.h>
#include <string.h>

#define MAX	17

int g_nN, g_nH;
char g_arrcSol[MAX];

void bk(int nLast, int nRemaining) {
	register int nLoop, nLim;
	if (!nRemaining) {
		printf("%s", g_arrcSol);
	} else  {
		nLim = g_nN - nRemaining;
		for (nLoop = nLast + 1; nLoop <= nLim; nLoop++) {
			g_arrcSol[nLoop] = '0';
			bk(nLoop, nRemaining - 1);
			g_arrcSol[nLoop] = '1';
		}
	}
}

int main() {
	int nNoCases, nLoop;

	for (scanf("%d", &nNoCases); nNoCases--; ) {
		scanf("%d %d", &g_nN, &g_nH);

		memset(g_arrcSol, '1', g_nN);
		g_arrcSol[g_nN] = '\n';
		g_arrcSol[g_nN + 1] = '\0';

		bk(-1, g_nN - g_nH);

		if (nNoCases)
			printf("\n");
	}

	return 0;
}
