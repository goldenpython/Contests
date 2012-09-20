/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 156 - Ananagrams                                                 */



#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;



#define MAX_LINE_LEN	(80 + 2)

struct PREDICATE {
	bool operator() (const char *lhs, const char *rhs) const {
		return strcmp(lhs, rhs) < 0;
	}
};

struct WORD_DESC {
	char *szOrigWord;
	int nNo;
};

char *GetSorted(char *pszWord) {
	static int arrnFreq['z' - 'a' + 1];
	char *psz;
	char *pszRetWord;

	memset(arrnFreq, 0, sizeof(arrnFreq));

	for (psz = pszWord; *psz; psz++)
		if (*psz >= 'a' && *psz <= 'z')
			arrnFreq[*psz - 'a']++;
		else
			arrnFreq[*psz - 'A']++;

	pszRetWord = new char[psz - pszWord + 1];
	psz = pszRetWord;
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < arrnFreq[i]; j++)
			*psz++ = i + 'a';

	*psz = '\0';

	return pszRetWord;
}

int main() {
	char *psz, szLine[MAX_LINE_LEN];
	const char *pszDelims = "\n\t\r ";
	PREDICATE oPred;

	map<char *, WORD_DESC, PREDICATE> oMap;

	while (gets(szLine) && *szLine != '#') {
		for (psz = strtok(szLine, pszDelims); psz; psz = strtok(NULL, pszDelims)) {
			char *pszKey = GetSorted(psz);
			if (!oMap[pszKey].nNo++) {
				oMap[pszKey].szOrigWord = strdup(psz);
			}
		}

	}

	vector<char *> oResult;

	for (map<char *, WORD_DESC, PREDICATE>::iterator it = oMap.begin(); it != oMap.end(); it++) {
		if (it->second.nNo == 1)
			oResult.insert(oResult.end(), it->second.szOrigWord);
	}

	sort(oResult.begin(), oResult.end(), oPred);

	for (int i = 0; i < oResult.size(); i++)
		printf("%s\n", oResult[i]);


	return 0;
}
