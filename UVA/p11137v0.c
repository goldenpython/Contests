/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11137 - Ingenuous Cubrency                                       */


#include <stdio.h>
#include <string.h>

#define MAX 10001
#define LOOP_UNROLL_FACTOR 64
#define MAX_COINS 21


int n, i, j;
long long sum[MAX + LOOP_UNROLL_FACTOR], nn, *lim, *pj, *pk;
int coins[MAX_COINS + 1];
char result[100];

int main() {

	for (i = 1; i <= MAX_COINS; i++)
		coins[i] = i * i * i;

	for (pj = sum, lim = sum + MAX; pj <= lim; *pj++ = 1);

	for (i = 2; i <= MAX_COINS; i++) {
		lim = sum + MAX - coins[i];
		for (pj = sum, pk = pj + coins[i]; pj <= lim; ) {
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;

			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;

			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;

			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;

			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;

			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;

			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;

			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
			*pk++ += *pj++;
		}
	}

	while (gets(result)) {
		n = atoi(result);

		nn = sum[n];

		i = nn % 1000000;
		j = nn / 1000000;

		if (j)
			printf("%d%06d\n", j, i);
		else
			printf("%d\n", i);
	}

	return 0;
}
