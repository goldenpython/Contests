/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12577 - Hajj-e-Akbar                                             */



#include <stdio.h>

int main() {
	int nCase = 1;
	char szLine[32];

	while (gets(szLine), *szLine != '*') {
		if (*szLine == 'H')
			printf("Case %d: Hajj-e-Akbar\n", nCase);
		else
			printf("Case %d: Hajj-e-Asghar\n", nCase);

		nCase++;
	}

	return 0;
}
