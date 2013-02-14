/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12554 - A Special "Happy Birthday" Song!!!                       */

#include <stdio.h>


#define MAX_LINE_LEN	102

int gcd(int a, int b) {
	int r;

	while (b) {
		r = b;
		b = a % b;
		a = r;
	}

	return a;
}

int main() {
	int nN, nLoop, nLimit;
	char szLine[MAX_LINE_LEN];
	const char *arrszSongWords[] = {
		"Happy",
		"birthday",
		"to",
		"you",
		"Happy",
		"birthday",
		"to",
		"you",
		"Happy",
		"birthday",
		"to",
		"Rujia",
		"Happy",
		"birthday",
		"to",
		"you"
	};
	char arrszNames[MAX_LINE_LEN][MAX_LINE_LEN];
	const int nNoWords = sizeof(arrszSongWords) / sizeof(char *);


	sscanf(gets(szLine), "%d", &nN);
	for (nLoop = 0; nLoop < nN; nLoop++) 
		gets(arrszNames[nLoop]);


	nLimit = nNoWords <= nN ? ((nN % nNoWords) ? nN + (nNoWords - (nN % nNoWords)) : nN) : nNoWords;

	for (nLoop = 0; nLoop < nLimit; nLoop++)
		printf("%s: %s\n", arrszNames[nLoop % nN], arrszSongWords[nLoop % nNoWords]);

	return 0;
}