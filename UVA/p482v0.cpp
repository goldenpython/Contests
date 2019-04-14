/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 482 - Permutation Arrays                                         */



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <string>

#if !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)
	#include <limits.h>
	#define gets(a) gets_s(a, INT_MAX)
#endif // !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)


using namespace std;

int main() {
	const int MAX_LINE_LEN = 1 << 16;
	const char *TOKENS = " \t\n\r";
	int nNoCases;

	char szLine[MAX_LINE_LEN];

	for (sscanf(gets(szLine), "%d", &nNoCases); nNoCases; nNoCases--) {
		vector<int> ovPerm;
		vector<string> ovNumbers;

		char *psz;

		gets(szLine);

		gets(szLine);
		for (psz = strtok(szLine, TOKENS); psz; psz = strtok(NULL, TOKENS))
			ovPerm.insert(ovPerm.end(), atoi(psz) - 1);

		gets(szLine);
		for (psz = strtok(szLine, TOKENS); psz; psz = strtok(NULL, TOKENS))
			ovNumbers.insert(ovNumbers.end(), psz);

		vector<int> ovPermInvese(ovPerm.size());
		for (int nLoop = 0; nLoop < (int)ovPerm.size(); nLoop++)
			ovPermInvese[ovPerm[nLoop]] = nLoop;

		for (int nLoop = 0; nLoop < (int)ovPerm.size(); nLoop++)
			printf("%s\n", ovNumbers[ovPermInvese[nLoop]].c_str());

		if (nNoCases > 1)
			printf("\n");
	}

	return 0;
}