/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10340 - All in All                                               */



#include <stdio.h>
#include <string.h>

#define MAX		(1024 * 1024)

char szLine[MAX * 2];
int pd[MAX];

int main() {
	char *p, *s, *t;
	int l1, l2, i, j, sol;

	/* freopen("input/10340.txt", "rt", stdin); */

	while (gets(szLine)) {
		for (p = s = szLine; *p != ' '; p++)
			;

		t = p + 1;
		*(t - 1) = '\0';
		l1 = t - s - 1;

		for ( ; *t == ' '; t++)
			;

		l2 = strlen(t);

		sol = 1;
		for (i = 0; i < l1 && sol; i++) {
			pd[i] = -1;

			for (j = i ? pd[i - 1] + 1 : 0; j < l2; j++)
				if (s[i] == t[j]) {
					pd[i] = j;
					break;
				}

			if (pd[i] == -1) {
				sol = 0;
				break;
			}
		}

		printf("%s\n", sol ? "Yes" : "No");
	}

	return 0;
}
