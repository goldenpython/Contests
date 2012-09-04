/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11223 - O: dah dah dah!                                          */


#include <stdio.h>
#include <string.h>


#define MAX_LINE_LEN	2048

#define MORSE2INT(szMorse, pszIterator, nResult) \
{ \
	nResult = 1; \
	for (pszIterator = szMorse; *pszIterator; pszIterator++) \
		nResult = nResult * 2 + (*pszIterator == '.'); \
} \

#define MORSE2INT_2(szMorse, pszIterator, nResult) \
{ \
	nResult = 1; \
	for (pszIterator = szMorse; *pszIterator && *pszIterator != ' '; pszIterator++) \
		nResult = nResult * 2 + (*pszIterator == '.'); \
} \

void InitTable(int *arrnMorseTable) {
	char *psz;
	int nIndex;
	
	MORSE2INT(".-", psz, nIndex); arrnMorseTable[nIndex] = 'A';
	MORSE2INT("-...", psz, nIndex); arrnMorseTable[nIndex] = 'B';
	MORSE2INT("-.-.", psz, nIndex); arrnMorseTable[nIndex] = 'C';
	MORSE2INT("-..", psz, nIndex); arrnMorseTable[nIndex] = 'D';
	MORSE2INT(".", psz, nIndex); arrnMorseTable[nIndex] = 'E';
	MORSE2INT("..-.", psz, nIndex); arrnMorseTable[nIndex] = 'F';
	MORSE2INT("--.", psz, nIndex); arrnMorseTable[nIndex] = 'G';
	MORSE2INT("....", psz, nIndex); arrnMorseTable[nIndex] = 'H';
	MORSE2INT("..", psz, nIndex); arrnMorseTable[nIndex] = 'I';
	MORSE2INT(".---", psz, nIndex); arrnMorseTable[nIndex] = 'J';
	MORSE2INT("-.-", psz, nIndex); arrnMorseTable[nIndex] = 'K';
	MORSE2INT(".-..", psz, nIndex); arrnMorseTable[nIndex] = 'L';
	MORSE2INT("--", psz, nIndex); arrnMorseTable[nIndex] = 'M';
	MORSE2INT("-.", psz, nIndex); arrnMorseTable[nIndex] = 'N';
	MORSE2INT("---", psz, nIndex); arrnMorseTable[nIndex] = 'O';
	MORSE2INT(".--.", psz, nIndex); arrnMorseTable[nIndex] = 'P';
	MORSE2INT("--.-", psz, nIndex); arrnMorseTable[nIndex] = 'Q';	
	MORSE2INT(".-.", psz, nIndex); arrnMorseTable[nIndex] = 'R';
	MORSE2INT("...", psz, nIndex); arrnMorseTable[nIndex] = 'S';
	MORSE2INT("-", psz, nIndex); arrnMorseTable[nIndex] = 'T';
	MORSE2INT("..-", psz, nIndex); arrnMorseTable[nIndex] = 'U';
	MORSE2INT("...-", psz, nIndex); arrnMorseTable[nIndex] = 'V';
	MORSE2INT(".--", psz, nIndex); arrnMorseTable[nIndex] = 'W';
	MORSE2INT("-..-", psz, nIndex); arrnMorseTable[nIndex] = 'X';
	MORSE2INT("-.--", psz, nIndex); arrnMorseTable[nIndex] = 'Y';
	MORSE2INT("--..", psz, nIndex); arrnMorseTable[nIndex] = 'Z';

	MORSE2INT("-----", psz, nIndex); arrnMorseTable[nIndex] = '0';
	MORSE2INT(".----", psz, nIndex); arrnMorseTable[nIndex] = '1';
	MORSE2INT("..---", psz, nIndex); arrnMorseTable[nIndex] = '2';
	MORSE2INT("...--", psz, nIndex); arrnMorseTable[nIndex] = '3';
	MORSE2INT("....-", psz, nIndex); arrnMorseTable[nIndex] = '4';
	MORSE2INT(".....", psz, nIndex); arrnMorseTable[nIndex] = '5';
	MORSE2INT("-....", psz, nIndex); arrnMorseTable[nIndex] = '6';
	MORSE2INT("--...", psz, nIndex); arrnMorseTable[nIndex] = '7';
	MORSE2INT("---..", psz, nIndex); arrnMorseTable[nIndex] = '8';
	MORSE2INT("----.", psz, nIndex); arrnMorseTable[nIndex] = '9';

	MORSE2INT(".-.-.-", psz, nIndex); arrnMorseTable[nIndex] = '.';
	MORSE2INT("--..--", psz, nIndex); arrnMorseTable[nIndex] = ',';
	MORSE2INT("..--..", psz, nIndex); arrnMorseTable[nIndex] = '?';
	MORSE2INT(".----.", psz, nIndex); arrnMorseTable[nIndex] = '\'';
	MORSE2INT("-.-.--", psz, nIndex); arrnMorseTable[nIndex] = '!';
	MORSE2INT("-..-.", psz, nIndex); arrnMorseTable[nIndex] = '/';
	MORSE2INT("-.--.", psz, nIndex); arrnMorseTable[nIndex] = '(';
	MORSE2INT("-.--.-", psz, nIndex); arrnMorseTable[nIndex] = ')';
	MORSE2INT(".-...", psz, nIndex); arrnMorseTable[nIndex] = '&';

	MORSE2INT("---...", psz, nIndex); arrnMorseTable[nIndex] = ':';
	MORSE2INT("-.-.-.", psz, nIndex); arrnMorseTable[nIndex] = ';';
	MORSE2INT("-...-", psz, nIndex); arrnMorseTable[nIndex] = '=';
	MORSE2INT(".-.-.", psz, nIndex); arrnMorseTable[nIndex] = '+';
	MORSE2INT("-....-", psz, nIndex); arrnMorseTable[nIndex] = '-';
	MORSE2INT("..--.-", psz, nIndex); arrnMorseTable[nIndex] = '_';
	MORSE2INT(".-..-.", psz, nIndex); arrnMorseTable[nIndex] = '"';
	MORSE2INT(".--.-.", psz, nIndex); arrnMorseTable[nIndex] = '@';
}

int main() {
	int nNoCases, nLoop, nChar;
	int arrnMorseTable[1 << 8];
	char *pszLetter, *psz;
	char szLine[MAX_LINE_LEN];

	memset(arrnMorseTable, 0, sizeof(arrnMorseTable));
	InitTable(arrnMorseTable);

	gets(szLine); sscanf(szLine, "%d", &nNoCases);
	for (nLoop = 1; nLoop <= nNoCases; nLoop++) {
		pszLetter = gets(szLine);

		printf("Message #%d\n", nLoop);
		while (*pszLetter) {
			if (*pszLetter == ' ') {
				if (*++pszLetter == ' ')
					printf(" "), pszLetter++;
			} else {
				MORSE2INT_2(pszLetter, psz, nChar);
				if (arrnMorseTable[nChar])
					printf("%c", arrnMorseTable[nChar]);
				pszLetter = psz;
			}

		}


		if (nLoop != nNoCases)
			printf("\n\n");
		else
			printf("\n");
	}

	return 0;
}
