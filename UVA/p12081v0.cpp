/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12081 - Reduced ID Numbers                                       */



#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nG;
		vector<int> oVecNumbers;
		for (cin >> nG; nG--; ) {
			int nNumber;
			cin >> nNumber;
			oVecNumbers.push_back(nNumber);
		}

		for (int nSol = 1; ; nSol++) {
			set<int> oSetSins;
			for (vector<int>::iterator oIt = oVecNumbers.begin(); oIt != oVecNumbers.end(); oIt++) {
				int nNumber = *oIt % nSol;
				if (oSetSins.find(nNumber) != oSetSins.end())
					break;
				oSetSins.insert(oSetSins.begin(), nNumber);
			}

			if (oSetSins.size() == oVecNumbers.size()) {
				cout << nSol << endl;
				break;
			}
		}
	}

	return 0;
}