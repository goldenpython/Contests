/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11292 - Dragon of Loowater                                       */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int nN, nM;
	while ((cin >> nN >> nM) && nN && nM) {
		vector<int> oVecDiameters, oVecHeights;
		while (nN--) {
			int nValue;
			cin >> nValue;
			oVecDiameters.push_back(nValue);
		}
		sort(oVecDiameters.begin(), oVecDiameters.end());

		while (nM--) {
			int nValue;
			cin >> nValue;
			oVecHeights.push_back(nValue);
		}
		sort(oVecHeights.begin(), oVecHeights.end());

		int nSol = 0;
		auto oItDiameters = oVecDiameters.cbegin(), oItHeights = oVecHeights.cbegin(); 
		while (oItDiameters != oVecDiameters.cend() && oItHeights != oVecHeights.cend()) {
			if (*oItDiameters <= *oItHeights) {
				nSol += *oItHeights++;
				oItDiameters++;
			} else {
				oItHeights++;
			}
		}

		if (oItDiameters != oVecDiameters.end())
			cout << "Loowater is doomed!" << endl;
		else
			cout << nSol << endl;
	}

	return 0;
}