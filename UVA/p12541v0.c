/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12541 - Birthdates                                               */


#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN		32

#define MAKE_DATE(d, m, y)	((d) | ((m) << 8) | ((y) << 16))

int main() {
	int nN, nDay, nMonth, nYear, nMinDate, nMaxDate;
	char szName[MAX_LINE_LEN], szMinName[MAX_LINE_LEN] = {'\0'}, szMaxName[MAX_LINE_LEN] = {'\0'};
	char szLine[MAX_LINE_LEN];

	nMaxDate = 0;
	nMinDate = MAKE_DATE(0, 0, 10000);
	for (sscanf(gets(szLine), "%d", &nN); nN; nN--) {
		gets(szLine);
		sscanf(szLine, "%s %d %d %d", szName, &nDay, &nMonth, &nYear);

		nYear = MAKE_DATE(nDay, nMonth, nYear);
		if (nYear <= nMinDate) {
			strcpy(szMinName, szName);
			nMinDate = nYear;
		}

		if (nYear >= nMaxDate) {
			strcpy(szMaxName, szName);
			nMaxDate = nYear;
		}
	}

	printf("%s\n%s\n", szMaxName, szMinName);

	return 0;
}