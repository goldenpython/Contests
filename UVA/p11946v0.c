/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>

#define MAX_LINE_LEN	128

int main() {
	char arrcChangedLetters[256] = {0};
	char *psz, szLine[MAX_LINE_LEN];
	int nLoop;

	for (nLoop = 0; nLoop < 256; nLoop++)
		arrcChangedLetters[nLoop] = nLoop;

	arrcChangedLetters['3'] = 'E';
	arrcChangedLetters['0'] = 'O';
	arrcChangedLetters['1'] = 'I';
	arrcChangedLetters['4'] = 'A';
	arrcChangedLetters['9'] = 'P';
	arrcChangedLetters['8'] = 'B';
	arrcChangedLetters['5'] = 'S';
	arrcChangedLetters['7'] = 'T';
	arrcChangedLetters['2'] = 'Z';
	arrcChangedLetters['6'] = 'G';


	gets(szLine);

	while (gets(szLine)) {
		for (psz = szLine; *psz; psz++)
			*psz = arrcChangedLetters[*psz];
		puts(szLine);
	}

	return 0;
}
