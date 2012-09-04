/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>

#define ABS(a)		((a) > 0 ? (a) : -(a))

int main() {
	int NoTestCases;
	int i, j, sum, min, k, n, nr[500];

	for (scanf("%d", &NoTestCases); NoTestCases; NoTestCases--) {
		scanf("%d", &n);

		for (i = 0; i < n; i++)
			scanf("%d", &nr[i]);		

		min = 0x7FFFFFFF;
		for (i = 0; i < n; i++) {
			sum = 0;
			for (j = 0; j < n; j++)
				if (i != j) {
					k = nr[i] - nr[j];
					sum += ABS(k);
				}

			if (sum < min)
				min = sum;
		}


		printf("%d\n", min);
	}

	return 0;
}
