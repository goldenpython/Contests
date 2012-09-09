/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 913 - Joana and the Odd Numbers                                  */



#include <stdio.h>

int main() {
	int	n;
	int cf[100], nrc, i;
	long long a, b, c;

	while (scanf("%d", &n) == 1) {
		a = (n + 1) / 2;
		a *= a;

		a = 1 + a * 2 - 2;
		b = a - 2;
		c = b - 2;

		a = a + b + c;

		nrc = 0;
		while (a) {
			cf[nrc++] = (int)(a % 10);
			a /= 10;
		}

		for (i = nrc - 1; i >= 0; i--)
			printf("%d", cf[i]);

		printf("\n");
	}

	return 0;
}
