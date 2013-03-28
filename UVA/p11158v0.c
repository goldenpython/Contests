/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11158 - Elegant Permuted Sum                                     */


#include <stdio.h>
#include <string.h>

#define MAX_NUMBERS 60

#define ABS(a)		((a) > 0 ? (a) : -(a))

int main() {
	int nrcases;
	int n, i, j, l, max, mindif, sum, last, dif, sol, lastnr, *pint, *pintlim;
	int nr[MAX_NUMBERS], nr1[MAX_NUMBERS];
	char used[MAX_NUMBERS], *k, *klim, *index;
	char *p, szLine[500];

	/* freopen("1.txt", "rt", stdin); */
	
	/* scanf("%d", &nrcases); */
	gets(szLine); nrcases = atoi(szLine);

	for (i = 0; i < nrcases; i++) {
		/* scanf("%d", &n); */
		gets(szLine);
		p = strtok(szLine, " ");
		n = atoi(p);

		for (j = 0; j < n; j++) {
			/* scanf("%d", &nr[j]); */ 
			p = strtok(NULL, " ");
			nr[j] = atoi(p);
		}

		pintlim = nr + n;
		klim = used + n;

		sol = -1000000;
		for (j = 0; j < n / 2; j++) {
			memset(used, 0, sizeof(char) * n);
			used[j] = 1;
			lastnr = nr1[0] = nr[last = j];
			sum = 0;

			mindif = 1000000;
			for (l = 0; l < n - 1; l++) {				
				max = -1;				

				/* for (k = 0; k < n; k++) */
				for (k = used, pint = nr; k < klim; k++, pint++)
					if (!*k) {
						dif = lastnr - *pint;
						dif = ABS(dif);
						if (dif > max) {
							max = dif;
							index = k; 
						}
					}

				if (max < mindif)
					mindif = max;

				sum += max;
				/* last = index; */
				*index = 1;
				lastnr = nr1[l + 1] = nr[index - used];
			}

			if (ABS(nr1[0] - nr1[n - 1]) > mindif)
				sum = sum - mindif + ABS(nr1[0] - nr1[n - 1]);

			if (sol < sum)
				sol = sum;
		}
			
		
		printf("Case %d: %d\n", i + 1, sol);
	}
}
