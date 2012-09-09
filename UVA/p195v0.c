/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 195 - Anagram                                                    */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN	2048

#define MIN(a,b)	((a) > (b) ? (b) : (a))


struct CHAR_LIST {
	char cChar;
	int iCount;
};

int iCharCountParam, iLen;
struct CHAR_LIST arrListParam['z' - 'a' + 1 + 'Z' - 'A' + 1];

char arrListSol[1024];

void bk(int iStep) {
	int i;

	if (iStep == iLen) {
		arrListSol[iStep] = '\0';
		printf("%s\n", arrListSol);
	}

	for (i = 0; i < iCharCountParam; i++)
		if (arrListParam[i].iCount > 0) {
			arrListSol[iStep] = arrListParam[i].cChar;

			arrListParam[i].iCount -= 1;
			bk(iStep + 1);
			arrListParam[i].iCount += 1;
		}
}

int main() {
	char *psz, szLine[MAX_LINE_LEN];
	int iFreq[256];
	int iNoCases, iCaseLoop, iChar, iLowerCaseChar;

	gets(szLine); sscanf(szLine, "%d", &iNoCases);
	/* scanf("%d", &iNoCases); */
	for (iCaseLoop = 0; iCaseLoop < iNoCases; iCaseLoop++) {
		gets(szLine);
		/* scanf("%s", szLine); */
		memset(iFreq + 'a', 0, ('z' - 'a' + 1) * sizeof(int));
		memset(iFreq + 'A', 0, ('Z' - 'A' + 1) * sizeof(int));
		for (psz = szLine; *psz; psz++)
			iFreq[*psz & 0xFF]++;
		iLen = 0;

		iCharCountParam = 0;
		for (iChar = 'A'; iChar <= 'Z'; iChar++) {
			if (iFreq[iChar]) {
				arrListParam[iCharCountParam].cChar = iChar;
				arrListParam[iCharCountParam++].iCount = iFreq[iChar];
				iLen += iFreq[iChar];
			}
			iLowerCaseChar = iChar - 'A' + 'a';
			if (iFreq[iLowerCaseChar]) {
				arrListParam[iCharCountParam].cChar = iLowerCaseChar;
				arrListParam[iCharCountParam++].iCount = iFreq[iLowerCaseChar];
				iLen += iFreq[iLowerCaseChar];
			}
		}
		bk(0);
	}

	return 0;
}
