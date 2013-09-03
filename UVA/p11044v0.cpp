/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11044 - Searching for Nessy                                      */


#include <stdio.h>

int div3(int n) {
	return (n - 2) / 3 + ((n - 2) % 3 != 0);
}

int main() {
	int nNoCases;

	for (scanf("%d", &nNoCases); nNoCases--; ) {
		int nN, nM;
		scanf("%d %d", &nN, &nM);
		printf("%d\n", div3(nN) * div3(nM));
	}
}