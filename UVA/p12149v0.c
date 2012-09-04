/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>

#define MAX	102

int main() {
	int nN;
	int arrnSol[MAX];

	arrnSol[0] = 0;
	for (nN = 1; nN < MAX; nN++)
		arrnSol[nN] = nN * nN + arrnSol[nN - 1];

	while (scanf("%d", &nN), nN) {
		printf("%d\n", arrnSol[nN]);
	}

	return 0;
}
