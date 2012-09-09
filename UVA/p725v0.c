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
