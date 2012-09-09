/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 492 - Pig-Latin                                                  */



#include <stdio.h>

#define IS_LETTER(a)	(((a) >= 'a' && (a) <= 'z') || ((a) >= 'A' && (a) <= 'Z'))

#define IS_VOVEL(a)		((a) == 'a' || (a) == 'e' || (a) == 'i' || (a) == 'o' || (a) == 'u' || (a) == 'A' || (a) == 'E' || (a) == 'I' || (a) == 'O' || (a) == 'U')

char szLineOut[1024 * 1024];
char szLine[1024 * 1024];

int main() {
	char *p, *s, *q, *out;

	while (gets(szLine)) {
		p = szLine;

		out = szLineOut;
		while (1) {			

			while (!IS_LETTER(*p) && *p)
				*out++ = *p++;

			if (!*p)
				break;

			for (s = p; IS_LETTER(*s); s++)
				;

			if (IS_VOVEL(*p)) {
				for ( ; p < s; p++)
					*out++ = *p;

				*out++ = 'a';
				*out++ = 'y';
			} else {
				q = p;

				for (p++; p < s; p++)
					*out++ = *p;

				*out++ = *q;
				*out++ = 'a';
				*out++ = 'y';
			}
		}

		puts(szLineOut);
	}

	return 0;
}
