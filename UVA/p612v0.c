/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 612 - DNA Sorting                                                */

/*   http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=553 */



#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN	52
#define MAX_STRINGS		100

struct STRING_STRUCT {
	char szString[MAX_LINE_LEN];
	int arrnStringInt[MAX_LINE_LEN];
	int arr2nCount[MAX_LINE_LEN][4];
	int arrnSol[MAX_LINE_LEN];

	int nSol, nSelfIndex;
};

int arrnIndex[MAX_STRINGS];
struct STRING_STRUCT arroStrings[MAX_STRINGS];

void QSort(int lo, int hi) {
	int i = lo, j = hi;
	struct STRING_STRUCT *pMid = &arroStrings[arrnIndex[(i + j) >> 1]];
	int aux;

	do {
		while (arroStrings[arrnIndex[i]].nSol < pMid->nSol || (arroStrings[arrnIndex[i]].nSol == pMid->nSol && arroStrings[arrnIndex[i]].nSelfIndex < pMid->nSelfIndex))
			i++;

		while (arroStrings[arrnIndex[j]].nSol > pMid->nSol || (arroStrings[arrnIndex[j]].nSol == pMid->nSol && arroStrings[arrnIndex[j]].nSelfIndex > pMid->nSelfIndex))
			j--;

		if (i <= j) {
			aux = arrnIndex[i];
			arrnIndex[i] = arrnIndex[j];
			arrnIndex[j] = aux;

			i++; j--;
		}
	} while (i <= j);

	if (j > lo)
		QSort(lo, j);

	if (i < hi)
		QSort(i, hi);
}

int main() {
	int nNoTestCases, nN, nM, nLoop, nLoopString, nLoopChar;
	char *psz;
	char szLine[MAX_LINE_LEN];
	int arrnCharMap[256];

	memset(arrnCharMap, 0, sizeof(arrnCharMap));
	arrnCharMap['A'] = 0;
	arrnCharMap['C'] = 1;
	arrnCharMap['G'] = 2;
	arrnCharMap['T'] = 3;

	for (sscanf(gets(szLine), "%d", &nNoTestCases); nNoTestCases; nNoTestCases--) {
		gets(szLine);
		sscanf(gets(szLine), "%d %d", &nN, &nM);
		memset(arroStrings, 0, nM * sizeof(struct STRING_STRUCT));
		for (nLoop = 0; nLoop < nM; nLoop++) {
			psz = gets(arroStrings[nLoop].szString);

			arroStrings[nLoop].arrnStringInt[0] = arrnCharMap[psz[0]];
			arroStrings[nLoop].arr2nCount[0][arroStrings[nLoop].arrnStringInt[0]] = 1;


			for (nLoopString = 1; nLoopString < nN; nLoopString++) {
				arroStrings[nLoop].arrnStringInt[nLoopString] = arrnCharMap[psz[nLoopString]];
				for (nLoopChar = 0; nLoopChar < 4; nLoopChar++)
					arroStrings[nLoop].arr2nCount[nLoopString][nLoopChar] += arroStrings[nLoop].arr2nCount[nLoopString - 1][nLoopChar];
				arroStrings[nLoop].arr2nCount[nLoopString][arroStrings[nLoop].arrnStringInt[nLoopString]]++;

				for (nLoopChar = arroStrings[nLoop].arrnStringInt[nLoopString] + 1; nLoopChar < 4; nLoopChar++)
					arroStrings[nLoop].arrnSol[nLoopString] += arroStrings[nLoop].arr2nCount[nLoopString - 1][nLoopChar];

				arroStrings[nLoop].nSol += arroStrings[nLoop].arrnSol[nLoopString];

			}

/*
			for (nLoopString = 0; nLoopString < nN; nLoopString++) 
				for (nLoopChar = nLoopString + 1; nLoopChar < nN; nLoopChar++)
					if (arroStrings[nLoop].szString[nLoopString] > arroStrings[nLoop].szString[nLoopChar])
						arroStrings[nLoop].nSol++;
*/

			arroStrings[nLoop].nSelfIndex = nLoop;
		}

		for (nLoop = 0; nLoop < nM; nLoop++)
			arrnIndex[nLoop] = nLoop;

		QSort(0, nM - 1);

		for (nLoop = 0; nLoop < nM; nLoop++)
			printf("%s\n", arroStrings[arrnIndex[nLoop]].szString);


		if (nNoTestCases > 1)
			printf("\n");

	}
	
	return 0;
}