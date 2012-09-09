/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10082 - WERTYU                                                   */



#include <stdio.h>

#define MAX_LINE_LEN 10000

char next[256];


int main() {
	char *strings[] = {
		"`1234567890-=",
		"QWERTYUIOP[]\\",
		"ASDFGHJKL;'",
		"ZXCVBNM,./",
	};

	int i;
	char *p, szLine[MAX_LINE_LEN], *p1, szLine1[MAX_LINE_LEN];

	for (i = 0; i < sizeof(strings) / sizeof(char *); i++)
		for (p = strings[i] + 1; *p; p++)
			next[*p] = *(p - 1);

	while (gets(szLine)) {
		for (p = szLine, p1 = szLine1; *p; p++)
			*p1++ = next[*p] ? next[*p] : *p;
			
		*p1 = '\0';

		puts(szLine1);
	}



	return 0;
}
