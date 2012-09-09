/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10193 - All You Need Is Love                                     */


#include <stdio.h>

#define MAX_LINE_LEN	32

int main() {
	char *psz, szLine[MAX_LINE_LEN];
	int nNoCases, nCaseLoop;
	int nNum1, nNum2, nTemp;

	sscanf(gets(szLine), "%d", &nNoCases);
	for (nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		for (psz = gets(szLine), nNum1 = 0; *psz; nNum1 = nNum1 * 2 + (*psz++ - '0'))
			;
		for (psz = gets(szLine), nNum2 = 0; *psz; nNum2 = nNum2 * 2 + (*psz++ - '0'))
			;

		while (nNum1) {
			nTemp = nNum1;
			nNum1 = nNum2 % nNum1;
			nNum2 = nTemp;
		}

		if (nNum2 > 1)
			printf("Pair #%d: All you need is love!\n", nCaseLoop);
		else
			printf("Pair #%d: Love is not all you need!\n", nCaseLoop);
	}

	return 0;
}
