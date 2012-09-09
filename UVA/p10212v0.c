/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10212 - The Last Non-zero Digit.                                 */



#include <stdio.h>

int main() {
	int i, n, m, k, n2, n5, prod, lim, numiter;
	int l2[] = {2, 4, 8, 6};

	while (scanf("%d %d", &n, &m) == 2) {
		n2 = n5 = 0;
		prod = 1;

		for (i = n - m + 1; i <= n; i++) {
			if (i % 10 == 0)
				break;

			k = i;

			while (!(k & 0x1)) {
				k >>= 1;
				n2++;
			}

			while (!(k % 5)) {
				k /= 5;
				n5++;
			}

			prod *= k;
			prod %= 10;
		}

		lim = n / 10 * 10 - 1;
		numiter = (lim + 1 - i) / 10;

		for ( ; i < lim; i++) {
			/* 0 */			
			k = i;

			while (!(k & 0x1)) {
				k >>= 1;
				n2++;
			}

			while (!(k % 5)) {
				k /= 5;
				n5++;
			}

			prod *= k;
			prod %= 10;

			/* 1 */
			i++;

			/* 2 */
			i++;
			k = i;

			while (!(k & 0x1)) {
				k >>= 1;
				n2++;
			}

			prod *= k;
			prod %= 10;

			/* 3 */
			i++;
			/* prod *= 3; */

			/* 4 */
			i++;
			k = i;

			while (!(k & 0x1)) {
				k >>= 1;
				n2++;
			}

			prod *= k;
			prod %= 10;

			/* 5 */
			i++;
			k = i;
			while (!(k % 5)) {
				k /= 5;
				n5++;
			}

			prod *= k;
			prod %= 10;

			/* 6 */
			i++;
			k = i;
			while (!(k & 0x1)) {
				k >>= 1;
				n2++;
			}

			prod *= k;
			prod %= 10;

			/* 7 */
			i++;
			k = i;

			/* prod *= 7; */

			/* 8 */
			i++;
			k = i;
			while (!(k & 0x1)) {
				k >>= 1;
				n2++;
			}

			prod *= k;
			prod %= 10;

			/* 9 */
			i++;

			/* prod *= 9; */
		}

		if (numiter % 2 == 1)
			prod *= 9;

		for ( ; i <= n; i++) {
			k = i;

			while (!(k & 0x1)) {
				k >>= 1;
				n2++;
			}

			while (!(k % 5)) {
				k /= 5;
				n5++;
			}

			prod *= k;
			prod %= 10;
		}

		if (n2 > n5) {
			n2 -= n5;
			if (n2)
				prod *= l2[(n2 - 1) % 4];
		} else if (n5 > n2)
			prod *= 5;
		

		printf("%d\n", prod % 10);
	}

	return 0;
}
