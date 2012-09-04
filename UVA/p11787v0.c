/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN	512

int main() {
	int nCases, nSol, nLastCharOccurences, nError, nDir;
	int arrnMap[256];
	char cLastChar;
	char *psz, szLine[MAX_LINE_LEN];

	memset(arrnMap, 0, sizeof(arrnMap));
	arrnMap['B'] = 1;
	arrnMap['U'] = 10;
	arrnMap['S'] = 100;
	arrnMap['P'] = 1000;
	arrnMap['F'] = 10000;
	arrnMap['T'] = 100000;
	arrnMap['M'] = 1000000;

	for (nCases = atoi(gets(szLine)); nCases--; ) {
		gets(szLine);

		cLastChar = *szLine;
		nLastCharOccurences = 1;

		for (psz = szLine + 1, nSol = nError = nDir = 0; *psz; psz++) {
			if (*psz == cLastChar) {
				nLastCharOccurences++;
			} else {
				if (nLastCharOccurences > 9) {
					nError = 1;
					break;
				}

				if (arrnMap[*psz] - arrnMap[cLastChar] > 0) {
					if (nDir == -1) {
						nError = 1;
						break;
					} else {
						nDir = 1;
					}
				} else {
					if (nDir == 1) {
						nError = 1;
						break;
					} else {
						nDir = -1;
					}

				}

				nSol += arrnMap[cLastChar] * nLastCharOccurences;
				cLastChar = *psz; 
				nLastCharOccurences = 1;
			}
		}

		if (nLastCharOccurences > 9) {
			nError = 1;
		}


		if (nError)
			printf("error\n");
		else {
			nSol += arrnMap[cLastChar] * nLastCharOccurences;
			printf("%d\n", nSol);
		}
	}

	return 0;
}
