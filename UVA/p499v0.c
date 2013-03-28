/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 499 - What's The Frequency, Kenneth?                             */



#include <stdio.h>
#include <string.h>

int main() {
	char *p, szLine[1024];
	int max, i, freq[256];

	/* freopen("input/499.txt", "rt", stdin); */

	while (gets(szLine)) {
		memset(freq, 0, sizeof(freq));
		for (p = szLine; *p; p++)
			freq[*p]++;

		max = 0;
		for (i = 'A'; i <= 'Z'; i++)
			if (max < freq[i])
				max = freq[i];
		for (i = 'a'; i <= 'z'; i++)
			if (max < freq[i])
				max = freq[i];


		for (i = 'A'; i <= 'Z'; i++)
			if (max == freq[i])
				printf("%c", i);
		for (i = 'a'; i <= 'z'; i++)
			if (max == freq[i])
				printf("%c", i);
		printf(" %d\n", max);
	}

	return 0;
}
