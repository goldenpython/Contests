/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10991 - Region                                                   */


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

int main() {
	int n, i;
	double r1, r2, r3;
	double a, b, c, alfa, beta, gama, area, aa, bb, cc;
	char *p, szLine[500], szLine1[100];

	/* scanf("%d", &n); */
	gets(szLine);
	n = atoi(szLine);

	for (i = 0; i < n; i++) {
		/* scanf("%lf %lf %lf", &r1, &r2, &r3); */
		gets(szLine);
		p = strtok(szLine, " "); r1 = atof(p);
		p = strtok(NULL, " "); r2 = atof(p);
		p = strtok(NULL, " "); r3 = atof(p);

		a = r1 + r2;
		aa = a * a;

		b = r1 + r3;
		bb = b * b;

		c = r2 + r3;
		cc = c * c;

		alfa = (-cc + aa + bb) / (2 * (b *= a));
		beta = (-bb + aa + cc) / (2 * a * c);

		alfa = acos(alfa);
		beta = acos(beta);

		area = b * sin(alfa);

		gama = PI - alfa - beta;


		area = (area - r1 * r1 * alfa - r2 * r2 * beta - r3 * r3 * gama) / 2;

		printf("%d.%06d\n", (int)area, (int)((area - (int)area) * 1000000));
	}

	return 0;
}
