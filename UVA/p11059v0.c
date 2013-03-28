/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11059 - Maximum Product                                          */



#include <stdio.h>
#include <string.h>


int main() {
	int n, i, j, k, nr[20], zeros[20], nrzeros, nrcase = 0, haspositives;
	long long prods[20], prod, maxprod;
	int l1, l2;

	while (scanf("%d", &n) == 1) {
		nrcase++;

		nrzeros = 1; zeros[0] = 0; haspositives = 0;

		nr[0] = 0;
		for (i = 1; i <= n; i++) {
			scanf("%d", &nr[i]);
			if (nr[i] > 0)
				haspositives = 1;
			else if (nr[i] == 0)
				zeros[nrzeros++] = i;
		}
		
		zeros[nrzeros++] = ++n;

		if (n == 1) {
			printf("Case #%d: The maximum product is %d.\n\n", nrcase, (long long)(nr[0] > 0 ? nr[0] : 0));
			continue;
		}

		maxprod = 0;
		for (i = 0; i < nrzeros - 1; i++) {
			l1 = zeros[i], l2 = zeros[i + 1];

			prods[l1] = 1;
			for (j = l1 + 1; j < l2; j++)
				prods[j] = prods[j - 1] * nr[j];
			
			for (j = l1; j < l2; j++)
				for (k = j + 1; k < l2; k++) {
					prod = prods[k] / prods[j];
					if (maxprod < prod)
						maxprod = prod;
				}
		}

		
		
		printf("Case #%d: The maximum product is ", nrcase);

		if (maxprod) {
			for (i = 0; maxprod; i++)
				nr[i] = maxprod % 10, maxprod /= 10;

			for (i--; i >= 0; i--)
				printf("%d", nr[i]);
		} else
			printf("0");

		printf(".\n\n"); 
	}
}
