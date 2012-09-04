/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10394 - Twin Primes                                              */



#include <stdio.h>
#include <math.h>

#define MAX				(20000010)
#define MAX_DIV_6		(20000010 / 6)
#define	MAX_SQRT		(4480)
#define MAX_NOPRIMES	240000
#define MAX_PAIRS		100003

int primes[MAX_NOPRIMES];
int nrp;

int pairs[MAX_PAIRS];

void ComputePrimes() {
	int i, j;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11; primes[5] = 13; primes[6] = 17; 
	primes[nrp = 7] = 19;

	for (i = 23; i < MAX_SQRT; i += 2) {
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

int IsPrime(int num) {
	int i, lim;

	lim = (int)sqrt(num) + 1;
	for (i = 1; i < nrp && primes[i] < lim; i++)
		if (!(num % primes[i]))
			return 0;

	return 1;
}

int AreBothPrimes(int num1, int num2) {
	int i, lim;

	lim = (int)sqrt(num2) + 1;
	for (i = 1; i < nrp && primes[i] < lim; i++)
		if (!(num1 % primes[i]) || !(num2 % primes[i]))
			return 0;

	return 1;
}

int main() {
	int i, j;
	ComputePrimes();

	pairs[0] = 3;
	j = 1;
	for (i = 1; i < MAX_DIV_6 && j < MAX_PAIRS; i++)
		/*if (IsPrime(i * 6 - 1) && IsPrime(i * 6 + 1)) */
		if (AreBothPrimes(i * 6 - 1, i * 6 + 1))
			pairs[j++] = i * 6 - 1;
		
	while (scanf("%d", &j) == 1) {
		printf("(%d, %d)\n", pairs[j - 1], pairs[j - 1] + 2); 
	}


	return 0;
}
