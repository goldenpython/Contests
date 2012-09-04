/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11000 - Bee                                                      */


#include <stdio.h>

int main() {
	int n, i;
	unsigned int m, f, m1, f1;

	while (scanf("%d", &n), n != -1) {
		if (!n) {
			printf("0 1\n");
			continue;
		}

		m = f = 1;

		for (i = 0; i < n - 1; i++) {
			m1 = m + f;
			f1 = m + 1;

			m = m1;
			f = f1;
		}
			
		printf("%u %u\n", m, m + f);
	}

	return 0;
}
