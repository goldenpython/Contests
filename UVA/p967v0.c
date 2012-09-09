/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 967 - Circular                                                   */


#include <stdio.h>
#include <math.h>

#define MAX				1000001
#define NR_PRIMES		79000
#define MAX_FACTORS		70


int primes[NR_PRIMES], nrp;

int isprime[MAX], isprime1[MAX];

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

		if (j != -1) {
			primes[++nrp] = i;
		}
	}

}

int main() {
	int i, nrc, lim, nr[7], num, num1, num2, j, l1, l2, lim10, *p, *q, *l;
	char a[20];

	ComputePrimes();

	for (i = 0; i <= nrp; i++)
		isprime[primes[i]] = 1;

	nrc = 1; lim = 10; lim10 = 1;
	for (i = 0; i < nrp; i++) {
		num = primes[i];
		if (num >= lim) {
			nrc++;
			lim *= 10;
			lim10 *= 10;
		}

		if (isprime[num] == 1 && !isprime1[num]) {
			nr[0] = num; 
			num1 = 1; num2 = 0;
			for (j = 1; j < nrc; j++) {
				nr[j] = nr[j - 1] / 10 + (nr[j - 1] % 10) * lim10;
				if (isprime[nr[j]])
					num1++;
			}

			 if (num1 != nrc)
				isprime1[num] = 0;
			else  
				isprime1[num] = 1;
		}

	}
/*
	for (i = 1; i < MAX; i++) {
		isprime[i] = isprime[i - 1] + (isprime[i] == 3); 
		isprime[i] = isprime[i] == 3 ? isprime[i - 1] + 1 : isprime[i - 1]; i++; 

		isprime[i] = isprime[i - 1] + (isprime[i] & 0x1);

	} */

	for (i = 1; i < MAX; i++) {
		isprime1[i] += isprime1[i - 1];
	} 



	while (scanf("%d %d", &l1, &l2) == 2) {
		num = isprime1[l2] - isprime1[l1 - 1];
		if (!num)
			printf("No Circular Primes.\n");
		else if (num == 1)
			printf("1 Circular Prime.\n");
		else {
			printf("%d Circular Primes.\n", num);
		}
	}

	return 0;
}
