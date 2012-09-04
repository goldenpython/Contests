/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10515 - Powers Et Al.                                            */


#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 1000


int main() {
	char *p, *q, szLine[MAX_LINE_LEN];
	int c, last2, zero;
	int l2[] = {2, 4, 8, 6};
	int l3[] = {3, 9, 7, 1};
	int l4[] = {4, 6};
	int l7[] = {7, 9, 3, 1};
	int l8[] = {8, 4, 2, 6};
	int l9[] = {9, 1};

	while (gets(szLine)) {
		p = strtok(szLine, " ");
		c = p[strlen(p) - 1] - '0';
		zero = !strcmp(p, "0");

		q = p = strtok(NULL, " ");
		if (!strcmp(p, "0")) {
			if (zero)
				return;

			printf("1\n");
			continue;
		}

		last2 = p[strlen(p) - 1] - '0';
		if (strlen(p) > 1)
			last2 += (p[strlen(p) - 2] - '0') * 10;

		last2 += 4;
		switch (c) {
			case 0:
			case 1:
			case 5:
			case 6:
				printf("%d\n", c);
				break;

			case 2:
				printf("%d\n", l2[(last2 - 1) % 4]);
				break;

			case 3:
				printf("%d\n", l3[(last2 - 1) % 4]);
				break;

			case 4:
				printf("%d\n", l4[(last2 - 1) % 2]);
				break;

			case 7:
				printf("%d\n", l7[(last2 - 1) % 4]);
				break;

			case 8:
				printf("%d\n", l8[(last2 - 1) % 4]);
				break;

			case 9:
				printf("%d\n", l9[(last2 - 1) % 2]);
				break;
		}
	}

	return 0;
}
