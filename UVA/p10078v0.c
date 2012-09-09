/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10078 - The Art Gallery                                          */



#include <stdio.h>

#define DET(x1, y1, x2, y2, x3, y3)			(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))
#define SGN(a)								((a) > 0 ? 1 : -1)

int main() {
	int nN, nLoop;
	int nX1, nY1, nX2, nY2, nX3, nY3, nXFirst, nYFirst, nXSecond, nYSecond, nDet, nSgn, nSgnTemp;

	while (scanf("%d", &nN), nN) {
		scanf("%d %d", &nX1, &nY1);
		nXFirst = nX1, nYFirst = nY1;

		scanf("%d %d", &nX2, &nY2);
		nXSecond = nX2, nYSecond = nY2;

		scanf("%d %d", &nX3, &nY3); 


		nSgn = DET(nX1, nY1, nX2, nY2, nX3, nY3);
		nSgnTemp = nSgn = SGN(nSgn);

		for (nLoop = 3; nLoop < nN; nLoop++) {
			nX1 = nX2, nY1 = nY2;
			nX2 = nX3, nY2 = nY3;
			scanf("%d %d", &nX3, &nY3);

			nSgnTemp = DET(nX1, nY1, nX2, nY2, nX3, nY3); nSgnTemp = SGN(nSgnTemp);
			if (nSgnTemp != nSgn)
				break;
		}

		if (nSgnTemp != nSgn) {
			printf("Yes\n");
			for (nLoop++; nLoop < nN; nLoop++)
				scanf("%d %d", &nX3, &nY3);
		} else {
			nSgnTemp = DET(nX2, nY2, nX3, nY3, nXFirst, nYFirst); nSgnTemp = SGN(nSgnTemp);
			if (nSgnTemp != nSgn) {
				printf("Yes\n");
				continue;
			}

			nSgnTemp = DET(nX3, nY3, nXFirst, nYFirst, nXSecond, nYSecond); nSgnTemp = SGN(nSgnTemp);
			if (nSgnTemp != nSgn)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;
}
