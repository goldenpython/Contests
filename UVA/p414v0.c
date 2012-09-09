/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 414 - Machined Surfaces                                          */


#include <stdio.h>

#define	MAX_CHARS_IN_LINE	25
#define MAX_LINE_LEN		32

#ifdef ONLINE_JUDGE
	#define BLANK_CHAR			' '
#else
	#define BLANK_CHAR			'B'
#endif

int main() {
	int nN, i, nMinBlanks, nTotalBlanks, nLineBlanks;
	char *psz, *pszEnd, szLine[MAX_LINE_LEN];

	for (sscanf(gets(szLine), "%d", &nN); nN; sscanf(gets(szLine), "%d", &nN)) {
		nMinBlanks = MAX_CHARS_IN_LINE;
		nTotalBlanks = 0;

		for (i = 0; i < nN; i++) {
			nLineBlanks = 0;

			for (psz = gets(szLine), pszEnd = psz + MAX_CHARS_IN_LINE; psz < pszEnd; psz++)
				if (*psz == BLANK_CHAR)					
					nLineBlanks++;

			if (nLineBlanks < nMinBlanks)
				nMinBlanks = nLineBlanks;

			nTotalBlanks += nLineBlanks;
		}

		printf("%d\n", nTotalBlanks - nN * nMinBlanks);

	}
	return 0;
}
