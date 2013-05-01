/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12611 - Beautiful Flag                                           */


#include <stdio.h>

int main() {
	int nNoTestCases;

	scanf("%d", &nNoTestCases);
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nRadius;
		scanf("%d", &nRadius);

		int nW = nRadius * 5;
		int nH = nW * 3 / 10;
		int nX = -nW * 45 / 100;

		printf("Case %d:\n", nCaseLoop);
		printf("%d %d\n", nX, nH);
		printf("%d %d\n", nX + nW, nH);
		printf("%d %d\n", nX + nW, -nH);
		printf("%d %d\n", nX, -nH);
	}

	return 0;
}