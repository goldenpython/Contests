/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11371 - Number Theory for Newbies                                */


#include <stdio.h>
#include <string.h>

int main() {
	int nN, nLoop, nLoopPow, nNoDigits;
	long long llMaxDiff, llSolMax, llSolMin;
	int arrnDigits[10];

	while (scanf("%d", &nN) == 1) {
		memset(arrnDigits, 0, sizeof(arrnDigits));
		for (nN = nN, nNoDigits = 0; nN; arrnDigits[nN % 10]++, nN /= 10, nNoDigits++)
			;

		llSolMax = 0;
		for (nLoop = 9; nLoop >= 0; nLoop--)
			for (nLoopPow = 0; nLoopPow < arrnDigits[nLoop]; nLoopPow++)
				llSolMax = llSolMax * 10 + nLoop;

		llSolMin = 0;
		for (nLoop = 1; nLoop <= 9; nLoop++)
			if (arrnDigits[nLoop]) {
				llSolMin = nLoop;
				arrnDigits[nLoop]--;
				break;
			}
		for (nLoop = 0; nLoop <= 9; nLoop++)
			for (nLoopPow = 0; nLoopPow < arrnDigits[nLoop]; nLoopPow++)
				llSolMin = llSolMin * 10 + nLoop;

		llMaxDiff = llSolMax - llSolMin;

		printf("%lld - %lld = %lld = 9 * %lld\n", llSolMax, llSolMin, llMaxDiff, llMaxDiff / 9);
	}

	return 0;
}
