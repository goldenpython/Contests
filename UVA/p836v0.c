/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 836 - Largest Submatrix                                          */


#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN	100
#define MAX_MATR_DIM	30

int main() {
	char szLine[MAX_LINE_LEN];
	int nrcases, n, i, j, k, l, x, max;
	char matrix[MAX_MATR_DIM][MAX_MATR_DIM];
	int sum[MAX_MATR_DIM][MAX_MATR_DIM];

	/* freopen("input/836.txt", "rt", stdin); */

	gets(szLine);
	sscanf(szLine, "%d", &nrcases);

	for ( ; nrcases; nrcases--) {
		gets(szLine);

		gets(matrix[0]);
		n = strlen(matrix[0]);
		for (i = 1; i < n; i++)
			gets(matrix[i]);

		for (i = 0; i <= n; i++) 
			sum[i][0] = sum[0][i] = 0;

		for (i = 1; i <= n; i++) 			
			for (j = 1; j <= n; j++)
				sum[i][j] = matrix[i - 1][j - 1] - '0' + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

		max = 0;
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n; j++)
				for (k = i + 1; k <= n; k++)
					for (l = j + 1; l <= n; l++) {
						x = sum[k][l] - sum[k][j] - sum[i][l] + sum[i][j];
						if (x == (k - i) * (l - j))
							if (max < x)
								max = x;
					}

		if (nrcases > 1)
			printf("%d\n\n", max);
		else
			printf("%d\n", max);
	}

	return 0;
}
