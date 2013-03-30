/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10347 - Medians                                                  */


#include <stdio.h>
#include <math.h>

int main() {
	double m1, m2, m3;

	while (scanf("%lf %lf %lf", &m1, &m2, &m3) == 3) {
		double sm;
		double A;

		if (m1 <= 0 || m2 <= 0 || m3 <= 0 || (sm = (m1 + m2 + m3) / 2, A = sm * (sm - m1) * (sm - m2) * (sm - m3)) <= 0)
			printf("-1.000\n");
		else
			printf("%.3lf\n", sqrt(A) * 4 / 3);
	}

	return 0;
}