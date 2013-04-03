/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12602 - Nice Licence Plates                                      */



#include <stdio.h>

int main() {
	const int MAX_LINE_LEN = 32;

	int nNoTestCases;
	char szLine[MAX_LINE_LEN];

	for (sscanf(gets(szLine), "%d", &nNoTestCases); nNoTestCases; nNoTestCases--) {
		gets(szLine);

		int nN1 = (szLine[0] - 'A') * 26 * 26 + (szLine[1] - 'A') * 26 + (szLine[2] - 'A');
		int nN2 = (szLine[4] - '0') * 1000 + (szLine[5] - '0') * 100 + (szLine[6] - '0') * 10 + (szLine[7] - '0');

		nN1 -= nN2;
		printf(nN1 <= 100 && nN1 >= -100 ? "nice\n" : "not nice\n");
	}

	return 0;
}