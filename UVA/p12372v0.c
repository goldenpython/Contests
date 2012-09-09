/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12372 - Packing for Holiday                                      */


#include <stdio.h>

int main() {
	int nNoCases, nCaseLoop, nW, nH, nL;

	scanf("%d", &nNoCases);
	for (nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		scanf("%d %d %d", &nW, &nH, &nL);
		if (nW > 20 || nH > 20 || nL > 20)
			printf("Case %d: bad\n", nCaseLoop);
		else
			printf("Case %d: good\n", nCaseLoop);
	}

	return 0;
}
