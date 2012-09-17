/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 880 - Cantor Fractions                                           */



#include <stdio.h>
#include <math.h>

#define ERR 1E-10


long long AtoLLNoSgn(char *szString) {
	long long ret = 0;

	while (*szString) {
		ret = ret * 10 + *szString++ - '0';
	}

	return ret;
}

int main() {
	long long norig, n, l, up, down;
	double d;
	char szLine[16];

	while (gets(szLine)) {
		n = atol(szLine);

		norig = n;
		d = (-1 + sqrt(1 + 8 * n)) / 2;

		if (d - (int)d < ERR)
			l = (int)(d - 1);
		else
			l = (int)d;

		n -= l * (l + 1) / 2;


		down = n;
		up = l + 1 - n + 1;

		printf("%d/%d\n", (int)up, (int)down);
	}

	return 0;
}
