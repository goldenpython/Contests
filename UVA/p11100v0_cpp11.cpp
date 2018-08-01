/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11100 - The Trip, 2007                                           */


#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	for (int nN; (cin >> nN), nN; ) {
		int nMaxFreq = 0;
		map<int, int> oMapSizeCount;
		while (nN--) {
			int nSize;
			cin >> nSize;
			nMaxFreq = max(++oMapSizeCount[nSize], nMaxFreq);
		}

		vector<vector<int>> oVec2nSol(nMaxFreq, vector<int>());
		int nIndex = 0;
		for (auto oIt = oMapSizeCount.cbegin(); oIt != oMapSizeCount.cend(); ++oIt) {
			for (int nLoop = oIt->second; nLoop; nLoop--)
				oVec2nSol[nIndex++ % nMaxFreq].push_back(oIt->first);
		}

		cout << nMaxFreq << endl;
		for (auto oIt = oVec2nSol.cbegin(); oIt != oVec2nSol.cend(); ++oIt) {
			cout << (*oIt)[0];
			for_each(next(oIt->cbegin()), oIt->end(), [](int nValue) { cout << ' ' << nValue; } );
			cout << endl;
		}

		cout << endl;
	}

	return 0;
}
