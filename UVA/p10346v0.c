/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10346 - Peter's Smokes                                           */



#include <stdio.h>

int main() {
	int n, m, sum, b;

	while (scanf("%d %d", &n, &m) == 2) {
		sum = n; b = 0;
		while (n && m) {
			b += n % m;
			n = n / m;
			if (b >= m) {
				n++;
				b %= m;
			}

			sum += n;
		}

		printf("%d\n", sum);
	}
}