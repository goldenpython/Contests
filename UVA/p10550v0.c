/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10550 - Combination Lock                                         */



#include <stdio.h>

int main() {
	int a, b, c, d, sum;

	while (scanf("%d %d %d %d", &a, &b, &c, &d), a || b || c || d) {
		sum = 80;
		sum += 40 - (b - a + 40) % 40;

		sum += 40;
		sum += 40 - (b + 40 - c) % 40;

		sum += 40 - (40 - c + d) % 40;

		printf("%d\n", sum * 360 / 40);
	}

	return 0;
}
