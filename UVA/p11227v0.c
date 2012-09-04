/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11227 - The silver bullet.                                       */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN	100
#define MAX_POINTS		102

#define ERR				0.0001f

/* #define DET(x1, y1, x2, y2, x3, y3)		(x1 * y2 + x2 * y3 + x3 * y1 - x3 * y2 - x1 * y3 - x2 * y1) */
#define DET(x1, y1, x2, y2, x3, y3)			(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))
#define ABS(a)	((a) > 0 ? (a) : -(a))

int main() {
	char *pdest, *p, szLine[MAX_LINE_LEN], szLine1[MAX_LINE_LEN];
	int nrcases, n, npoints, maxinline, max;
	int loop, i, j, k;
	double xx, yy, det, precalc1, precalc2, precalc3, precalc4, x[MAX_POINTS], y[MAX_POINTS];

	/* freopen("input\\11227.txt", "rt", stdin); */

	gets(szLine); nrcases = atoi(szLine);
	for (loop = 0; loop < nrcases; loop++) {
		gets(szLine); n = atoi(szLine);

		npoints = 0;
		for (i = 0; i < n; i++) {
			gets(szLine);

			p = strtok(szLine, " ");
			xx = atof(p);

			p = strtok(NULL, " ");
			yy = atof(p);

			for (j = 0; j < npoints; j++)
				if (x[j] == xx && y[j] == yy) {
					j = -1;
					break;
				}

			if (j != -1)
				x[npoints] = xx, y[npoints++] = yy;
		}

		maxinline = 0;
		for (i = 0; i < npoints - 2 - maxinline; i++)
			for (j = i + 1; j < npoints - 1 - maxinline; j++) {
				max = 0;
				precalc1 = x[i] * y[j];
				precalc2 = x[j] * y[i];
				precalc3 = y[i] - y[j];
				precalc4 = x[j] - x[i];

				for (k = j + 1; k < npoints; k++) {
					/*det = DET(x[i], y[i], x[j], y[j], x[k], y[k]); */
					det = precalc1 + y[k] * precalc4 - precalc2 + x[k] * precalc3;

					if (ABS(det) < ERR)
						max++;
				}

				if (max > maxinline)
					maxinline = max;
			}


			if (npoints > 1)
				printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", loop + 1, npoints, maxinline + 2);
			else 
				printf("Data set #%d contains a single gnu.\n", loop + 1); 
	}

	return 0;
}
