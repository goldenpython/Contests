/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12416 - Excessive Space Remover                                  */


#include <stdio.h>

#define MAX_LINE_LEN	(1024 * 1024)

char g_szLine[MAX_LINE_LEN];

int main() {
	char *psz;
	int nMaxSpaces, nCurrentSpaces, nSol;

	while (psz = gets(g_szLine)) {
		nMaxSpaces = -1;
		for (psz = g_szLine, nCurrentSpaces = 0; *psz; psz++) {
			if (*psz == ' ') {
				nCurrentSpaces++;
			} else {
				if (nCurrentSpaces > nMaxSpaces)
					nMaxSpaces = nCurrentSpaces;
				nCurrentSpaces = 0;
			}
		}

		if (nCurrentSpaces > nMaxSpaces)
			nMaxSpaces = nCurrentSpaces;

		for (nSol = 0; nMaxSpaces > 1; nSol++, nMaxSpaces = (nMaxSpaces >> 1) + (nMaxSpaces & 0x1))
			;

		printf("%d\n", nSol);
	}

	return 0;
}
