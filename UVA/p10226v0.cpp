/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10226 - Hardwood Species                                         */


#include <map>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	int nNoCases = atoi(oLine.c_str());

	getline(cin, oLine);
	while (nNoCases--) {
		map<string, int> oTrees;
		int nTotalTrees = 0;
		while (getline(cin, oLine), oLine.size()) {
			oTrees[oLine]++;
			nTotalTrees++;
		}

		for (map<string, int>::iterator oIt = oTrees.begin(); oIt != oTrees.end(); oIt++)
			cout << oIt->first << " " << setprecision(4) << fixed << (oIt->second * 100.0) / nTotalTrees << endl;
		if (nNoCases)
			cout << endl;
	}

	return 0;
}