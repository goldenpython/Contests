/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10790 - How Many Points of Intersection?                         */


#include <stdio.h>

int main() {
	int n, m, CaseIndex = 1;
	unsigned long long a, b;
	int nrc, i, cf[32];

	while (scanf("%d %d", &n, &m), n && m) {
		a = n;
		a *= (unsigned long long)(n - 1);
		a /= 2;

		b = m;
		b *= (unsigned long long)(m - 1);
		b /= 2;

		a *= b;

		if (a == 0) {
			printf("Case %d: 0", CaseIndex++);
		} else
			printf("Case %d: ", CaseIndex++);

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
