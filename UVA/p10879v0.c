/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10879 - Code Refactoring                                         */



#include <stdio.h>
#include <math.h>

#define MAX	3170 /*3163*/
#define NR_PRIMES 1500

int primes[NR_PRIMES], nrp;

void ComputePrimes() {
	int i, j;
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; 
	primes[4] = 11; primes[5] = 13; primes[6] = 17; primes[nrp = 7] = 19;

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

int AtoINoSgn(char *szString) {
	int ret = 0;
		
	while (*szString) {
		ret = ret * 10 + *szString++ - '0'; 
	}
	
	return ret;
}

int ATOI_RET;
#define ATOI_NO_SGN(szString)	{ ATOI_RET = 0; while (*szString) ATOI_RET = ATOI_RET * 10 + *szString++ - '0'; }

int main() {
	int nrcases, i, n, nn, j, numdiv, A, B, C, D;
	int factor[50], pow[50], nrf;
	char *p, szLine[50];


	ComputePrimes();

	gets(szLine); p = szLine; ATOI_NO_SGN(p); nrcases = ATOI_RET;
	for (i = 1; i <= nrcases; i++) {
		gets(szLine); p = szLine; ATOI_NO_SGN(p); n = ATOI_RET;
		nn = n;

		nrf = 0; numdiv = 0;
		for (j = 0; j < nrp && n > 1 && numdiv < 2; j++) {
			if (n % primes[j] == 0) {
				factor[nrf] = primes[j];
				pow[nrf] = 0;

				do {
					n /= primes[j];
					pow[nrf]++;
					numdiv++;
				} while (n % primes[j] == 0 && numdiv < 2);

				nrf++;
			}
		}

		if (n != 1) {
			factor[nrf] = n;
			pow[nrf] = 1;
			nrf++;
		}

		A = factor[0];
		B = nn / factor[0];

		if (pow[0] > 1) {
			C = factor[0] * factor[0];
			D = nn / C;
		} else {
			C = factor[1];
			D = nn / factor[1];
		}

		printf("Case #%d: %d = %d * %d = %d * %d\n", i, nn, A, B, C, D);

	}

	return 0;
}
