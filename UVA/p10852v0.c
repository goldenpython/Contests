/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10852 - Less Prime                                               */


#include <stdio.h>
#include <math.h>

#define MAX	10005
#define NR_PRIMES 1500

int primes[NR_PRIMES], nrp;

void ComputePrimes() {
	int i, j, l;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[6] = 17; primes[nrp = 7] = 19;

	for (i = 23; i < MAX; i += 2) {
		int l = sqrt(i);
		for (j = 0; primes[j] <= l; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			primes[++nrp] = i;
	}

}

void Solve(int nr) {
	int i = 0, j = nrp - 1, m, p, max = -1, sol, x, aux;
	while (i <= j)
		if (primes[m = (i + j) >> 1] < nr)
			i = m + 1;
		else
			j = m - 1;


	i = j;
	for ( ; i >= 0; i--) {
		x = primes[i];
		p = nr / x;
		aux = nr - x * p;
		if (max < aux) {
			max = aux;
			sol = i;
		}
	}

	printf("%d\n", primes[sol]);
}

int main() {
	int i, nrc, nr;

	ComputePrimes();

	scanf("%d", &nrc);
	for (i = 0; i < nrc; i++) {
		scanf("%d", &nr);
		Solve(nr);
	}

	return 0;
}
