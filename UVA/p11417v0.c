/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11417 - GCD                                                      */



#include <stdio.h>

#define MAX	512


void PrecalcGCDTable(int aaGCDTable[MAX][MAX]) {
	int i, j, r, a, b;

	for (i = 1; i < MAX; i++) {
		aaGCDTable[i][i - 1] = 0;

		for (j = i + 1; j < MAX; j++) {
			b = i; a = j;
			while (b) {
				r = b;
				b = a % b;
				a = r;
			}

			aaGCDTable[i][j] = aaGCDTable[i][j - 1] + a;
		}
	}
}

int main() {
	int iN, iSum, i;
	int aaGCDTable[MAX][MAX];

	PrecalcGCDTable(aaGCDTable);

	while (scanf("%d", &iN), iN) {
		iSum = 0;
		for (i = 1; i < iN; i++)
			iSum += aaGCDTable[i][iN] - aaGCDTable[i][i - 1];

		printf("%d\n", iSum);
	}

	return 0;
}
