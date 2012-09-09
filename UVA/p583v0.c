/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 583 - Prime Factors                                              */


#include <stdio.h>
#include <math.h>

#define MAX				46350
#define MAX_NOPRIMES	5000

int primes[MAX_NOPRIMES];
int nrp;

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

int AtoI(char *szString) {
	int sgn = 1, ret = 0;

	if (*szString == '-') {
		sgn = -1;
		szString++;
	} else if (*szString == '+')
		szString++;

	while (*szString) {
		ret = ret * 10 + *szString++ - '0'; 
	}

	return ret * sgn;
}


int main() {
	char szLine[64];
	int n, i, j, lim, count, firstfactor;

	ComputePrimes();

	while (gets(szLine), n = AtoI(szLine)) {
		printf("%d =", n);

		if (n < 0) {
			printf(" -1");
			n = -n;
			firstfactor = 0;
		} else
			firstfactor = 1;

		lim = sqrt(n) + 1;
		for (i = 0; primes[i] < lim; i++)
			if (!(n % primes[i])) {
				count = 0;

				do {
					count++;
					n /= primes[i];					
				} while (!(n % primes[i]));

				if (!firstfactor) {
					for (j = 0; j < count; j++)
						printf(" x %d", primes[i]);
				} else {
					for (j = 0; j < count - 1; j++)
						printf(" %d x", primes[i]);

					printf(" %d", primes[i]);
					firstfactor = 0;
				}

				lim = sqrt(n) + 1;
			}

 		if (n != 1)
			if (firstfactor)
				printf(" %d", n);
			else
				printf(" x %d", n);

		printf("\n");
	}

	return 0;
}
