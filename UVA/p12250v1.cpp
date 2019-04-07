/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12250 - Language Detection                                       */


#include <stdio.h>
#include <string.h>

#if !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)
	#include <limits.h>
	#define gets(a) gets_s(a, INT_MAX)
#endif // !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)


int main() {
	const int MAX_LINE_LEN = 16;

	int nCaseNumber = 0;
	char szLine[MAX_LINE_LEN];

	while (gets(szLine) && *szLine != '#') {
		printf("Case %d: ", ++nCaseNumber);
		if (!strcmp(szLine, "HELLO"))
			printf("ENGLISH\n");
		else if (!strcmp(szLine, "HOLA"))
			printf("SPANISH\n");
		else if (!strcmp(szLine, "HALLO"))
			printf("GERMAN\n");
		else if (!strcmp(szLine, "BONJOUR"))
			printf("FRENCH\n");
		else if (!strcmp(szLine, "CIAO"))
			printf("ITALIAN\n");
		else if (!strcmp(szLine, "ZDRAVSTVUJTE"))
			printf("RUSSIAN\n");
		else
			printf("UNKNOWN\n");
	}


	return 0;
}