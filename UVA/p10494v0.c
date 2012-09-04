/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10494 - If We Were a Child Again                                 */


#include <stdio.h>

#define MAX		1024

int main() {
	long long nSecondNumber, nDividend;
	char szSecondNumber[16];
	char *pszCursorDividend, *pszCursorResult, cOp, szFirstNumber[MAX], szResult[MAX];

	while (scanf("%s %c %s", szFirstNumber, &cOp, &szSecondNumber) == 3) {
		nSecondNumber = atoi(szSecondNumber);

		nDividend = 0;
		pszCursorResult = szResult;
		for (pszCursorDividend = szFirstNumber; *pszCursorDividend; pszCursorDividend++) {
			nDividend = nDividend * 10 + (*pszCursorDividend - '0');
			*pszCursorResult++ = nDividend / nSecondNumber + '0';
			nDividend %= nSecondNumber;
		}

		*pszCursorResult = '\0';
		for (pszCursorResult = szResult; *(pszCursorResult + 1) && *pszCursorResult == '0'; pszCursorResult++)
			;

		if (cOp == '%')
			printf("%d\n", nDividend);
		else
			printf("%s\n", pszCursorResult);
	}

	return 0;
}
