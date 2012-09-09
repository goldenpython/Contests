/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10192 - Vacation                                                 */


#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE	128

int main() {
	int nSizeMother, nSizeFather, nLoop1, nLoop2, nCaseLoop = 0;
	char szMother[MAX_STRING_SIZE], szFather[MAX_STRING_SIZE];
	int arr2nSol[MAX_STRING_SIZE][MAX_STRING_SIZE];

	while (gets(szMother) && *szMother != '#' && gets(szFather)) {
		nSizeMother = (int)strlen(szMother); nSizeFather = (int)strlen(szFather);

		memset(arr2nSol, 0, sizeof(arr2nSol));

		for (nLoop1 = 1; nLoop1 <= nSizeMother; nLoop1++)
			for (nLoop2 = 1; nLoop2 <= nSizeFather; nLoop2++)
				if (szMother[nLoop1 - 1] == szFather[nLoop2 - 1]) {
					arr2nSol[nLoop1][nLoop2] = arr2nSol[nLoop1 - 1][nLoop2 - 1] + 1;
				} else {
					if (arr2nSol[nLoop1 - 1][nLoop2] > arr2nSol[nLoop1][nLoop2 - 1])
						arr2nSol[nLoop1][nLoop2] = arr2nSol[nLoop1 - 1][nLoop2];
					else
						arr2nSol[nLoop1][nLoop2] = arr2nSol[nLoop1][nLoop2 - 1];
				}

		printf("Case #%d: you can visit at most %d cities.\n", ++nCaseLoop, arr2nSol[nSizeMother][nSizeFather]);
	}

	return 0;
}
