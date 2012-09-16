/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10013 - Super long sums                                          */



#include <stdio.h>
#include <math.h>

#define MAX_DIGITS 1000005

int result[MAX_DIGITS];

int main() {
	char szLine[128];
	int TestCaseLoop, NoTestCases, m, i, r;


	/* freopen("input/10013.txt", "rt", stdin); */

	gets(szLine); NoTestCases = atoi(szLine);

	for (TestCaseLoop = 0; TestCaseLoop < NoTestCases; TestCaseLoop++) {
		gets(szLine);

		gets(szLine); m = atoi(szLine);
		for (i = 0; i < m; i++) {
			gets(szLine); result[i] = szLine[0] + szLine[2] - '0';
		}

		r = 0;
		for (i = m - 1; i >= 0; i--) {
			result[i] = result[i] + r;
			if (result[i] > '9') {
				result[i] = result[i] - 10;
				r = 1;
			} else
				r = 0;

		}

		for (i = 0; i < m; i++)
			printf("%c", result[i]);

		if (TestCaseLoop < NoTestCases - 1)
			printf("\n\n");
		else
			printf("\n");
	}

	return 0;
}