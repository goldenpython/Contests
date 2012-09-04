/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10918 - Tri Tiling                                               */



#include <stdio.h>

#define MAX 31
	
int main() {
	int f[MAX], g[MAX];
	int i, n;

	f[0] = 1; f[1] = 0;
	g[0] = 0; g[1] = 1;

	for (i = 2; i < MAX; i++) {
		f[i] = f[i - 2] + g[i - 1] + g[i - 1];
		g[i] = f[i - 1] + g[i - 2];
	}


	while (scanf("%d", &n), n != -1)
		printf("%d\n", f[n]);

	return 0;
}
