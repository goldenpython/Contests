/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11459 - Snakes and Ladders                                       */


#include <iostream>
#include <vector>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nNoPlayers, nNoSnakes, nNoDiceRolls;
		cin >> nNoPlayers >> nNoSnakes >> nNoDiceRolls;

		const int MAX_POS = 100;
		vector<int> oVecnJumpPos(MAX_POS + 1);
		for (int nLoop = 0; nLoop < nNoSnakes; nLoop++) {
			int nFrom, nTo;
			cin >> nFrom >> nTo;
			oVecnJumpPos[nFrom] = nTo;
		}

		bool bWinnerExists = false;
		vector<int> oVecnPlayerPos(nNoPlayers, 1);
		for (int nDiceRollLoop = 0; nDiceRollLoop < nNoDiceRolls; nDiceRollLoop++) {
			int nDiceRoll;
			cin >> nDiceRoll;

			if (bWinnerExists)
				continue;

			int nPlayerIndex = nDiceRollLoop % nNoPlayers;
			oVecnPlayerPos[nPlayerIndex] += nDiceRoll;
			if (oVecnPlayerPos[nPlayerIndex] >= MAX_POS) {
				oVecnPlayerPos[nPlayerIndex] = MAX_POS;
				bWinnerExists = true;
			}

			while (oVecnJumpPos[oVecnPlayerPos[nPlayerIndex]]) {
				oVecnPlayerPos[nPlayerIndex] = oVecnJumpPos[oVecnPlayerPos[nPlayerIndex]];
				if (oVecnPlayerPos[nPlayerIndex] >= MAX_POS) {
					oVecnPlayerPos[nPlayerIndex] = MAX_POS;
					bWinnerExists = true;
					break;
				}
			}
		}

		for (int nPlayerLoop = 0; nPlayerLoop < nNoPlayers; nPlayerLoop++)
			cout << "Position of player " << nPlayerLoop + 1 << " is " << oVecnPlayerPos[nPlayerLoop] << "." << endl;
	}

	return 0;
}