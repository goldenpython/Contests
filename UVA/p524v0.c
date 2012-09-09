/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 524 - Prime Ring Problem                                         */


#include <stdio.h>
#include <string.h>

#define MAX		17

int g_arrnIsPrime[MAX * 3];
int g_arrnNeighbours[MAX][MAX];

int g_nN;
int g_arrnSol[MAX];
int g_arrnSolIsUsed[MAX];

void GenArrays() {
	int nI, nJ;

	g_arrnIsPrime[2] = 1;
	g_arrnIsPrime[3] = 1;
	g_arrnIsPrime[5] = 1;
	g_arrnIsPrime[7] = 1;
	g_arrnIsPrime[11] = 1;
	g_arrnIsPrime[13] = 1;
	g_arrnIsPrime[17] = 1;
	g_arrnIsPrime[19] = 1;
	g_arrnIsPrime[23] = 1;
	g_arrnIsPrime[29] = 1;
	g_arrnIsPrime[31] = 1;
	g_arrnIsPrime[37] = 1;
	g_arrnIsPrime[41] = 1;

	for (nI = 1; nI < MAX; nI++) {
		for (nJ = 1; nJ < MAX; nJ++)
			if (nI != nJ && g_arrnIsPrime[nI + nJ])
				g_arrnNeighbours[nI][++g_arrnNeighbours[nI][0]] = nJ;
		g_arrnNeighbours[nI][++g_arrnNeighbours[nI][0]] = MAX;
	}
}

void BK(int nStep) {
	int nLoop, nPrev;

	if (nStep == g_nN && g_arrnIsPrime[g_arrnSol[0] + g_arrnSol[g_nN - 1]]) {
		printf("1");
		for (nLoop = 1; nLoop < g_nN; nLoop++)
			printf(" %d", g_arrnSol[nLoop]);
		printf("\n");
		return;
	}

	nPrev = g_arrnSol[nStep - 1];
	for (nLoop = 1; g_arrnNeighbours[nPrev][nLoop] <= g_nN; nLoop++) {
		if (!g_arrnSolIsUsed[g_arrnNeighbours[nPrev][nLoop]]) {
			g_arrnSolIsUsed[g_arrnNeighbours[nPrev][nLoop]] = 1;
			g_arrnSol[nStep] = g_arrnNeighbours[nPrev][nLoop];
			BK(nStep + 1);
			g_arrnSolIsUsed[g_arrnNeighbours[nPrev][nLoop]] = 0;
		}
	}
}

int main() {
	int nCase = 1;

	GenArrays();

	while (scanf("%d", &g_nN) == 1) {
		memset(g_arrnSolIsUsed, 0, sizeof(g_arrnSolIsUsed));

		g_arrnSol[0] = g_arrnSolIsUsed[1] = 1;
		if (nCase > 1)
			printf("\n");
		printf("Case %d:\n", nCase++);
		BK(1);
	}

	return 0;
}
