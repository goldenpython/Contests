/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 978 - Lemmings Battle!                                           */


#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

void PrintMultiset(const multiset<int, greater<int>>& roSet) {
	for (auto oIt = roSet.begin(); oIt != roSet.end(); oIt++)
		cout << *oIt << endl;
}

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;

	while (nNoTestCases--) {
		int nB, nSG, nSB;
		cin >> nB >> nSG >> nSB;
		multiset<int, greater<int>> oSetSG, oSetSB;
		while (nSG--) {
			int nNumber;
			cin >> nNumber;
			oSetSG.insert(nNumber);
		}

		while (nSB--) {
			int nNumber;
			cin >> nNumber;
			oSetSB.insert(nNumber);
		}

		while (true) {
			int nBattleFieldIndex = 0;
			vector<int> oVecNewSG, oVecNewSB;
			for (auto oItSG = oSetSG.cbegin(), oItSB = oSetSB.cbegin(); oItSG != oSetSG.cend() && oItSB != oSetSB.cend() && nBattleFieldIndex < nB; nBattleFieldIndex++) {
				int nDiff = *oItSG - *oItSB;
				if (nDiff > 0)
					oVecNewSG.push_back(nDiff);
				else if (nDiff < 0)
					oVecNewSB.push_back(-nDiff);

				oItSG = oSetSG.erase(oItSG);
				oItSB = oSetSB.erase(oItSB);
			}

			oSetSG.insert(oVecNewSG.begin(), oVecNewSG.end());
			oSetSB.insert(oVecNewSB.begin(), oVecNewSB.end());

			if (!oSetSG.size())  {
				if (!oSetSB.size()) {
					cout << "green and blue died" << endl;
					break;
				} else {
					cout << "blue wins" << endl;
					PrintMultiset(oSetSB);
					break;
				}
			} else if (!oSetSB.size()) {
				cout << "green wins" << endl;
				PrintMultiset(oSetSG);
				break;
			}
		}
		
		if (nNoTestCases)
			cout << endl;
	}

	return 0;
}