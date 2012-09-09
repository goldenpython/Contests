/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10168 - Summation of Four Primes                                 */



#include <stdio.h>
#include <math.h>

#define MAX_PRIMES		10000070
#define MAX_NOPRIMES	680000

int g_arrnPrimes[MAX_NOPRIMES];
int g_nNoPrimes;

void GenPrimes() {
	int i, j, lim; 
	g_arrnPrimes[0] = 2; g_arrnPrimes[1] = 3; g_arrnPrimes[2] = 5; g_arrnPrimes[3] = 7; g_arrnPrimes[4] = 11;
	g_nNoPrimes = 5;

	for (i = 13; i <= MAX_PRIMES; i += 2) {
		lim = (int) sqrt((double)i);
		for (j = 1; g_arrnPrimes[j] <= lim; j++)
			if (!(i % g_arrnPrimes[j])) {
				j = -1;
				break;
			}

		if (j != -1)
			g_arrnPrimes[g_nNoPrimes++] = i;
	}
}

int Find(int n) {
	int i = 0, j = g_nNoPrimes - 1, m; 

	while (i <= j)
		if (g_arrnPrimes[m = (i + j) >> 1] < n)
			i = m + 1;
		else
			j = m - 1;
	
	if (g_arrnPrimes[i] == n)
		return i;

	return -1;
}

int Find1(int n) {
	int i = 0, j = g_nNoPrimes - 1, m; 

	while (i <= j)
		if (g_arrnPrimes[m = (i + j) >> 1] < n)
			i = m + 1;
		else
			j = m - 1;

	if (g_arrnPrimes[i] == n)
		return i;
	
	return i - 1;
}

int main() {
	int nN, nLoop, nIndex;

	GenPrimes();

	while (scanf("%d", &nN) == 1) {
		if (nN % 2) {
			nN -= 2;
			nIndex = Find1(nN - 3);
			if (nIndex < 1) {
				printf("Impossible.\n");
				continue;
			} else {
				printf("2 %d ", g_arrnPrimes[nIndex]);
				nN -= g_arrnPrimes[nIndex];
			}
		} else {
			nIndex = Find1(nN / 2 - 2);
			if (nIndex != -1) {
				printf("%d %d ", g_arrnPrimes[nIndex], g_arrnPrimes[nIndex]);
				nN -= g_arrnPrimes[nIndex] * 2;
			} else {
				printf("Impossible.\n");
				continue;
			}
		}

		for (nLoop = 0; nLoop < g_nNoPrimes; nLoop++) {
			nIndex = Find(nN - g_arrnPrimes[nLoop]);
			if (nIndex != -1) {
				printf("%d %d\n", g_arrnPrimes[nLoop], g_arrnPrimes[nIndex]);
				break;
			}
		}

	}
}
