/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10591 - Happy Number                                             */


#include <stdio.h>

int nr, array[64];

int IsHappyNumber(int n) {
	int sum, r, i;
	nr = 0; array[nr++] = n;


	do {
		sum = 0;

		while (n) {
			r = n % 10;
			sum += r * r;
			n /= 10;
		}

		if (sum == 1)
			return 1;

		n = sum;

		for (i = 0; i < nr; i++)
			if (n == array[i])
				return 0;

		array[nr++] = n;
	} while (1);
}

int AtoINoSgn(char *szString) {
	int ret = 0;

	while (*szString) {
		ret = ret * 10 + *szString++ - '0'; 
	}

	return ret;
}

int main() {
	char szLine[32];
	int n, nrcases, caseno = 1;

	gets(szLine); nrcases = AtoINoSgn(szLine);

	while (caseno <= nrcases) {
		gets(szLine); n = AtoINoSgn(szLine);
		printf("Case #%d: %d is %s\n", caseno++, n, IsHappyNumber(n) ? "a Happy number." : "an Unhappy number.");
	}

	return 0;
}
