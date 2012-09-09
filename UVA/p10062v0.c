/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10062 - Tell me the frequencies!                                 */



#include <stdio.h>
#include <string.h>

int main() {
	char *p, szLine[1024];
	int i, j, aux, first = 1, freq[256], index[256];

	while (gets(szLine)) {
		memset(freq, 0, sizeof(freq)); 

		for (p = szLine; *p; freq[*p++]++)
			;

		freq['\n'] = freq['\r'] = 0;
		for (i = 32; i < 128; i++)
			index[i] = i;

		for (i = 32; i < 128; i++)
			for (j = i + 1; j < 128; j++)
				if (freq[index[i]] > freq[index[j]] || (freq[index[i]] == freq[index[j]] && index[i] < index[j])) {
					aux = index[i];
					index[i] = index[j];
					index[j] = aux;
				}

		for (i = 32; !freq[index[i]] && i < 128; i++)
			;

		if (!first) 
			printf("\n");
		else
			first = 0;


		for ( ; i < 128; i++) 
			printf("%d %d\n", index[i], freq[index[i]]);
	}

	return 0;
}
