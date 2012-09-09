/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 902 - Password Search                                            */



#include <stdio.h>
#include <string.h>

#include <map>
#include <string>

using namespace std;

#define MAP_TYPE map<long long int, int>


long long int GetNumber(char *psz) {
	int llRet = 0;

	while (*psz) {
		llRet = llRet * 26 + (*psz - 'a');
		psz++;
	}

	return llRet;
}

char g_szLine[2000100];

int main() {
	char *pszMessage, *pszFirst, *pszLast;
	int nPasswordSize, nLoop, nMax;
	long long int llNumber, llPow, llSol;


	while (scanf("%d %s", &nPasswordSize, g_szLine) == 2) {
		MAP_TYPE oStringOccurence;

		pszMessage = g_szLine; 


		llNumber = 0; llPow = 1;
		for (nLoop = 0; nLoop < nPasswordSize; nLoop++) {
			llNumber = llNumber * 26 + (pszMessage[nLoop] - 'a');
			llPow *= 26;
		}
		llPow /= 26;
		pszFirst = pszMessage; pszLast = pszMessage + nPasswordSize - 1;

		nMax = 0;
		do {
			int nCurrent = ++oStringOccurence[llNumber];
			if (nCurrent > nMax) {
				nMax = nCurrent;
				llSol = llNumber;
			}

			llNumber -= llPow * (*pszFirst - 'a');
			pszFirst++, pszLast++;
			llNumber = llNumber * 26 + (*pszLast - 'a');
		} while (*pszLast);

		llNumber = llSol;

		g_szLine[nPasswordSize] = '\0';
		for (nLoop = nPasswordSize - 1; nLoop >= 0; nLoop--) {
			g_szLine[nLoop] = (llNumber % 26) + 'a';
			llNumber /= 26;
		}
		printf("%s\n", g_szLine);
	}

	return 0;
}
