/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LEN	1024

int main() {
	int nLen, nLoop;
	char *psz, szLine[MAX_LINE_LEN];

	while (1) {
		for (psz = szLine; (*psz = getchar()) != '\n'; psz++)
			;
		*psz = '\0';

		if (szLine[0] == '0')
			break;

		nLen = psz - szLine;
		if (nLen % 2)
			printf("%d", (int)sqrt(szLine[0] - '0'));
		else
			printf("%d", (int)sqrt((szLine[0] - '0') * 10 + szLine[1] - '0'));

		for (nLoop = 0; nLoop < ((nLen - 1) >> 1); nLoop++)
			printf("0");
		printf("\n");
	}

	return 0;
}
