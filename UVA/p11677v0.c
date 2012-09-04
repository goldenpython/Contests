/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>

int main() {
	int nH1, nM1, nH2, nM2;

	while (scanf("%d %d %d %d", &nH1, &nM1, &nH2, &nM2), nH1 || nM1 || nH2 || nM2)
		printf("%d\n", (24 * 60 - nH1 * 60 - nM1 + nH2 * 60 + nM2) % (24 * 60));

	return 0;
}
