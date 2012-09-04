/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10427 - Naughty Sleepy Boys                                      */


#include <stdio.h>

int main() 
{
	int n;
	char s[20];

	while (scanf("%d", &n) == 1) {
		int k = 9, c = 1;

		while (n >= k * c) {
			n -= k * c;
			k *= 10;
			c++;
		}

		if (!n) {
			printf("9\n");
			continue;
		}

		k = (n - 1) / c + k / 9;
		n = (n - 1) % c;
		
		sprintf(s, "%d", k);
		printf("%c\n", s[n]);
	}
}
