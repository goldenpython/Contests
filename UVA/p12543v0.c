/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12543 - Longest Word                                             */


#include <stdio.h>
#include <string.h>


#define MAX_BUFFER_LEN		(1024 * 10)
#define MAX_WORD_LEN		102

char *mystrlwr(char *szString) {
	char *psz;

	for (psz = szString; *psz; psz++)
		if (*psz >= 'A' && *psz <= 'Z')
			*psz += ('a' - 'A');
			
	return szString;
}

int main() {
	int nBufferLen, nLoop, nMax;
	int arrnIsValidLetter[256];
	char *pcStartWord, *pcEndWord, *pcLimit, szSol[MAX_WORD_LEN], arrcBuffer[MAX_BUFFER_LEN];

	memset(szSol, 0, sizeof(szSol));

	memset(arrnIsValidLetter, 0, sizeof(arrnIsValidLetter));
	for (nLoop = 'a'; nLoop <= 'z'; nLoop++)
		arrnIsValidLetter[nLoop] = 1;
	for (nLoop = 'A'; nLoop <= 'Z'; nLoop++)
		arrnIsValidLetter[nLoop] = 1;
	arrnIsValidLetter['-'] = 1;

	nBufferLen = fread(arrcBuffer, sizeof(char), sizeof(arrcBuffer), stdin);


	pcLimit = arrcBuffer + nBufferLen - 1;
	while (*pcLimit != 'D')
		pcLimit--;
	pcLimit -= 3;
	*pcLimit = ' ';

	nMax = -1;
	pcStartWord = arrcBuffer;
	while (pcStartWord < pcLimit) {
		while (!arrnIsValidLetter[*pcStartWord])
			pcStartWord++;
		pcEndWord = pcStartWord;
		while (arrnIsValidLetter[*pcEndWord])
			pcEndWord++;

		if (pcEndWord - pcStartWord > nMax) {
			nMax = pcEndWord - pcStartWord;
			memcpy(szSol, pcStartWord, nMax);
		}

		pcStartWord = pcEndWord + 1;
	}

	printf(mystrlwr(szSol));
	printf("\n");

	return 0;
}
