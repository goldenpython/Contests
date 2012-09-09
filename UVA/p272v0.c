/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 272 - TEX Quotes                                                 */



#include <stdio.h>

#define MAX_LINE_LEN	256

int main() {
	int NumQuotes = 0;
	const char quotes[2] = {'`', '\''};
	char szLine1[MAX_LINE_LEN], szLine2[MAX_LINE_LEN];
	register char *p1, *p2;

	/* freopen("input/272.txt", "rt", stdin); */

	while (gets(szLine1)) {
		for (p1 = szLine1, p2 = szLine2; *p1; )
			if (*p1 != '\"')
				*p2++ = *p1++;
			else {
				*p2++ = quotes[NumQuotes];
				*p2++ = quotes[NumQuotes];
				p1++;

				NumQuotes ^= 1;
			}

		*p2 = '\0';
		/* puts(szLine2); */
		printf("%s\n", szLine2);
	}

	return 0;
}
