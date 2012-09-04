/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11466 - Largest Prime Divisor                                    */



#include <stdio.h>
#include <math.h>

#define MAX				10000000
#define NR_PRIMES		700000

int primes[NR_PRIMES], nrp;

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

		if (j != -1)
			primes[++nrp] = i;
	}

}

int main() {
	int nSol, nDivs, i;
	long long nNumber;

	ComputePrimes();

	while (scanf("%lld", &nNumber), nNumber) {
		nSol = -1; nDivs = 0;

		if (nNumber < 0)
			nNumber = -nNumber;
		
		for (i = 0; i < nrp && nNumber >= (long long)primes[i] * primes[i]; i++)
			if (!(nNumber % primes[i])) {
				nSol = i;
				nDivs++;

				do {
					nNumber /= primes[i];
				} while (!(nNumber % primes[i]));
			}

		if (nSol != -1)
			if (nNumber > 1)
				printf("%lld\n", nNumber);
			else if (nDivs > 1)
				printf("%d\n", primes[nSol]);
			else
				printf("-1\n");
		else 
			printf("-1\n");
	}

	return 0;
}
