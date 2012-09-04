/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11220 - Decoding the message.                                    */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN	10000


int main() {
	char *p, szLine[MAX_LINE_LEN];
	int nrcases, loop, letter;


	/* freopen("input\\11220.txt", "rt", stdin); */

	gets(szLine); nrcases = atoi(szLine);
	gets(szLine);

	for (loop = 0; loop < nrcases; loop++) {
		if (loop)
			printf("\n");

		printf("Case #%d:\n", loop + 1);
		while (gets(szLine) && *szLine) {
			letter = 0;
			for (p = strtok(szLine, " "); p; p = strtok(NULL, " ")) {
				if (strlen(p) > letter)
					printf("%c", p[letter++]);
			}
			printf("\n");
		}

	}

	return 0;
}
