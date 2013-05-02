/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11349 - Symmetric Matrix                                         */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_N		102


int main() {
	int NoCases, CaseLoop, n, i, j;
	char szLine[MAX_N * 15];
	long long matr[MAX_N][MAX_N];


	scanf("%d", &NoCases);

	for (CaseLoop = 1; CaseLoop <= NoCases; CaseLoop++) {
		scanf("%[^0-9]*", szLine);
		scanf("%d", &n);

		bool sim = true;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%lld", &matr[i][j]);

		if (sim) {
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					if (matr[i][j] < 0 || matr[i][j] != matr[n - i - 1][n - j - 1]) {
						i = j = n;
						sim = 0;
						break;
					}
		}

		printf("Test #%d: %s.\n", CaseLoop, sim ? "Symmetric" : "Non-symmetric");
	}

	return 0;
}
