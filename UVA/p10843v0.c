/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10843 - Anne's game                                              */


#include <stdio.h>

int main() {
	int nrcases, n, i, j;
	long long prod;
	
	scanf("%d", &nrcases);
	
	for (i = 0; i < nrcases; i++) {
		scanf("%d", &n);
		
		prod = 1;
		for (j = 0; j < n - 2; j++)
			prod = (prod * n) % 2000000011;
			
		printf("Case #%d: %d\n", i + 1, (int)prod);
	}
	
	return 0;
}
