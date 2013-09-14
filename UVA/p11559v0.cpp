/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11559 - Event Planning                                           */


#include <iostream>

using namespace std;

int main() {
	int nNoParticipants;

	while (cin >> nNoParticipants) {
		int nBudget, nNoHotels, nNoWeeks;
		cin >> nBudget >> nNoHotels >> nNoWeeks;
		int nSol = nBudget + 1;

		for (int nLoopHotels = 0; nLoopHotels < nNoHotels; nLoopHotels++) {
			int nRoomPrice;
			cin >> nRoomPrice;
			for (int nLoopWeeks = 0; nLoopWeeks < nNoWeeks; nLoopWeeks++) {
				int nNoBeds;
				cin >> nNoBeds;
				if (nNoBeds >= nNoParticipants && nSol >= nNoParticipants * nRoomPrice)
					nSol = nNoParticipants * nRoomPrice;
			}
		}

		if (nSol <= nBudget)
			cout << nSol << endl;
		else
			cout << "stay home" << endl;

	}

	return 0;
}