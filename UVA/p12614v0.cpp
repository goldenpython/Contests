/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12614 - Earn For Future                                          */


#include <stdio.h>

int main() {
	int nNoTestCases;

	scanf("%d", &nNoTestCases);
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nNoNumbers, nSol = 0;

		for (scanf("%d", &nNoNumbers); nNoNumbers; nNoNumbers--) {
			int nNumber;

			scanf("%d", &nNumber);
			if (nSol < nNumber)
				nSol = nNumber;
		}
		
		printf("Case %d: %d\n", nCaseLoop, nSol);
	}
}