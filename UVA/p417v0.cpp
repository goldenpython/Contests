/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 417 - Word Index                                                 */

#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<string> arrAll;
	vector<int> arrBeginIndex;
	char szString[8];

	int nLoop1, nLoop2, nLoop3, nLoop4, nLoop5;

	arrAll.reserve(90000);

	arrBeginIndex.insert(arrBeginIndex.end(), arrAll.size());

	szString[1] = '\0';
	for (nLoop1 = 'a'; nLoop1 <= 'z'; nLoop1++) {
		szString[0] = nLoop1;
		arrAll.insert(arrAll.end(), szString);
	}

	arrBeginIndex.insert(arrBeginIndex.end(), arrAll.size());

	szString[2] = '\0';
	for (nLoop1 = 'a'; nLoop1 <= 'z'; nLoop1++) {
		szString[0] = nLoop1;
		for (nLoop2 = nLoop1 + 1; nLoop2 <= 'z'; nLoop2++) {
			szString[1] = nLoop2;
			arrAll.insert(arrAll.end(), szString);
		}
	}

	arrBeginIndex.insert(arrBeginIndex.end(), arrAll.size());

	szString[3] = '\0';
	for (nLoop1 = 'a'; nLoop1 <= 'z'; nLoop1++) {
		szString[0] = nLoop1;
		for (nLoop2 = nLoop1 + 1; nLoop2 <= 'z'; nLoop2++) {
			szString[1] = nLoop2;
			for (nLoop3 = nLoop2 + 1; nLoop3 <= 'z'; nLoop3++) {
				szString[2] = nLoop3;
				arrAll.insert(arrAll.end(), szString);
			}
		}
	}

	arrBeginIndex.insert(arrBeginIndex.end(), arrAll.size());

	szString[4] = '\0';
	for (nLoop1 = 'a'; nLoop1 <= 'z'; nLoop1++) {
		szString[0] = nLoop1;
		for (nLoop2 = nLoop1 + 1; nLoop2 <= 'z'; nLoop2++) {
			szString[1] = nLoop2;
			for (nLoop3 = nLoop2 + 1; nLoop3 <= 'z'; nLoop3++) {
				szString[2] = nLoop3;
				for (nLoop4 = nLoop3 + 1; nLoop4 <= 'z'; nLoop4++) {
					szString[3] = nLoop4;
					arrAll.insert(arrAll.end(), szString);
				}
			}
		}
	}

	arrBeginIndex.insert(arrBeginIndex.end(), arrAll.size());

	szString[5] = '\0';
	for (nLoop1 = 'a'; nLoop1 <= 'z'; nLoop1++) {
		szString[0] = nLoop1;
		for (nLoop2 = nLoop1 + 1; nLoop2 <= 'z'; nLoop2++) {
			szString[1] = nLoop2;
			for (nLoop3 = nLoop2 + 1; nLoop3 <= 'z'; nLoop3++) {
				szString[2] = nLoop3;
				for (nLoop4 = nLoop3 + 1; nLoop4 <= 'z'; nLoop4++) {
					szString[3] = nLoop4;
					for (nLoop5 = nLoop4 + 1; nLoop5 <= 'z'; nLoop5++) {
						szString[4] = nLoop5;
						arrAll.insert(arrAll.end(), szString);
					}
				}
			}
		}
	}

	arrBeginIndex.insert(arrBeginIndex.end(), arrAll.size());

	while (gets(szString)) {
		int nSize = strlen(szString);
		for (char *psz = szString + 1; *psz; psz++)
			if (*psz <= *(psz - 1)) {
				printf("%d\n", 0);
				nSize = -1;
				break;
			}

		if (nSize > 0) {
			vector<string>::iterator oIt = lower_bound(arrAll.begin() + arrBeginIndex[nSize - 1], arrAll.begin() + arrBeginIndex[nSize], szString);
			printf("%d\n", oIt - arrAll.begin() + 1);
		}
	}


	return 0;
}