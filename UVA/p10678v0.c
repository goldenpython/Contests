/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10678 - The Grazing Cow                                          */


#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
	int n, d, l, i;
	double r1, r2;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &d, &l);

		r1 = d / 2.0;
		r2 = l / 2.0;
		r1 = sqrt(r2 * r2 - r1 * r1);

		printf("%.3lf\n", PI * r1 * r2);
	}
}
