/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11530 - SMS Typing                                               */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *pszKeyboard[] = {
	" ",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz",
};

struct oLetter {
	int iKey;
	int iKeyOrd;
} arrKeys[255];

int arrNumLettersOnKey[10];

#define MAX_LINE_LEN	128

int main() {
	int i, j, iLoopCase;
	int iLastKey, iLastKeyOrd, iNoCases, iSol;
	char *p, szLine[MAX_LINE_LEN];

	for (i = 0; i < sizeof(pszKeyboard) / sizeof(char *); i++) {
		for (j = 0; pszKeyboard[i][j] != '\0'; j++) {
			arrKeys[pszKeyboard[i][j]].iKey = i;
			arrKeys[pszKeyboard[i][j]].iKeyOrd = j;
			arrNumLettersOnKey[i]++;
		}
	}

	gets(szLine); sscanf(szLine, "%d", &iNoCases);
	for (iLoopCase = 1; iLoopCase <= iNoCases; iLoopCase++) {
		iLastKey = -1; iLastKeyOrd = -1; iSol = 0;
		for (p = gets(szLine); *p; p++)
			if (iLastKey != arrKeys[*p].iKey)
				iSol += 1 + (iLastKeyOrd = arrKeys[*p].iKeyOrd);
			else
				iSol += (arrNumLettersOnKey[iLastKey] + iLastKeyOrd - arrKeys[*p].iKeyOrd) % arrNumLettersOnKey[iLastKey];

		printf("Case #%d: %d\n", iLoopCase, iSol);
	}


	return 0;
}
