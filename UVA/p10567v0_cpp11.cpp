/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10567 - Helping Fill Bates                                       */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	const int MAX_LINE_LEN = 1000000 + 5;
	string oCandidates;
	oCandidates.reserve(MAX_LINE_LEN);
	cin >> oCandidates;

	vector<vector<int>> oVec2nCharPositons(256, vector<int>());

	const int nSize = static_cast<int>(oCandidates.size());
	for (int nLoop = 0; nLoop < nSize; nLoop++)
		oVec2nCharPositons[oCandidates[nLoop]].push_back(nLoop);

	int nNoQueries;
	for (cin >> nNoQueries; nNoQueries--; ) {
		string oQueryString;
		cin >> oQueryString;

		int nCurrentPos = -1, nFirstMatch, nLastMatch = -1;
		for (auto oIt = oQueryString.cbegin(); ; ) {
			const auto &roVecnPositions = oVec2nCharPositons[*oIt];
			auto oItSearch = lower_bound(roVecnPositions.cbegin(), roVecnPositions.cend(), nCurrentPos + 1);
			if (oItSearch == roVecnPositions.cend())
				break;

			if (oIt == oQueryString.cbegin())
				nFirstMatch = *oItSearch;
			if (++oIt == oQueryString.cend()) {
				nLastMatch = *oItSearch;
				break;
			}
			nCurrentPos = *oItSearch;
		}

		if (nLastMatch < 0)
			cout << "Not matched" << endl;
		else
			cout << "Matched " << nFirstMatch << ' ' << nLastMatch << endl;
	}

	return 0;
}