/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 821 - Page Hopping                                               */




#include <stdio.h>
#include <string.h>

#define MAX_NODES	101

int main() {
	int nCaseLoop = 1;
	int arrnMap[MAX_NODES];
	int arr2G[MAX_NODES][MAX_NODES];

	while (1) {
		int nNode1, nNode2;
		int nMax = 0;

		memset(arr2G, 0x1, sizeof(arr2G));
		memset(arrnMap, 0x7C, sizeof(arrnMap));
		while (scanf("%d %d", &nNode1, &nNode2) && nNode1) {
			if (arrnMap[nNode1] > MAX_NODES)
				nNode1 = arrnMap[nNode1] = nMax++;
			else
				nNode1 = arrnMap[nNode1];

			if (arrnMap[nNode2] > MAX_NODES)
				nNode2 = arrnMap[nNode2] = nMax++;
			else
				nNode2 = arrnMap[nNode2];

			arr2G[nNode1][nNode2] = 1;
		}

		if (!nMax)
			break;

		for (int k = 0; k < nMax; k++)
			for (int i = 0; i < nMax; i++)
				for (int j = 0; j < nMax; j++)
					if (arr2G[i][j] > arr2G[i][k] + arr2G[k][j])
						arr2G[i][j] = arr2G[i][k] + arr2G[k][j];
		int nSum = 0;
		for (int i = 0; i < nMax; i++)
			for (int j = 0; j < nMax; j++)
				if (arr2G[i][j] < MAX_NODES && i != j)
					nSum += arr2G[i][j];

		printf("Case %d: average length between pages = %.3lf clicks\n", nCaseLoop++, 1.0 * nSum / (nMax * (nMax - 1)));
	}

	return 0;
}