/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11850 - Alaska                                                   */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int nNoStations;

	while ((cin >> nNoStations), nNoStations) {
		vector<int> oDistances(nNoStations);
		for (vector<int>::iterator oIt = oDistances.begin(); oIt != oDistances.end(); oIt++)
			cin >> *oIt;
		sort(oDistances.begin(), oDistances.end());

		const int MAX_DIST = 200;
		const int DIST = 1422;
		bool bPossible = (DIST - oDistances[nNoStations - 1]) <= MAX_DIST / 2;
		if (bPossible) {
			for (vector<int>::iterator oIt = oDistances.begin() + 1; oIt != oDistances.end(); oIt++)
				if (*oIt - *(oIt - 1) > MAX_DIST) {
					bPossible = false;
					break;
				}
		}
		cout << (bPossible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}

	return 0;
}
