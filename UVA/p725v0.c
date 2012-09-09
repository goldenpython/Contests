/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 725 - Division                                                   */


#include <stdio.h>
#include <string.h>

int main() {
	int n, min, max, a, sol, i, j, good, aux;
	int c[10], v, first = 1;

	while (scanf("%d", &n), n) {
		min = 1000 * n; max = 99999;

		if (min < 10000)
			min = 10000 + n - 10000 % n;
		a = min / n;

		if (!first)
			printf("\n");

		sol = 0;
		for (i = min; i <= max; i += n, a++) {
			good = 1;

			memset(c, 0, sizeof(c));

			aux = i;
			while (aux) {
				v = aux % 10;
				if (c[v]++) {
					good = 0;
					break;
				}
				aux /= 10;
			}

			if (good) {
				if (a < 10000)
					if (c[0]++)
						continue;


				aux = a;
				while (aux) {
					v = aux % 10;
					if (c[v]++) {
						good = 0;
						break;
					}
					aux /= 10;
				}
			}

			if (good) {
				printf("%05d / %05d = %d\n", i, a, n);
				sol = 1;
			}
		}

		if (!sol)
			printf("There are no solutions for %d.\n", n);

		first = 0;
	}

	return 0;
}
