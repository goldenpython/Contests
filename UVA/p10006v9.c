/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11121 - 10006 - Carmichael Numbers                               */


#include <stdio.h>
#include <math.h>


int carmichael[] = {
	561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633,
		62745, 63973
};

int FindNumber(int nr) {
	int a = 0, b = sizeof(carmichael) / sizeof(int) - 1, m;

	while (a <= b) {
		if (carmichael[m = (a + b) >> 1] > nr)
			b = m - 1;
		else 
			a = m + 1;
	}

	return carmichael[b] == nr;
}

int main() {
	int n;
	char szLine[100];

	while (1)  {
		gets(szLine);
		n = atoi(szLine);
		if (!n)
			return;

		if (FindNumber(n))
			printf("The number %d is a Carmichael number.\n", n);
		else
			printf("%d is normal.\n", n);
	}

	return 0;
}