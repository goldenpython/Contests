/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10908 - Largest Square                                           */



#include <stdio.h>

#define MAX_LINE_LEN	128

int main() {
	int nNoCases;
	int nNoColumns, nNoLines, nNoTests, nLineLoop;
	int nCenterColumn, nCenterLine, nSol, nSize, nMaxSize, nLoop;
	char cCenter;
	char szLine[MAX_LINE_LEN];
	char arr2cGrid[MAX_LINE_LEN][MAX_LINE_LEN];

	#ifndef ONLINE_JUDGE
		freopen("input//10908.txt", "rt", stdin);
	#endif // ONLINE_JUDGE

	for (sscanf(gets(szLine), "%d", &nNoCases); nNoCases; nNoCases--) {
		sscanf(gets(szLine), "%d %d %d", &nNoLines, &nNoColumns, &nNoTests);
		for (nLineLoop = 0; nLineLoop < nNoLines; gets(arr2cGrid[nLineLoop++]))
			;

		printf("%d %d %d\n", nNoLines, nNoColumns, nNoTests);
		while (nNoTests--) {
			sscanf(gets(szLine), "%d %d", &nCenterLine, &nCenterColumn);
			cCenter = arr2cGrid[nCenterLine][nCenterColumn];
			nMaxSize = nCenterLine < nCenterColumn ? nCenterLine : nCenterColumn;
			if (nNoColumns - nCenterColumn - 1 < nMaxSize)
				nMaxSize = nNoColumns - nCenterColumn - 1;
			if (nNoLines - nCenterLine - 1 < nMaxSize)
				nMaxSize = nNoLines - nCenterLine - 1;
			for (nSol = 1, nSize = 0; nSize <= nMaxSize; nSol += 2, nSize++) {
				for (nLoop = -nSize; nLoop <= nSize; nLoop++)
					if (	arr2cGrid[nCenterLine + nLoop][nCenterColumn - nSize] != cCenter || 
							arr2cGrid[nCenterLine + nLoop][nCenterColumn + nSize] != cCenter ||
							arr2cGrid[nCenterLine - nSize][nCenterColumn + nLoop] != cCenter ||
							arr2cGrid[nCenterLine + nSize][nCenterColumn + nLoop] != cCenter 
					) {
						nSize = nLoop = nNoColumns + nNoLines + 1; 
						nSol -= 2;
						break;
					}
			}

			printf("%d\n", nSol - 2);
		}
	}

	return 0;
}
