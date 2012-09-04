/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>

#define SWAP(a, b, temp)	{ temp = a; a = b; b = temp; }

int main() {
	int nA, nB, nC, nTemp;

	while (scanf("%d %d %d", &nA, &nB, &nC) == 3 && (nA || nB || nC)) {
		if (nA < nB)
			SWAP(nA, nB, nTemp);
		if (nA < nC)
			SWAP(nA, nC, nTemp);

		if (nA * nA == nB * nB + nC * nC)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
