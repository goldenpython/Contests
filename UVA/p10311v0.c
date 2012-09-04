/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10311 - Goldbach and Euler                                       */



#include <stdio.h>
#include <math.h>

#define MAX				10101
#define NR_PRIMES		5000

int primes[NR_PRIMES], nrp;

void ComputePrimes() {
	int i, j, l;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[6] = 17;
	primes[nrp = 7] = 19;

	for (i = 23; i < MAX; i += 2) {
		l = (int)sqrt(i);
		for (j = 1; primes[j] <= l; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

		if (j != -1) {
			primes[++nrp] = i;
		}
	}
}

int IsPrime(int n) {
	int i, j, m, l;

	if (n == 1)
		return 0;

	if (n > primes[nrp]) {
		l = (int)sqrt(n);
		for (j = 0; primes[j] <= l; j++)
			if (!(n % primes[j])) {
				j = -1;
				break;
			}

		return (j == -1) ? 0 : 1;
	} else {
		i = 0; j = nrp;
		while (i <= j) {
			if (primes[m = (i + j) >> 1] > n)
				j = m - 1;
			else
				i = m + 1;
		}

		return primes[j] == n;
	}
}

int AtoINoSgn(char *szString) {
	int ret = 0;

	while (*szString) {
		ret = ret * 10 + *szString++ - '0';
	}

	return ret;
}

int main() {
	int n, i, sol;
	char szLine[16];

	ComputePrimes();

	while (gets(szLine)) {
		n = AtoINoSgn(szLine);

		if (!(n & 0x1)) {
			sol = 0;

			i = n / 2 - 1;
			if ((i & 0x1) == 0)
				i--;

			for (; i > 2; i -= 2)
				if (IsPrime(i) && IsPrime(n - i)) {
					printf("%d is the sum of %d and %d.\n", n, i, n - i);
					sol = 1;
					break;
				}

			if (sol)
				continue;

			printf("%d is not the sum of two primes!\n", n);
		} else {
			if (n > 2 && IsPrime(n - 2))
				printf("%d is the sum of %d and %d.\n", n, 2, n - 2);
			else
				printf("%d is not the sum of two primes!\n", n);
		}
	}

	return 0;
}
