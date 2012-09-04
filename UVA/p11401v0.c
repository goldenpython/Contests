/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11401 - Triangle Counting                                        */



#include <stdio.h>

#define MAX	1000001

long long sol[MAX];

int main() {
	int n, i;
	int cf[100], nrc;
	long long m;

	sol[3] = 0;
	sol[4] = 1;
	sol[5] = 3;
	for (i = 6; i < MAX; i++) {
		m = i;
		m = (1 + (m - 3)) * ((m - 2) >> 1) >> 1;
		sol[i] = sol[i - 1] + m;

		m = ++i;
		m = (2 + (m - 3)) * ((m - 2) >> 1) >> 1;
		sol[i] = sol[i - 1] + m;
	}

	while (scanf("%d", &n), n >= 3) {
		m = sol[n];

		if (m == 0) {
			printf("0\n");
			continue;
		}

		nrc = 0;
		while (m) {
			cf[nrc++] = (int)(m % 10);
			m /= 10;
		}

		for (i = nrc - 1; i >= 0; i--)
			printf("%d", cf[i]);
		printf("\n");
	}

	return 0;
}
