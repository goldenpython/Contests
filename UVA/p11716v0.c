/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_LINE_LEN	12000

int main() {
	int nNoLines, nLineLen, nSquareSize, i;
	char *psz, *pszLimit, szLine[MAX_LINE_LEN];

	for (gets(szLine), sscanf(szLine, "%d", &nNoLines); nNoLines; nNoLines--) {
		gets(szLine);

		nLineLen = strlen(szLine);
		nSquareSize = (int) sqrt(nLineLen);

		if (nSquareSize * nSquareSize != nLineLen) {
			printf("INVALID\n");
			continue;
		}

		pszLimit = szLine + nLineLen;
		for (i = 0; i < nSquareSize; i++)
			for (psz = szLine + i; psz < pszLimit; psz += nSquareSize)
				printf("%c", *psz);

		printf("\n");
	}

	return 0;
}
