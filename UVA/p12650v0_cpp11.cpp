/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12650 - Dangerous Dive                                           */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int nN, nR;
	while (cin >> nN >> nR) {
		vector<int> oVecIds;
		oVecIds.reserve(nR);
		for (int nLoop = 0; nLoop < nR; nLoop++) {
			int nId;
			cin >> nId;
			oVecIds.push_back(nId);
		}

		if (oVecIds.size() == nN) {
			cout << '*' << endl;
			continue;
		}

		sort(oVecIds.begin(), oVecIds.end());
		auto oItCurrent = oVecIds.cbegin();
		for (int nLoop = 1; nLoop <= nN; nLoop++)
			if (nLoop == *oItCurrent)
				oItCurrent = next(oItCurrent);
			else
				cout << nLoop << ' ';

		cout << endl;
	}

	return 0;
}