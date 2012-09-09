/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 444 - Encoder and Decoder                                        */


#include <stdio.h>
#include <string.h>

#define MAX		1024

#define IS_VALID(c)	((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || c == '!' || c == ',' || c == '.' || c == ':' || c== ';' || c == '?')

char *strreverse(char *sz) {
	char *p1 = sz, *p2 = sz + strlen(sz) - 1;
	char c;

	while (p1 < p2) {
		c = *p1;
		*p1 = *p2;
		*p2 = c;

		p1++;
		p2--;
	}
}

int main() {
	int len, a;
	char *p, szLine[MAX], *pRes, szRes[MAX];
	char szTemp[16];


	/* freopen("input/444.txt", "rt", stdin); */

	while (gets(szLine)) {
		if (*szLine > '9' || *szLine < '0') {
			len = strlen(szLine);
			*(pRes = szRes) = '\0';

			for (p = szLine + len - 1; p >= szLine; p--) {
				sprintf(pRes, "%d", *p);
				strreverse(pRes);
				pRes += strlen(pRes);
			}

			printf("%s\n", szRes);
		} else {
			for (p = szLine, *(pRes = szRes + MAX - 1) = '\0'; *p; ) {
				a = *p++ - '0';
				a += 10 * (*p++ - '0');

				if (!IS_VALID(a))
					a += 100 * (*p++ - '0');

				*--pRes = a;
			}

			printf("%s\n", pRes);
		}
	}

	return 0;
}
