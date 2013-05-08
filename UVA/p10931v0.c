/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10931 - Parity                                                   */


#include <stdio.h>
#include <string.h>

int main() {
	unsigned int n, par;
	int i;
	char aux[100];

	while (scanf("%d", &n), n) {
		par = 0;
		strcpy(aux, "");
		while (n) {
			if (n & 0x1) {
				par++;
				strcat(aux, "1");
			} else
				strcat(aux, "0");

			n >>= 1;
		}

		/* printf("The parity of %d is %d (mod 2).\n", nn, par); */
		printf("The parity of ");
		for (i = strlen(aux) - 1; i >= 0; i--)
			printf("%c", aux[i]);
		printf(" is %d (mod 2).\n", par);
	}

	return 0;
}
