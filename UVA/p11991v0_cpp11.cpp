/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11991 - Easy Problem from Rujia Liu?                             */


#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

int main() {
	for (int nNoNumbers, nNoQueries; cin >> nNoNumbers >> nNoQueries;) {
		typedef unordered_map<unsigned int, vector<unsigned int>> STRUCT_TYPE;
		// typedef map<unsigned int, vector<unsigned int>> STRUCT_TYPE;

		STRUCT_TYPE oDict;
		for (int nLoop = 1; nLoop <= nNoNumbers; nLoop++) {
			unsigned int nNumber;
			cin >> nNumber;
			oDict[nNumber].push_back(nLoop);
		}

		while (nNoQueries--) {
			unsigned int nK, nV, nResponse = 0;
			cin >> nK >> nV;
			auto oIt = oDict.find(nV);
			if (oIt != oDict.end() && oIt->second.size() >= nK)
				nResponse = oIt->second[nK - 1];
			cout << nResponse << endl;
		}
	}
	return 0;
}