/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11489 - Integer Game                                             */


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;

	for (auto nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		string oLine;
		cin >> oLine;

		auto oVecnStats = accumulate(
			oLine.cbegin(), 
			oLine.cend(), 
			vector<int>(3), 
			[](vector<int> &roVecnStats, char cChar) -> vector<int> { 
				roVecnStats[(cChar - '0') % 3]++; 
				return roVecnStats; 
			}
		);

		auto nSum = (oVecnStats[1] + oVecnStats[2] * 2) % 3;
		bool bSWins = false;
		if (!nSum) {
			if (oVecnStats[0] % 2)
				bSWins = true;
		} else {
			if (oVecnStats[nSum] && !(oVecnStats[0] % 2))
				bSWins = true;
		}

		cout << "Case " << nCaseLoop << ": " << (bSWins ? 'S' : 'T') << endl;
	}

	return 0;
}