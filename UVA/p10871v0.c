/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10871 - Primed Subsequence                                       */


#include <stdio.h>
#include <math.h>

#define MAX_PRIMES		10011
#define MAX_NOPRIMES	2000
#define	MAX_NUMBERS		10006

int primes[MAX_NOPRIMES];
int nrprimes;

int nrcases;
int i, j, n, k, solution;
int sums[MAX_NUMBERS];

void GenPrimes() {
	int i, j, lim; 
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11;
	nrprimes = 5;

	for (i = 13; i <= MAX_PRIMES; i += 2) {
		lim = (int) sqrt(i);
		for (j = 0; primes[j] <= lim; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			primes[nrprimes++] = i;
	}
}

int FindPrime(int prime) {
	/* int a = 0, b = nrprimes - 1, m, lim;

	while (a <= b)
		if (primes[m = (a + b) >> 1] < prime) {
			a = m + 1;
		} else
			b = m - 1;

	if (primes[a] == prime)
		return 1;  */

	int lim, i;

	lim = (int) sqrt(prime);
	for (i = 0; primes[i] <= lim; i++) 
		if (!(prime % primes[i]))
			return 0;

	return 1;
}

int main() {
	GenPrimes();

	for (scanf("%d", &nrcases); nrcases; nrcases--) {
		scanf("%d", &n);

		sums[0] = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &sums[i + 1]);
			sums[i + 1] += sums[i];
		}


		solution = 0;
		for (i = 2; i <= n; i++)
			for (j = i; j <= n; j++) {
				k = sums[j] - sums[j - i];
				if (FindPrime(k)) {
					printf("Shortest primed subsequence is length %d:", i);
					for (k = 0; k < i; k++)
						printf(" %d", sums[j + k - i + 1] - sums[j + k - i]);

					printf("\n");

					solution = 1;

					i = n + 1;
					break;
				}
			}

		if (!solution)
			printf("This sequence is anti-primed.\n");

	}

	return 0;
}
