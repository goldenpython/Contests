/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10242 - Fourth Point !!                                          */



#include <stdio.h>
#include <math.h>

#define EQUAL(a, b)		(fabs(a - b) < 0.000000001)

int main() {
	double x[4], y[4], x1[4], y1[4];
	int i, j, c;

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2], &x[3], &y[3]) == 8) {
		for (i = 0; i < 4; i++)
			for (j = i + 1; j < 4; j++)
				if (EQUAL(x[i], x[j]) && EQUAL(y[i], y[j])) {
					x1[0] = x[i];
					y1[0] = y[i];

					i = 4;
					break;
				}
		c = 1;
		for (i = 0; i < 4; i++)
			if (!EQUAL(x[i], x1[0]) || !EQUAL(y[i], y1[0])) {
				x1[c] = x[i];
				y1[c] = y[i];
				c++;
			}


		x1[3] = x1[2] + x1[1] - x1[0];
		y1[3] = y1[2] + y1[1] - y1[0]; 

		printf("%.3lf %.3lf\n", x1[3], y1[3]);
	}

	return 0;
}
