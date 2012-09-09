/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11734 - Big Number of Teams will Solve This                      */


#include <stdio.h>

#define	MAX_LINE_LEN	24

int main() {
	int nNoCases, nTestLoop, nPE, nWA;
	char *pszLine1Cursor, *pszLine2Cursor;
	char szLine1[MAX_LINE_LEN], szLine2[MAX_LINE_LEN];

	gets(szLine1); nNoCases = atoi(szLine1);
	for (nTestLoop = 1; nTestLoop <= nNoCases; nTestLoop++) {
		pszLine1Cursor = gets(szLine1);
		pszLine2Cursor = gets(szLine2);
		nPE = nWA = 0;
		for ( ; *pszLine1Cursor; pszLine1Cursor++)
			if (*pszLine1Cursor == *pszLine2Cursor)
				pszLine2Cursor++;
			else if (*pszLine1Cursor == ' ')
				nPE = 1;
			else {
				nWA = 1;
				break;
			}

		if (*pszLine1Cursor != *pszLine2Cursor)
			nWA = 1;

		if (nWA)
			printf("Case %d: Wrong Answer\n", nTestLoop);
		else if (nPE)
			printf("Case %d: Output Format Error\n", nTestLoop);
		else
			printf("Case %d: Yes\n", nTestLoop);
	}

	return 0;
}
