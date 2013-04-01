/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10010 - Where's Waldorf?                                         */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM				54

#define MAX_LINE_LEN		256


int g_nNoRows, g_nNoColumns;

char g_arrszMatrix[MAX_DIM][MAX_DIM];

int g_nSearchedWordLen;
char g_szSearchedWord[MAX_LINE_LEN];

/*
int FindWord(int nStep, int nPrevRow, int nPrevColumn) {
	int nLoop, nRow, nColumn, nFound = 0;

	if (nStep == g_nSearchedWordLen) {
		return 1;
	}

	for (nLoop = 0; nLoop < sizeof(g_arrDrow) / sizeof(g_arrDrow[0]); nLoop++) {
		nRow = nPrevRow + g_arrDrow[nLoop];
		nColumn = nPrevColumn + g_arrDcolumn[nLoop];

		if (nRow >= 0 && nRow < g_nNoRows && nColumn >= 0 && nColumn < g_nNoColumns && g_arrszMatrix[nRow][nColumn] == g_szSearchedWord[nStep]) {
			if (FindWord(nStep + 1, nRow, nColumn)) {
				nFound = 1;
				break;
			}
		}			
	}

	return nFound;
}
*/

int FindWord(int nStep, int nPrevRow, int nPrevColumn) {
	int nLoopDir, nLoopChar, nRow, nColumn, nFound = 0;
	const int g_arrDrow[]		=	{-1, -1, -1, +0, +0, +0, +1, +1, +1};
	const int g_arrDcolumn[]	=	{-1, +0, +1, -1, +0, +1, -1, +0, +1};

	for (nLoopDir = 0; nLoopDir < sizeof(g_arrDrow) / sizeof(g_arrDrow[0]); nLoopDir++) {

		nRow = nPrevRow; nColumn = nPrevColumn;
		for (nLoopChar = nStep; nLoopChar < g_nSearchedWordLen; nLoopChar++) {
			nRow += g_arrDrow[nLoopDir];
			nColumn += g_arrDcolumn[nLoopDir];

			if (!(nRow >= 0 && nRow < g_nNoRows && nColumn >= 0 && nColumn < g_nNoColumns && g_arrszMatrix[nRow][nColumn] == g_szSearchedWord[nLoopChar])) {
				break;
			}
		}

		if (nLoopChar == g_nSearchedWordLen) {
			nFound = 1;
			break;
		}
	}

	return nFound;
}

char *mystrlwr(char *szString) {
	char *psz;

	for (psz = szString; *psz; psz++)
		if (*psz >= 'A' && *psz <= 'Z')
			*psz += ('a' - 'A');
			
	return szString;
}

int main() {
	int nNoCases, nNoSearchedWords;
	int nRowLoop, nColumnLoop;
	char szLine[MAX_LINE_LEN];

	sscanf(gets(szLine), "%d", &nNoCases);
	gets(szLine);

	for ( ; nNoCases--; ) {
		sscanf(gets(szLine), "%d %d", &g_nNoRows, &g_nNoColumns);

		for (nRowLoop = 0; nRowLoop < g_nNoRows; nRowLoop++)
			mystrlwr(gets(g_arrszMatrix[nRowLoop]));

		for (sscanf(gets(szLine), "%d", &nNoSearchedWords); nNoSearchedWords--; ) {
			g_nSearchedWordLen = strlen(mystrlwr(gets(g_szSearchedWord)));

			for (nRowLoop = 0; nRowLoop < g_nNoRows; nRowLoop++)
				for (nColumnLoop = 0; nColumnLoop < g_nNoColumns; nColumnLoop++) {
					if (g_arrszMatrix[nRowLoop][nColumnLoop] == *g_szSearchedWord && FindWord(1, nRowLoop, nColumnLoop)) {
						printf("%d %d\n", nRowLoop + 1, nColumnLoop + 1);
						nRowLoop = g_nNoRows;
						break;
					}
				}
		}

		gets(szLine);

		if (nNoCases)
			printf("\n");
	}


	return 0;
}
