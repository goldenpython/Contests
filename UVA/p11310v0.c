/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11310 - Delivery Debacle                                         */


#include <stdio.h>

#define MAX 42

int main() {
	long long m, res[MAX];
	int i, nCases, n;
	char *p1, *p2, szRes[MAX];

	res[0] = 1;
	res[1] = 1;
	res[2] = 5;
	for (i = 3; i < MAX; i++)
		res[i] = 4 * res[i - 2] + 2 * res[i - 3] + res[i - 1];

	*(p2 = szRes + 20) = '\0';

	for (scanf("%d", &nCases); nCases; nCases--) {
		scanf("%d", &n);

		m = res[n];
		for (p1 = p2 - 1; m; p1--) {
			*p1 = m % 10 + '0';
			m /= 10;
		}

		printf("%s\n", p1 + 1);
	}

	return 0;
}
