/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12289 - One-Two-Three                                            */



#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN	16

int main() {
	int nNoCases, nDiffOne, nDiffTwo, nLoop;
	char szLine[MAX_LINE_LEN];
	char *szOne = "one";
	char *szTwo = "two";

	for (sscanf(gets(szLine), "%d", &nNoCases); nNoCases; nNoCases--) {
		gets(szLine);
		if (strlen(szLine) == 3) {
			for (nLoop = nDiffOne = nDiffTwo = 0; nLoop < 3; nLoop++) {
				if (szLine[nLoop] != szOne[nLoop])
					nDiffOne++;
				if (szLine[nLoop] != szTwo[nLoop])
					nDiffTwo++;
			}
			printf(nDiffOne < nDiffTwo ? "1\n" : "2\n");
		} else {
			printf("3\n");
		}
	}

	return 0;
}
