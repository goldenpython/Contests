/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10226 - Hardwood Species                                         */


#include <map>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main() {
	const int MAX_SPECIES_NAME_LEN = 32;
	const int MAX_SPECIES = 10000;

	char arrszSpecies[MAX_SPECIES][MAX_SPECIES_NAME_LEN];

	int nNoCases = atoi(gets(arrszSpecies[0]));

	auto pred = [](const char *const pszLHS, const char *const pszRHS) { return strcmp(pszLHS, pszRHS) < 0; };
	map<const char *, int, decltype(pred)> oTrees(pred);

	gets(arrszSpecies[0]);
	while (nNoCases--) {
		oTrees.clear();

		int nTotalTrees = 0, nNoSpecies = 0;
		char *pszCurrent = arrszSpecies[nNoSpecies];
		while (gets(pszCurrent) && *pszCurrent) {
			auto it = oTrees.find(pszCurrent);
			if (it == oTrees.end()) {
				oTrees.insert(pair<const char *, int>(pszCurrent, 1));
				pszCurrent = arrszSpecies[++nNoSpecies];
			} else {
				it->second++;
			}

			nTotalTrees++;
		}

		for (auto oIt = oTrees.cbegin(); oIt != oTrees.cend(); ++oIt)
			printf("%s %.4f\n", oIt->first, oIt->second * 100.0 / nTotalTrees);
		if (nNoCases)
			printf("\n");
	}

	return 0;
}
