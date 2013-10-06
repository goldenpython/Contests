/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10473 - Simple Base Conversion                                   */


#include <stdio.h>

int main() {
	char szLine[16];
	int nNumber;

	while (1) {
		if (!gets(szLine))
			break;

		if (szLine[1] == 'x') {
			sscanf(szLine, "%x", &nNumber);
			printf("%d\n", nNumber);
		} else {
			sscanf(szLine, "%d", &nNumber);
			if (nNumber < 0)
				break;
			printf("0x%X\n", nNumber);
		}
	}

	return 0;
}