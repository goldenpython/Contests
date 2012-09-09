/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12250 - Language Detection                                       */


#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN	16

int main() {
	char szLine[16];
	int nCaseNumber = 0;

	while (*gets(szLine) != '#') {
		nCaseNumber++;

		if (!strcmp(szLine, "HELLO"))
			printf("Case %d: ENGLISH\n", nCaseNumber);
		else if (!strcmp(szLine, "HOLA"))
			printf("Case %d: SPANISH\n", nCaseNumber);
		else if (!strcmp(szLine, "HALLO"))
			printf("Case %d: GERMAN\n", nCaseNumber);
		else if (!strcmp(szLine, "BONJOUR"))
			printf("Case %d: FRENCH\n", nCaseNumber);
		else if (!strcmp(szLine, "CIAO"))
			printf("Case %d: ITALIAN\n", nCaseNumber);
		else if (!strcmp(szLine, "ZDRAVSTVUJTE"))
			printf("Case %d: RUSSIAN\n", nCaseNumber);
		else
			printf("Case %d: UNKNOWN\n", nCaseNumber);
	}

	return 0;
}
 
