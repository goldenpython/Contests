/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 439 - Knight Moves                                               */


#include <stdio.h>

int main() {
	char szLine[64];
	int r1, c1, r2, c2, index, i, j, k, g[64][64];
	const int dr[] = {-1, +1, +2, +2, +1, -1, -2, -2};
	const int dc[] = {-2, -2, -1, +1, +2, +2, +1, -1};

	for (i = 0; i < 64; i++)
		for (j = 0; j < 64; j++)
			g[i][j] = 0xFFFF;


	for (i = 0; i < 64; i++) {
		g[i][i] = 0;

		r1 = i >> 3; c1 = i & 0x7;

		for (j = 0; j < sizeof(dr) / sizeof(int); j++) {
			r2 = r1 + dr[j]; c2 = c1 + dc[j];

			if (r2 >= 0 && r2 < 8 && c2 >= 0 && c2 < 8) {
				index = (r2 << 3) + c2;

				g[i][index] = g[index][i] = 1;
			}
		}
	}


	for (k = 0; k < 64; k++)
		for (i = 0; i < 64; i++)
			for (j = 0; j < 64; j++)
				if (g[i][k] + g[k][j] < g[i][j])
					g[i][j] = g[i][k] + g[k][j];


	while (gets(szLine)) {
		i = ((szLine[0] - 'a') << 3) + szLine[1] - '1';
		j = ((szLine[3] - 'a') << 3) + szLine[4] - '1';

		szLine[2] = '\0';
		printf("To get from %s to %s takes %d knight moves.\n", szLine, szLine + 3, g[i][j]);
	}

	return 0;
}
