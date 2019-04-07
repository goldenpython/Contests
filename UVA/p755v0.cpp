/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 755 - 487--3279                                                  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>

#if !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)
	#include <limits.h>
	#define gets(a) gets_s(a, INT_MAX)
#endif // !defined(ONLINE_JUDGE) && (_MSC_VER >= 1900)

int main() {
	const int MAX_LINE_LEN = 1024;
	char szLine[MAX_LINE_LEN];
	char arrnKeyMap[256];

	const char NOT_A_ANUMBER = 99;
	memset(arrnKeyMap, NOT_A_ANUMBER, sizeof(arrnKeyMap));
	arrnKeyMap['0'] = 0;
	arrnKeyMap['1'] = 1;
	arrnKeyMap['A'] = arrnKeyMap['B'] = arrnKeyMap['C'] = arrnKeyMap['2'] = 2;
	arrnKeyMap['D'] = arrnKeyMap['E'] = arrnKeyMap['F'] = arrnKeyMap['3'] = 3;
	arrnKeyMap['G'] = arrnKeyMap['H'] = arrnKeyMap['I'] = arrnKeyMap['4'] = 4;
	arrnKeyMap['J'] = arrnKeyMap['K'] = arrnKeyMap['L'] = arrnKeyMap['5'] = 5;
	arrnKeyMap['M'] = arrnKeyMap['N'] = arrnKeyMap['O'] = arrnKeyMap['6'] = 6;
	arrnKeyMap['P'] = arrnKeyMap['R'] = arrnKeyMap['S'] = arrnKeyMap['7'] = 7;
	arrnKeyMap['T'] = arrnKeyMap['U'] = arrnKeyMap['V'] = arrnKeyMap['8'] = 8;
	arrnKeyMap['W'] = arrnKeyMap['X'] = arrnKeyMap['Y'] = arrnKeyMap['9'] = 9;

	for (int nNoCases = atoi(gets(szLine)); nNoCases--; ) {
		gets(szLine);

		int nNoPhoneNumbers = atoi(gets(szLine));
		std::map<int, int> oMap;

		while(nNoPhoneNumbers--) {
			int nNumber = 0;
			for (char *psz = gets(szLine); *psz; psz++)
				if (arrnKeyMap[*psz] != NOT_A_ANUMBER)
					nNumber = nNumber * 10 + arrnKeyMap[*psz];

			oMap[nNumber]++;
		}

		bool bNoDuplicates = true;
		for (std::map<int, int>::iterator oIt = oMap.begin(); oIt != oMap.end(); oIt++) {
			if (oIt->second > 1) {
				printf("%03d-%04d %d\n", oIt->first / 10000, oIt->first % 10000, oIt->second);
				bNoDuplicates = false;
			}
		}

		if (bNoDuplicates)
			printf("No duplicates.\n");
		
		if (nNoCases)
			printf("\n");
	}

	return 0;
}