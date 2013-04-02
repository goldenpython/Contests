/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11340 - Newspaper                                                */


#include <stdio.h>
#include <string.h>

int main() {
	const int MAX_LINE_LEN = 1024 * 10;

	int nNoTestCases;
	int arrnCharCost[256];
	char szLine[MAX_LINE_LEN];


	for (gets(szLine), sscanf(szLine, "%d", &nNoTestCases); nNoTestCases--; ) {
		memset(arrnCharCost, 0, sizeof(arrnCharCost));

		int nNoLetters;
		for (gets(szLine), sscanf(szLine, "%d", &nNoLetters); nNoLetters--; ) {

			char cChar;
			int nCharCost;
			gets(szLine); sscanf(szLine, "%c %d", &cChar, &nCharCost);
			arrnCharCost[cChar & 0xFF] = nCharCost;
		}

		int nNoLines, nCost = 0;
		for (gets(szLine), sscanf(szLine, "%d", &nNoLines); nNoLines--; ) {
			for (unsigned char *psz = (unsigned char *) gets(szLine); *psz; psz++)
				nCost += arrnCharCost[*psz];
		}

		printf("%d.%02d$\n", nCost / 100, nCost % 100);
	}


	return 0;
}