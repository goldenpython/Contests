/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10190 - Divide, But Not Quite Conquer!                           */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	for (int nN, nM; cin >> nN >> nM; ) {
		vector<int> oVecPowers;

		if (nN > 1 && nM > 1) {
			while (!(nN % nM)) {
				oVecPowers.push_back(nN);
				nN /= nM;
			}
		}

		if (nN != 1 || !oVecPowers.size()) {
			cout << "Boring!" << endl;
		} else {
			for_each(oVecPowers.cbegin(), oVecPowers.cend(), [](int nNumber) { cout << nNumber << ' '; });
			cout << '1' << endl;
		}
	}

	return 0;
}