/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 200 - Rare Order                                                 */


#include <stdio.h>

#define LIMIT	('Z' - 'A' + 1)

int g[LIMIT][LIMIT];
int degin[LIMIT], degout[LIMIT], used[LIMIT];

int main() {
	int i, j;
	int qhead, qtail, queue[LIMIT];
	char *aux, *p1, *p2, *ps1, *ps2, szLine1[64], szLine2[64];

	p1 = szLine1; p2 = szLine2;

	/* freopen("input/200.txt", "rt", stdin); */

	gets(p1);
	while (gets(p2), *p2 != '#') {
		for (ps1 = p1, ps2 = p2; *ps1 == *ps2 && *ps1 && *ps2; ps1++, ps2++)
			;

		if (*ps1 && *ps2) {
			g[*ps1 - 'A'][*ps2 - 'A'] = 1;
			used[*ps1 - 'A'] = used[*ps2 - 'A'] = 1;
		}

		aux = p1;
		p1 = p2;
		p2 = aux;
	}

	for (i = 0; i < LIMIT; i++)
		for (j = 0; j < LIMIT; j++)
			if (g[i][j]) {
				degin[j]++;
				degout[i]++;
			}

	qhead = 0; qtail = -1;
	for (i = 0; i < LIMIT; i++)
		if (used[i]) {
			if (degin[i] == 0) {
				queue[++qtail] = i;
			}
		}

	while (qhead <= qtail) {
		for (i = 0; i < LIMIT; i++)
			if (g[queue[qhead]][i]) {
				if (!--degin[i])				
					queue[++qtail] = i;
			}
		qhead++;
	}

	for (i = 0; i <= qtail; i++)
		printf("%c", queue[i] + 'A');
	printf("\n");

	return 0;
}
