/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11192 - Group Reverse                                            */



#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 500

int main() {
	int g, i, j, n;
	char s[MAX_LINE_LEN];
	char *p;

	while (gets(s)) {
		p = strtok(s, " ");
		sscanf(s, "%d", &g);

		if (!g)
			break;

		n = strlen(p = strtok(NULL, " "));
		n /= g;

		for (i = 0; i < g; i++)
			for (j = 0; j < n; j++)
				printf("%c", p[i * n + n - j - 1]);

		printf("\n");
	}

	return 0;
}
