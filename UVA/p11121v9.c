/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11121 - Base -2                                                  */


#include <stdio.h>
#include <string.h>

#define MAX_C 64

int AtoI(char *szString) {
	int sgn = 1, ret = 0;

	if (*szString == '-') {
		sgn = -1;
		szString++;
	}

	while (*szString) {
		ret = ret * 10 + *szString++ - '0'; 
	}

	return ret * sgn;
}

int main() {
	int n, c, r, nrcases, i;
	char nr[MAX_C], *p = nr + MAX_C - 2, *pc;

	memset(nr, 0, sizeof(nr));

	gets(nr);
	nrcases = AtoI(nr);

	for (i = 1; i <= nrcases; i++) {
		gets(nr);
		n = AtoI(nr);

		if (!n)
			printf("Case #%d: 0\n", i);
		else {
			pc = p;

			while (n) {
				c = n / (-2);
				r = n & 0x1;

				*pc-- = r + '0';
				if (r && n < 0)
					c++;

				n = c;
			}

			printf("Case #%d: %s\n", i, pc + 1);
		}
	}

	return 0;
}