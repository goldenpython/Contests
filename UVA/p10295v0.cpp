/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10295 - Hay Points                                               */



#include <stdio.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int main() {
	int nDictSize, nNoJobsDescriptions;
	map<string, int> oDict;
	char szWord[128];

	scanf("%d %d", &nDictSize, &nNoJobsDescriptions);
	for (int nLoop = 0; nLoop < nDictSize; nLoop++) {
		int nValue;
		scanf("%s %d", szWord, &nValue);
		oDict[szWord] = nValue;
	}

	for (int nLoop = 0; nLoop < nNoJobsDescriptions; nLoop++) {
		int nSum = 0;
		while (scanf("%s", szWord), strcmp(szWord, ".")) {
			map<string, int>::iterator oIt = oDict.find(szWord);
			if (oIt != oDict.end())
				nSum += oIt->second;
		}

		printf("%d\n", nSum);
	}

	return 0;
}