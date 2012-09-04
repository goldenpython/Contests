/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10392 - Factoring Large Numbers                                  */


#include <stdio.h>
#include <math.h>

#define MAX				1000010
#define MAX_NOPRIMES	80000

#define	MAX_FACTORS		200

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

long long AtoL(char *szString) {
	long long sgn = 1, ret = 0;
	
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
	char szLine[100];
	long long n, lim;
	int j, i, numfactors;
	long long factor[MAX_FACTORS], power[MAX_FACTORS];
	int cf[100], nrc;

	ComputePrimes();

	/* freopen("input/10392.txt", "rt", stdin); */

	while (1) {
		gets(szLine);
		n = AtoL(szLine);
		if (n == -1)
			return 0;
		
		numfactors = 0;
		lim = (long long)sqrt(n) + 1;
		for (i = 0; i <= nrp && primes[i] <= lim; i++) {
			if (!(n % primes[i])) {
				factor[numfactors] = primes[i];
				power[numfactors] = 0;

				do {
					power[numfactors]++;
					n /= primes[i];
				} while (!(n % primes[i]));

				lim = (long long)sqrt(n) + 1;

				numfactors++;
			}
		}

		for (i = 0; i < numfactors; i++) 
			for (j = 0; j < power[i]; j++)
				printf("    %u\n", factor[i]);	

		if (n != 1) {
			/* factor[numfactors] = n;
			power[numfactors] = 1;
			numfactors++; */
			printf("    ");
			nrc = 0;
			while (n) {
				cf[nrc++] = (int)(n % 10);
				n /= 10;
			}

			for (i = nrc - 1; i >= 0; i--)
				printf("%d", cf[i]);
			printf("\n");

		}	

		printf("\n");
	}

	return 0;
}
