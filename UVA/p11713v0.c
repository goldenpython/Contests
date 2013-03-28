/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN	22

int main() {
	int nTestCases, i;
	char *pCursor1, *pCursor2, szName[2][MAX_NAME_LEN];
	char bIsVovel[256];

	memset(bIsVovel + 'a', 0, sizeof(bIsVovel[0]) * ('z' - 'a' + 1));
	bIsVovel['a'] = bIsVovel['A'] = 1;
	bIsVovel['e'] = bIsVovel['E'] = 1;
	bIsVovel['i'] = bIsVovel['I'] = 1;
	bIsVovel['o'] = bIsVovel['O'] = 1;
	bIsVovel['u'] = bIsVovel['U'] = 1;

	for (sscanf(gets(szName[0]), "%d", &nTestCases); nTestCases--; ) {
		pCursor1 = gets(szName[0]); pCursor2 = gets(szName[1]);

		for ( ; *pCursor1 && *pCursor2 && (*pCursor1 == *pCursor2 || bIsVovel[*pCursor1] && bIsVovel[*pCursor2]); pCursor1++, pCursor2++)
			;

		if (*pCursor1 == *pCursor2 && *pCursor1 == '\0')
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
