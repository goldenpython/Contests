/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10922 - 2 the 9s                                                 */


#include <stdio.h>

#define MAX_LINE_LEN 1005

int main() {
	char line[MAX_LINE_LEN], *p;
	int deg, sum, aux;

	while (gets(line)) {
		/* if (!strcmp(line, "0"))
			return 0; */
		if (*line == '0')
			return 0;

		sum = deg = 0;
		for (p = line; *p; sum += *p++);

		sum -= (p - line) * '0';

		if (sum % 9)
			printf("%s is not a multiple of 9.\n", line);
		else {
			while (sum % 9 == 0 && sum > 9) {
				aux = 0;
				do {
					aux += sum % 10;
				} while (sum /= 10);
				/* while (sum) {
					aux += sum % 10;
					sum /= 10;
				} */
				sum = aux;
				deg++;
			}
			printf("%s is a multiple of 9 and has 9-degree %d.\n", line, deg + 1);
		}
	}

	return 0;
}
