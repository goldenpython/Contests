/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13257 - License Plates                                           */


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	stringstream oStringStream(oLine);
	int nNoTestCases;
	for (oStringStream >> nNoTestCases; nNoTestCases--; ) {
		getline(cin, oLine);

		vector<vector<int>> oVecCharPositions(256);
		int nStringLen = static_cast<int>(oLine.size());
		for (int nLoop = 0; nLoop < nStringLen; nLoop++)
			oVecCharPositions[oLine[nLoop]].push_back(nLoop);

		int nSol = 0;
		for (int nFirstChar = 'A'; nFirstChar <= 'Z'; nFirstChar++) {
			if (oVecCharPositions[nFirstChar].size() == 0)
				continue;
			int nFirstCharIndex = oVecCharPositions[nFirstChar][0];

			for (int nLastChar = 'A'; nLastChar <= 'Z'; nLastChar++) {
				if (oVecCharPositions[nLastChar].size() == 0)
					continue;

				int nLastCharIndex = *oVecCharPositions[nLastChar].rbegin();
				if (nLastCharIndex - nFirstCharIndex < 2)
					continue;

				int nMiddleCharCharReferencePos = nFirstCharIndex + 1;

				for (int nMidlleChar = 'A'; nMidlleChar <= 'Z'; nMidlleChar++) {
					const vector<int> &roVecPositions = oVecCharPositions[nMidlleChar];
					auto oIt = lower_bound(roVecPositions.cbegin(), roVecPositions.cend(), nMiddleCharCharReferencePos);
					if (oIt != roVecPositions.cend() && *oIt > nFirstCharIndex && *oIt < nLastCharIndex)
						nSol++;
				}
			}
		}

		cout << nSol << endl;
	}

	return 0;
}