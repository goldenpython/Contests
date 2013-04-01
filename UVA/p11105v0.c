/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11105 - Semi-prime H-numbers                                     */



#include <stdio.h>
#include <string.h>

#define MAX		250000

int nr[MAX + 10];

int AtoI(char *szString) {
	int ret = 0;

	while (*szString) {
		ret = ret * 10 + *szString++ - '0'; 
	}

	return ret;
}


int main() {
	int i, j, n, m, k;
	char szLine[20];

	n = MAX / 5;

	for (i = 1; i <= n; i++) {
		m = (MAX - i) / ((i << 2) + 1);

		for (j = i; j <= m; j++) {
			k = ((i * j) << 2) + i + j;
			nr[k] = nr[i] + nr[j] + 1;
		}			
	} 

	for (i = 1, j = 0; i <= MAX; i++, j++) 
		if (nr[i] == 1)
			nr[i] += nr[j];
		else
			nr[i] = nr[j];


	while (gets(szLine), n = AtoI(szLine)) {
		i = (n - 1) >> 2;
		printf("%d %d\n", n, nr[i]);
	}
	
	return 0;
}
