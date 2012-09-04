/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11185 - Ternary                                                  */



#include <stdio.h>

int main() {
	int n = 0, arr[30], nrc, i;


	while (scanf("%d", &n), n >= 0) {
		if (n == 0) {
			printf("0\n");
			continue;
		}

		nrc = 0;
		while (n) {
			arr[nrc++] = n % 3;
			n /= 3;
		}

		for (i = nrc - 1; i >= 0; i--)
			printf("%d", arr[i]);

		printf("\n");
	}

	return 0;
}
