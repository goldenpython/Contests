/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10683 - The decadary watch                                       */


#include <stdio.h>

int main() {
	char szLine[32];

	while (gets(szLine)) {
		int nH = (szLine[0] - '0') * 10 + (szLine[1] - '0');
		int nM = (szLine[2] - '0') * 10 + (szLine[3] - '0');
		int nS = (szLine[4] - '0') * 10 + (szLine[5] - '0');
		int nC = (szLine[6] - '0') * 10 + (szLine[7] - '0');

		int nTotal = nC + nS * 100 + nM * 100 * 60 + nH * 100 * 60 * 60;
		//const int nMaxNormal = 24 * 60 * 60 * 100;
		//const int nMaxDec = 10 * 100 * 100 * 100;
		const int nMaxNormal = 24 * 6 * 6;
		const int nMaxDec = 10 * 100;
		

		printf("%07d\n", int(double(nTotal) / nMaxNormal * nMaxDec));
	}

	return 0;
}