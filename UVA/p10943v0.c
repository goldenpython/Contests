/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10943 - How do you add?                                          */


#include <stdio.h>
#include <math.h>

#define MAX		205
#define MAX_P	60

int primes[MAX_P], power[MAX_P], nrp;

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
	int n, k, i, j, aux;

	ComputePrimes();

	while (scanf("%d %d", &n, &k), n || k) {
		/* if (n < k) {
			printf("0\n");
			continue;
		} */

		n += k - 1;
		k--;

		memset(power, 0, sizeof(power));
		for (i = k + 1; i <= n; i++) {
			aux = i;

			for (j = 0; j <= nrp && aux != 1; j++) {
				while (aux && !(aux % primes[j])) {
					power[j]++;
					aux /= primes[j];
				}
			}
		}

		for (i = 1; i <= n - k; i++) {
			aux = i;

			for (j = 0; j <= nrp && aux != 1; j++) {
				while (aux && !(aux % primes[j])) {
					power[j]--;
					aux /= primes[j];
				}
			}
		}

		aux = 1;
		for (i = 0; i < nrp; i++)
			for (j = 0; j < power[i]; j++) {
				aux *= primes[i];
				aux %= 1000000;
			}

		printf("%d\n", aux);
	}
	return 0;
}
