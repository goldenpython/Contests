/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12527 - Different Digits                                         */

#include <stdio.h>

#define MAX		5001

int IsGood(int nNumber) {
	char *psz1, *psz2, szNumber[8];

	sprintf(szNumber, "%d", nNumber);

	for (psz1 = szNumber; *psz1; psz1++)
		for (psz2 = psz1 + 1; *psz2; psz2++)
			if (*psz1 == *psz2)
				return 0;

	return 1;
}

int main() {
	int nLoop, nFrom, nTo;
	int arrnSum[MAX];

	arrnSum[0] = 1;
	for (nLoop = 1; nLoop < MAX; nLoop++)
		arrnSum[nLoop] = IsGood(nLoop) ? arrnSum[nLoop - 1] + 1 : arrnSum[nLoop - 1];
		

	while (scanf("%d %d", &nFrom, &nTo) == 2)
		printf("%d\n", arrnSum[nTo] - arrnSum[nFrom - 1]);

	return 0;
}