/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11455 - Behold my quadrangle                                     */


#include <stdio.h>

#define SWAP_NUMBERS(a, b, c)	{ c = a; a = b; b = c; }

int main() {
	long long nA, nB, nC, nD, nTemp;
	int nNoCases, i;

	scanf("%d", &nNoCases);
	for (i = 0; i < nNoCases; i++) {
		scanf("%lld %lld %lld %lld", &nA, &nB, &nC, &nD);

		if (nA < nB)
			SWAP_NUMBERS(nA, nB, nTemp);

		if (nA < nC)
			SWAP_NUMBERS(nA, nC, nTemp);

		if (nA < nD)
			SWAP_NUMBERS(nA, nD, nTemp);

		if (nB < nC)
			SWAP_NUMBERS(nB, nC, nTemp);

		if (nB < nD)
			SWAP_NUMBERS(nB, nD, nTemp);

		if (nC < nD)
			SWAP_NUMBERS(nC, nD, nTemp);

		if (nA == nB && nB == nC && nC == nD)
			printf("square\n");
		else if (nA == nB && nC == nD)
			printf("rectangle\n");
		else if (nA + nB + nC > nD && nA + nB + nD > nC && nA + nC + nD > nB && nB + nC + nD > nA)
			printf("quadrangle\n");
		else
			printf("banana\n");
	}

	return 0;
}
