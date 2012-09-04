/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/


#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN	128

int main() {
	char szLine[MAX_LINE_LEN];
	char *psz1, *psz2;
	char cDigit, szNumber[MAX_LINE_LEN];

	while (gets(szLine) && sscanf(szLine, "%c%s", &cDigit, szNumber) && cDigit && strcmp(szNumber, "0")) {
		for (psz1 = psz2 = szNumber; *psz1; psz1++)
			if (*psz1 != cDigit)
				*psz2++ = *psz1;

		*psz2 = '\0';
		psz1 = szNumber;
		while (*psz1 == '0')
			psz1++;

		if (*psz1 == '\0')
			printf("0\n");
		else
			printf("%s\n", psz1);
	}

	return 0;
}
