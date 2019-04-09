/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12626 - I ❤ Pizza                                               */


#include <stdio.h>

#if !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)
	#include <limits.h>
	#define gets(a) gets_s(a, INT_MAX)
#endif // !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)


#define MAX_LINE_LEN	620

#define MIN(a, b)	((a) < (b) ? (a) : (b))

int main() {
	int nNoTestCases;
	char szLine[MAX_LINE_LEN];

	for (sscanf(gets(szLine), "%d", &nNoTestCases); nNoTestCases--; ) {
		gets(szLine);

		int arrnFreq[256];
		arrnFreq['M'] = arrnFreq['A'] = arrnFreq['R'] = arrnFreq['G'] = arrnFreq['I'] = arrnFreq['T'] = 0;
		for (char *psz = szLine; *psz; psz++)
			arrnFreq[*psz]++;

		arrnFreq['A'] /= 3;
		int nSol = arrnFreq['A'];

		arrnFreq['R'] /= 2;
		nSol = MIN(nSol, arrnFreq['R']);

		nSol = MIN(nSol, arrnFreq['M']);
		nSol = MIN(nSol, arrnFreq['G']);
		nSol = MIN(nSol, arrnFreq['I']);
		nSol = MIN(nSol, arrnFreq['T']);

		printf("%d\n", nSol);
	}

	return 0;
}