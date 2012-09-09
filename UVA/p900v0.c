/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 900 - Brick Wall Patterns                                        */



#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MAX_L	32
#define MAX_N	51
#define BASE	100000

void ADD(int *dest, int *s1, int *s2) {
	int l1 = s1[0], l2 = s2[0];
	int l = MAX(l1, l2), r = 0, i;

	for (i = 1; i <= l; i++) {
		r += s1[i] + s2[i];
		dest[i] = r % BASE;
		r = (r > BASE) ? 1 : 0;

	}

	if (r)
		dest[++l] = r;

	dest[0] = l;
}

int main() {
	int i, n;
	int fib[MAX_N][MAX_L];

	memset(fib, 0, sizeof(fib));
	fib[0][0] = fib[1][0] = 1;
	fib[1][1] = fib[0][1] = 1;
	for (i = 2; i < MAX_N; i++)
		ADD(fib[i], fib[i - 2], fib[i - 1]);

	while (scanf("%d", &n), n) {
		printf("%d", fib[n][fib[n][0]]);

		for (i = fib[n][0] - 1; i >= 1; i--)
			printf("%05d", fib[n][i]);

		printf("\n");
	}

	return 0;
}
