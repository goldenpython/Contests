/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 256 - Quirksome Squares                                          */



#include <stdio.h>
#include <math.h>

int power(int b, int e) {
	int i, ret = 1;

	for (i = 0; i < e; i++)
		ret *= b;

	return ret;
}

int main() {
	int n, l1, l2, i, m, d, h1, h2;
	char szFormat[16];

	while (scanf("%d", &n) == 1) {
		l1 = power(10, n / 2 - 1);
		l2 = power(10, n / 2) - 1;

		d = l1 * 10;
		sprintf(szFormat, "%%0%dd%%0%dd\n", n / 2, n / 2);

		l1 = 0;

		for (i = l1; i <= l2; i++) {
			m = i * i;

			h1 = m / d;
			h2 = m % d;

			if ((h1 + h2) * (h1 + h2) == m)
				printf(szFormat, h1, h2);
		}
	}

	return 0;
}
