/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10924 - Prime Words                                              */


#include <stdio.h>
#include <math.h>

#define MAX	1500
#define NR_PRIMES 1050

int primes[NR_PRIMES], nrp;

void ComputePrimes() {
	int i, j, l;
	/*primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[6] = 17; primes[nrp = 7] = 19;*/
	primes[0] = 1; primes[1] = 2; primes[2] = 3; primes[3] = 5; primes[4] = 7; primes[5] = 11; primes[6] = 13; primes[nrp = 7] = 17;

	for (i = 19; i < MAX; i += 2) {
		int l = sqrt(i);
		for (j = 1; primes[j] <= l; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

			if (j != -1)
				primes[++nrp] = i;
	}

}

void Solve(char *line) {
	int i = 0, j = nrp - 1, nr = 0, m;
	char *p;

	for (p = line; *p; p++)
		nr += (*p >= 'a' && *p <= 'z') ? *p - 'a' + 1 : *p - 'A' + 27;


	while (i <= j)
		if (primes[m = (i + j) >> 1] < nr)
			i = m + 1;
		else
			j = m - 1;


/* 	i = j;
	for ( ; i >= 0; i--) {
		x = primes[i];
		p = nr / x;
		aux = nr - x * p;
		if (max < aux) {
			max = aux;
			sol = i;
		}
	} */

	if (primes[i] == nr)
		printf("It is a prime word.\n");
	else
		printf("It is not a prime word.\n");
}

int main() {
	char line[25];
	ComputePrimes();

	while (gets(line)) {
		Solve(line);
	}

	return 0;
}
