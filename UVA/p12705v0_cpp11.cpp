/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12705 - Breaking Board                                           */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	for (int nNoTestCasesLeft = stoi(oLine); nNoTestCasesLeft--; ) {
		getline(cin, oLine);
		vector<int> oVecnFreq(256);
		for (auto cChar : oLine)
			if (cChar != ' ')
				oVecnFreq[cChar]++;
		sort(oVecnFreq.begin(), oVecnFreq.end(), greater<int>());

		static const vector<int> oVecnCoeff = { 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 11, 11, 12};
		auto nRes = inner_product(oVecnCoeff.cbegin(), oVecnCoeff.cend(), oVecnFreq.cbegin(), 0);
		cout << nRes << endl;
	}

	return 0;
}