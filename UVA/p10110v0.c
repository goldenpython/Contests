/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10110 - Light, more light                                        */



#include <stdio.h>
#include <math.h>

#define MAX			65637
#define NR_PRIMES	(1024 * 7)

unsigned int primes[NR_PRIMES], nrp;


void ComputePrimes() {
	int i, j, lim;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[6] = 17; 
	primes[nrp = 7] = 19;

	for (i = 23; i < MAX; ) {
		lim = sqrt(i);
		for (j = 2; primes[j] <= lim; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			primes[++nrp] = i;

		i += 2;
		lim = sqrt(i);
		for (j = 2; primes[j] <= lim; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			primes[++nrp] = i;

		i += 4;
	}

}

unsigned int AtoUINoSgn(char *szString) {
	unsigned int ret = 0;

	while (*szString) {
		ret = ret * 10 + *szString++ - '0'; 
	}

	return ret;
}

int main() {
	char szLine[128];
	unsigned int n, i, nrdiv, pow, lim;

	ComputePrimes();

	while (1) {
		gets(szLine);
		n = AtoUINoSgn(szLine);
		if (!n)
			return 0;

		nrdiv = 1;
		lim = sqrt(n);
		for (i = 0; n > 1 && primes[i] <= lim && nrdiv & 0x1; i++) {
			pow = 0;
			while (!(n % primes[i])) {
				n /= primes[i];
				pow++;
			}

			nrdiv *= pow + 1;
		}

		if (n != 1)
			nrdiv *= 2;

		if (nrdiv & 0x1)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
