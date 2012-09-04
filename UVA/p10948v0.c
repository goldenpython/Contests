/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10948 - The primary problem                                      */



#include <stdio.h>
#include <math.h>

#define MAX		1000010
#define MAX_P	80000

int primes[MAX_P], nrp;

void ComputePrimes() {
	int i, j, l;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[nrp = 6] = 17;

	for (i = 19; i <= MAX; i += 2) {
		l = sqrt(i);
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
	int n, i, j, m, loop;

	ComputePrimes();

	while (scanf("%d", &n), n) {
		if (n % 2) {
			n -= 2;
			i = 0; j = nrp; 
			while (i <= j)
				if (primes[m = (i + j) >> 1] < n)
					i = m + 1;
				else
					j = m - 1;
			if (primes[i] == n)
				printf("%d:\n%d+%d\n", n + 2, 2, n);
			else
				printf("%d:\nNO WAY!\n", n + 2);
		} else {
			for (loop = 0; (primes[loop] << 1) <= n; loop++) {
				n -= primes[loop];
				i = 0; j = nrp; 
				while (i <= j)
					if (primes[m = (i + j) >> 1] < n)
						i = m + 1;
					else
						j = m - 1;

				if (primes[i] == n) {
					printf("%d:\n%d+%d\n", n + primes[loop], primes[loop], n);
					loop = -1;
					break;
				} else
					n += primes[loop];
			}

			/* if (loop != -1) {
				printf("%dNO WAY!\n");
			} */
		}
	}
}
