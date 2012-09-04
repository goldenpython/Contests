/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10424 - Love Calculator                                          */



#include <stdio.h>

#define MAX_LINE_LEN	30


int main() {
	char szLine1[MAX_LINE_LEN], szLine2[MAX_LINE_LEN];
	static char points[256];

	int i, p1, p2;
	char *p;

	/* freopen("input\\10424.txt", "rt", stdin); */

	for (i = 'a'; i <= 'z'; i++)
		points[i] = i - 'a' + 1;

	for (i = 'A'; i <= 'Z'; i++)
		points[i] = i - 'A' + 1;

	while (gets(szLine1) && gets(szLine2)) {
		for (p1 = 0, p = szLine1; *p; p1 += points[*p++]);
		for (p2 = 0, p = szLine2; *p; p2 += points[*p++]);


		while (p1 > 9) {
			i = p1;
			p1 = 0;
			while (i)
				p1 += i % 10, i /= 10;
		}

		while (p2 > 9) {
			i = p2;
			p2 = 0;
			while (i)
				p2 += i % 10, i /= 10;
		}

		printf("%.2f %\n", 100 * (p1 > p2 ? (float)p2 / p1 : (float)p1 / p2));
	}

	return 0;
}
