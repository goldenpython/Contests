/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 750 - 8 Queens Chess Problem                                     */



#include <stdio.h>

#define TABLE_SIZE	8

int g_nNoSolutions;
int g_arrnPos[TABLE_SIZE];
int g_arrnSolutions[100][TABLE_SIZE];

int abs(int nVal) {
	return nVal > 0 ? nVal : -nVal;
}

void gen(int nStep) {
	if (nStep == TABLE_SIZE) {
		for (int nLoop = 0; nLoop < TABLE_SIZE; nLoop++)
			g_arrnSolutions[g_nNoSolutions][nLoop] = g_arrnPos[nLoop];
		g_nNoSolutions++;
	} else {
		for (int nLoopCol = 0; nLoopCol < TABLE_SIZE; nLoopCol++) {
			g_arrnPos[nStep] = nLoopCol;

			int nLoop;
			for (nLoop = 0; nLoop < nStep; nLoop++)
				if (g_arrnPos[nLoop] == nLoopCol || abs(g_arrnPos[nLoop] - nLoopCol) == nStep - nLoop)
					break;

			if (nLoop == nStep)
				gen(nStep + 1);
		}
	}
}

int main() {
	gen(0);


	int nNoTestCases;
	scanf("%d", &nNoTestCases);
	for (int nCaseLoop = 0; nCaseLoop < nNoTestCases; nCaseLoop++) {
		if (nCaseLoop)
			printf("\n");
		printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8");

		int nCol, nRow;
		scanf("%d %d", &nCol, &nRow);
		nCol--; nRow--;

		printf("\n");

		int nIndex = 1;
		for (int nSolLoop = 0; nSolLoop < g_nNoSolutions; nSolLoop++) {
			if (g_arrnSolutions[nSolLoop][nRow] == nCol) {
				printf("\n%2d     ", nIndex++);
				for (int nLoop = 0; nLoop < TABLE_SIZE; nLoop++) 
					printf(" %d", g_arrnSolutions[nSolLoop][nLoop] + 1);
			}
		}

		printf("\n");
	}

	return 0;
}