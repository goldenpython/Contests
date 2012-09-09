/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 543 - Goldbach's Conjecture                                      */


#include <stdio.h>
#include <math.h>

#define MAX		1000010
#define MAX_P	80000

int primes[MAX_P], nrp;

void ComputePrimes() {
	int i, j, l;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[nrp = 6] = 17;

	for (i = 19; i <= MAX; ) {

		l = (int)sqrt(i);
		for (j = 2; primes[j] <= l; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}
		if (j != -1)
			primes[++nrp] = i;
		i += 4;

		l = (int)sqrt(i);
		for (j = 2; primes[j] <= l; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}
		if (j != -1)
			primes[++nrp] = i;
		i += 2;
	}
}

int Find(int n) {
	int i = 0, j = nrp, m; 

	while (i <= j)
		if (primes[m = (i + j) >> 1] < n)
			i = m + 1;
		else
			j = m - 1;
	
	if (primes[i] == n)
		return i;

	return -1;
}

int AtoINoSgn(char *szString) {
	int ret = 0;

	while (*szString) {
		ret = ret * 10 + *szString++ - '0'; 
	}

	return ret;
}

int main() {
	char szLine[32];
	int n, nn, nhalf, loop, i, j, m;

	ComputePrimes();

	while (gets(szLine), n = AtoINoSgn(szLine)) {
		nhalf = (n + 1) >> 1;
		for (loop = 1; loop < nrp && primes[loop] <= nhalf; loop++) {
			i = 0; j = nrp; 
			nn = n - primes[loop];

			while (i <= j)
				if (primes[m = (i + j) >> 1] < nn)
					i = m + 1;
				else
					j = m - 1;

			if (primes[i] == nn) {
				printf("%d = %d + %d\n", n, primes[loop], n - primes[loop]);
				break;
			}
		}
	}

	return 0;
}
