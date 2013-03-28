/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 490 - Rotating Sentences                                         */


#include <stdio.h>
#include <string.h>

char szLines[128][128], szLines1[128][128];

int main() {
	int n, i, j, ii, max, len[128];

	/* freopen("input/490.txt", "rt", stdin); */

	max = 0;
	for (n = 0; gets(szLines[n]) && *szLines[n]; n++) {
		len[n] = strlen(szLines[n]);
		if (len[n] > max)
			max = len[n];
	}

	for (i = n - 1; i >= 0; i--) {
		ii = n - i - 1;

		for (j = 0; j < len[i]; j++)
			szLines1[j][ii] = szLines[i][j];
		for (; j < max; j++)
			szLines1[j][ii] = ' ';
	}

	for (i = 0; i < max; i++)
		printf("%s\n", szLines1[i]);



	return 0;
}
