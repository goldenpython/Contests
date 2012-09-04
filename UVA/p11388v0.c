/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11388 - GCD LCM                                                  */



#include <stdio.h>

int main() {
	int nGCD, nLCM, nCaseLoop;

	for (scanf("%d", &nCaseLoop); nCaseLoop; nCaseLoop--) {
		scanf("%d %d", &nGCD, &nLCM);
		if (nLCM % nGCD)
			printf("-1\n");
		else
			printf("%d %d\n", nGCD, nLCM);
	}

	return 0;
}
