/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11494 - Queen                                                    */


#include <stdio.h>

#define ABS(a)	((a) > 0 ? (a) : -(a))

int main() {
	int nX1, nX2, nY1, nY2, nDiffX, nDiffY;

	while (scanf("%d %d %d %d", &nX1, &nY1, &nX2, &nY2) == 4 && nX1) {
		nDiffX = ABS(nX1 - nX2);
		nDiffY = ABS(nY1 - nY2);

		if (nDiffX == nDiffY)
			if (!nDiffX)
				printf("0\n");
			else
				printf("1\n");
		else if (nDiffX && nDiffY)
			printf("2\n");
		else
			printf("1\n");
	}

	return 0;
}
