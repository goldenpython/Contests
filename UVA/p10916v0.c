/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10916 - Factstone Benchmark                                      */


#include <stdio.h>
#include <math.h>

#define INTERVAL	(1 + ((2160 - 1960) / 10))

int fact[INTERVAL];

void Compute() {
	int i, l = INTERVAL, nrb = 4, j = 1;
	double logfact = 0, ln2 = log(2);

	for (i = 0; i < l; i++, nrb *= 2) {
		while (logfact <= nrb * ln2) {
			j++;
			logfact += log(j);
		}
		fact[i] = j - 1;
	}
}

int main() {
	int n, i, j, m;

	Compute();

	while (1) {
		scanf("%d", &n);

		if (n == 0)
			return 0;

		printf("%d\n", fact[(n - 1960) / 10]);
	}

	return 0;
}
