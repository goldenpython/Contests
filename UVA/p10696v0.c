/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10696 - f91                                                      */


#include <stdio.h>

int f91(int n) {
	if (n >= 101)
		return n - 10;
	else
		return f91(f91(n + 11));
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
	int n;

	while (1) {
		gets(szLine);
		n = AtoINoSgn(szLine);
		if (!n)
			return 0;

		printf("f91(%d) = %d\n", n, f91(n));
	}

	return 0;
}
