/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 401 - Palindromes                                                */


#include <stdio.h>
#include <string.h>

char *table[] = {
	"AA",
	"E3",
	"HH",
	"II",
	"JL",
	"LJ",
	"MM",
	"OO",
	"S2",
	"TT",
	"UU",
	"VV",
	"WW",
	"XX",
	"YY",
	"Z5",
	"11",
	"2S",
	"3E",
	"5Z",
	"88"
};

char CharInverse[256];

int IsPalindrome(char *s, int len) {
	char *p = s + len - 1;

	while (s <= p)
		if (*s++ != *p--)
			return 0;

	return 1;
}

int IsMirrored(char *s, int len) {
	char *p = s + len - 1;

	while (s <= p)
		if (CharInverse[*s++] != *p--)
			return 0;

	return 1;
}

int main() {
	int i, bp, bm, len;
	char szLine[32];

	for (i = 0; i < sizeof(table) / sizeof(char *); i++)
		CharInverse[table[i][0]] = table[i][1];

	/* freopen("input/401.txt", "rt", stdin); */

	while (gets(szLine)) {
		len = strlen(szLine);
		bp = IsPalindrome(szLine, len);
		bm = IsMirrored(szLine, len);

		if (bp)
			if (bm)
				printf("%s -- is a mirrored palindrome.\n\n", szLine);
			else
				printf("%s -- is a regular palindrome.\n\n", szLine);
		else
			if (bm)
				printf("%s -- is a mirrored string.\n\n", szLine);
			else
				printf("%s -- is not a palindrome.\n\n", szLine);
	}

	return 0;
}
