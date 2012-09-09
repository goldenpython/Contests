/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 445 - Marvelous Mazes                                            */


#include <stdio.h>

#define IS_DIGIT(a)		(a >= '0' && a <= '9')

int main() {
	int num, i;
	char *p, szLine[65536];

	/* freopen("input/455.txt", "rt", stdin); */

	while (gets(szLine)) {
		if (*szLine) {

			for (p = szLine; *p; p++) {
				if (*p == '!') {
					printf("\n");
					p++;
				}

				for (num = 0; IS_DIGIT(*p); p++)
					num += *p - '0';		
		
				if (*p == 'b')
					for (i = 0; i < num; i++)
						printf(" ");
				else
					for (i = 0; i < num; i++)
						printf("%c", *p);
			}

			printf("\n");
		} else
			printf("\n");
	}

	return 0;
}
