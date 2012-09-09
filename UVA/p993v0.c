/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 993 - Product of digits                                          */


#include <stdio.h>
#include <stdlib.h>

int main() {
	int nrcases, i, j, n, c[10];

	scanf("%d", &nrcases);
	for ( ; nrcases; nrcases--) {
		scanf("%d", &n);

		if (n == 1) {
			printf("1\n");
			continue;
		}

		memset(c, 0, sizeof(c));

		while (!(n % 7))
			n /= 7, c[7]++;

		while (!(n % 5))
			n /= 5, c[5]++;

		while (!(n % 3))
			n /= 3, c[3]++;

		while (!(n % 2))
			n /= 2, c[2]++;

		if (n != 1) {
			printf("-1\n");
			continue;
		}

		if (c[3]) {
			c[9] = c[3] / 2;
			c[3] %= 2;
		}

		if (c[2]) {
			c[8] = c[2] / 3;
			c[2] %= 3;
		}

		if (c[3] && c[2]) {
			if (c[2] < c[3]) {
				c[6] = c[2];
				c[3] -= c[2];
				c[2] = 0;
			} else {
				c[6] = c[3];
				c[2] -= c[3];
				c[3] = 0;
			}
		}

		if (c[2]) {
			c[4] = c[2] / 2;
			c[2] %= 2;
		}

		for (i = 1; i <= 9; i++)
			for (j = 0; j < c[i]; j++)
				printf("%d", i);

		printf("\n");
	}
}
