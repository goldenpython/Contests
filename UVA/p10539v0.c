/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10539 - Almost Prime Numbers                                     */



#include <stdio.h>
#include <math.h>

#define MAX_PRIMES		1000007
#define MAX_NOPRIMES	80000

int primes[MAX_NOPRIMES];
int nrprimes;

void GenPrimes() {
	int i, j, lim; 
	primes[0] = 2; primes[1] = 3; primes[2] = 5; primes[3] = 7; primes[4] = 11;
	nrprimes = 5;

	for (i = 13; i <= MAX_PRIMES; i += 2) {
		lim = (int) sqrt(i);
		for (j = 1; primes[j] <= lim; j++)
			if (!(i % primes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			primes[nrprimes++] = i;
	}
}

int Find(int n) {
	int i = 0, j = nrprimes, m; 

	while (i <= j)
		if (primes[m = (i + j) >> 1] < n)
			i = m + 1;
		else
			j = m - 1;
	
	if (primes[i] == n)
		return i;

	return i;
}

int Find1(int n) {
	int i = 0, j = nrprimes, m; 

	while (i <= j)
		if (primes[m = (i + j) >> 1] < n)
			i = m + 1;
		else
			j = m - 1;
	
	if (primes[i] == n)
		return i;

	return i - 1;
}

int main() {
	int nNoCases, nSol, nBaseLoop, nFromBase, nToBase;
	long long llTo, llFrom;

	GenPrimes();

	for (scanf("%d", &nNoCases); nNoCases; nNoCases--) {
		scanf("%lld %lld", &llFrom, &llTo);

		nSol = 0;
		for (nBaseLoop = 2; ; nBaseLoop++) {
			nFromBase = ceil(exp(log((double)llFrom) / nBaseLoop) - 1E-10);
			nToBase = floor(exp(log((double)llTo) / nBaseLoop) + 1E-10);

			if (nToBase == 1)
				break;

			nFromBase = Find(nFromBase);
			nToBase = Find1(nToBase);

			nSol += nToBase - nFromBase + 1;
		}

		printf("%d\n", nSol);
	}

	return 0;
}
