/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 914 - Jumping Champion                                           */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX			1000012
#define NR_PRIMES	80000

int primes[NR_PRIMES], nrp;
int numprimes[MAX];
int maxdiff;

int diff[MAX];


void ComputePrimes() {
	int i, j;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[6] = 17; 
	primes[nrp = 7] = 19;

	for (i = 23; i < MAX; i += 2) {
		int l = (int)sqrt(i);
		for (j = 1; primes[j] <= l; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

		if (j != -1) {
			primes[++nrp] = i;
			if (i - primes[nrp - 1] > maxdiff)
				maxdiff = i - primes[nrp - 1];
		}
	}

}

int FindPrime(int nr) {
	int a = 0, b = nrp, m;

	while (a <= b) {
		if (primes[m = (a + b) >> 1] > nr)
			b = m - 1;
		else 
			a = m + 1;
	}

	return b;
}

int main() {
	int i, loop, nrcases, l, u, index1, index2, sol;
	int *differences, max;

	ComputePrimes();

	for (i = 0; i < nrp; i++)
		diff[i] = primes[i + 1] - primes[i];

	differences = (int *)malloc((1 + maxdiff) * sizeof(int));

	scanf("%d", &nrcases);
	for (loop = 1; loop <= nrcases; loop++) {
		scanf("%d %d", &l, &u);

		index1 = FindPrime(l);
		if (index1 < 0 || primes[index1] != l)
			index1++;

		index2 = FindPrime(u);
		/* if (index2 < 0 || primes[index2] != u)
			index2++; */

		memset(differences, 0, sizeof(int) * (1 + maxdiff));
		for (i = index1; i < index2; i++)
			differences[diff[i]]++;

		max = 0; sol = 1;
		for (i = 0; i <= maxdiff; i++) {
			if (differences[max] < differences[i]) {
				max = i;
				sol = 1;
			} else if (differences[max] == differences[i]) {
				sol = 0;
			}

		}

		if (!sol)
			printf("No jumping champion\n");
		else {
			printf("The jumping champion is %d\n", max);
		}
	}

	free(differences);

	return 0;
}
