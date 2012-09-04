/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10405 - Longest Common Subsequence                               */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L		1024

#define MAX(a, b)	((a) > (b) ? (a) : (b))

int sol[MAX_L][MAX_L];

int main() {
	int l1, l2, i, j;
	char sz1[MAX_L], sz2[MAX_L];

	/* freopen("input/10405.txt", "rt", stdin); */

	while (gets(sz1) && gets(sz2)) {
		l1 = strlen(sz1); l2 = strlen(sz2);

		for (i = 0; i <= l1; i++)
			sol[i][0] = 0;

		for (i = 0; i <= l2; i++)
			sol[0][i] = 0;

		for (i = 0; i < l1; i++)
			for (j = 0; j < l2; j++)
				if (sz1[i] == sz2[j]) {
					sol[i + 1][j + 1] = sol[i][j] + 1;
				} else {
					sol[i + 1][j + 1] = MAX(sol[i + 1][j], sol[i][j + 1]);
				}

		printf("%d\n", sol[l1][l2]);
	}

	return 0;
}
