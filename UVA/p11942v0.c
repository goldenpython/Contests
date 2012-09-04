/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>

int main() {
	int nN, nLoop, nLast, nCurrent, nNeg, nPos;

	printf("Lumberjacks:\n");
	for (scanf("%d", &nN); nN; nN--) {
		nNeg = nPos = 0;
		scanf("%d", &nLast);
		for (nLoop = 1; nLoop < 10; nLoop++) {
			scanf("%d", &nCurrent);
			if (nLast < nCurrent)
				nPos++;
			else if (nLast > nCurrent)
				nNeg++;
			nLast = nCurrent;
		}

		if (!nPos && nNeg >= 0 || !nNeg && nPos >= 0)
			printf("Ordered\n");
		else
			printf("Unordered\n");
	}

	return 0;
}
