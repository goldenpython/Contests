/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11172 - Relational Operator                                      */


#include <stdio.h>

int main() {
	int a, b, nrcases;

	for (scanf("%d", &nrcases); nrcases; nrcases--) {
		scanf("%d %d", &a, &b);

		a -= b;

		if (a == 0)
			printf("=\n");
		else if (a < 0)
			printf("<\n");
		else
			printf(">\n");
	}

	return 0;
}
