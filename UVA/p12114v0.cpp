/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12114 - Bachelor Arithmetic                                      */


#include <stdio.h>

int main() {
	int nB, nS, nCaseNumber = 1;

	while (scanf("%d %d", &nB, &nS), nB || nS) {
		if (nB <= 1)
			printf("Case %d: :-\\\n", nCaseNumber);
		else if (nB > nS) 
			printf("Case %d: :-(\n", nCaseNumber);
		else
			printf("Case %d: :-|\n", nCaseNumber);

		nCaseNumber++;
	}


	return 0;
}