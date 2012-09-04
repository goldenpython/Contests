/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/



#include <stdio.h>
#include <string.h>

int main() {
	char *psz, *pszNumber1, *pszNumber2, *pszResult;
	char cOp;
	int nNotValid, nNumber1, nNumber2, nResult, nSum = 0;
	char szLine[256];

	while (gets(szLine)) {
		nNotValid = 0;
		psz = pszNumber1 = szLine;
		while (*psz) {
			if (*psz != '-' && *psz != '+') {
				if (*psz == '?') {
					nNotValid = 1;
					break;
				}
				psz++;
			} else {
				cOp = *psz;
				*psz++ = '\0';
				pszNumber2 = psz;
				break;
			}
		}

		if (nNotValid)
			continue;

		while (*psz) {
			if (*psz != '=') {
				if (*psz == '?') {
					nNotValid = 1;
					break;
				}
				psz++;
			} else {
				*psz++ = '\0';
				pszResult = psz;
				break;
			}
		}

		if (nNotValid)
			continue;

		while (*psz) {
			if (*psz == '?') {
				nNotValid = 1;
				break;
			}
			psz++;
		}

		if (nNotValid)
			continue;

		nNumber1 = atoi(pszNumber1);
		nNumber2 = atoi(pszNumber2);
		nResult = atoi(pszResult);

		if (cOp == '+')
			nNumber1 += nNumber2;
		else 
			nNumber1 -= nNumber2;

		if (nNumber1 == nResult)
			nSum++;
	}

	printf("%d\n", nSum);

	return 0;
}
