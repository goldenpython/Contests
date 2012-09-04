/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>

#define MAX(a, b)	((a) > (b) ? (a) : (b))
#define MIN(a, b)	((a) > (b) ? (a) : (b))

int main() {
	int nL, nC, nR1, nR2, nMaxR;

	while (scanf("%d %d %d %d", &nL, &nC, &nR1, &nR2), nL) {
		nR1 *= 2; nR2 *= 2;

		nMaxR = MAX(nR1, nR2);
		if (nL < nMaxR || nC < nMaxR) {
			printf("N\n");
			continue;
		}

		if (nL >= nR1 + nR2) {
			if (nC >= nMaxR)
				printf("S\n");
			else
				printf("N\n");
		} else if (nC >= nR1 + nR2) {
			if (nL >= nMaxR)
				printf("S\n");
			else
				printf("N\n");
		} else {

			nR1 = (nR1 + nR2) >> 1;
			nC -= nR1;
			nL -= nR1;

			if (nR1 * nR1 <= nC * nC + nL * nL)
				printf("S\n");
			else
				printf("N\n");
		}

	}

	return 0;
}
