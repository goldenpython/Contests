/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10930 - A-Sequence                                               */


#include <stdio.h>
#include <string.h>

#define MAX		35
#define MAXS	(MAX * 2005)

int main() {
	int n, nr[MAX], nrcase = 0, sol, i, j;
	int d[MAXS], max;

	while (scanf("%d", &n) == 1) {
		nrcase++;
		for (i = 0; i < n; i++)
			scanf("%d", nr + i);

		sol = 1;
		printf("Case #%d: ", nrcase);
		for (i = 0; i < n; i++) {
			if (i == n - 1)
				printf("%d", nr[i]);
			else
				printf("%d ", nr[i]);
			if (i > 0)
				if (nr[i - 1] >= nr[i]) 
					sol = 0;
				else
					;
			else if (nr[0] < 1)
				sol = 0;
		}
		printf("\n");
				
		if (!sol) {
			printf("This is not an A-sequence.\n");
			continue;
		}

		sol = 1;
		for (i = 0; i < MAXS; i++)
			d[i] = -1;
		d[0] = d[nr[0]] = 0;

		max = nr[0];
		for (i = 1; i < n; i++) {
			if (d[nr[i]] != -1) {
				sol = 0;
				break;
			}

			for (j = 0; j <= max; j++)
				if (d[j] != -1 && d[j] < i && d[j + nr[i]] == -1) {
					d[j + nr[i]] = i;
					if (j + nr[i] > max)
						max = j + nr[i];
				}
		}

		if (!sol) {
			printf("This is not an A-sequence.\n");
		} else {
			printf("This is an A-sequence.\n");
		}
	}
}
