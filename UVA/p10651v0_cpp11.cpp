/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10651 - Pebble Solitaire                                         */


#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int GetIntFromString(const string &roGame) {
	int nRetValue = 0;
	for (auto oIt = roGame.cbegin(); oIt != roGame.cend(); ++oIt)
		nRetValue = (nRetValue << 1) | (*oIt != '-');

	return nRetValue;
}

const int GAME_UNINITIALIZED = -1;
const int GAME_NO_MORE_MOVES = 0;
vector<int> g_VecnGames(1 << 12, GAME_UNINITIALIZED);

#define BIT_ISSET(n, b)			(!!((n) & (1 << (b))))
#define BIT_SET(n, b)			((n) | (1 << (b)))
#define BIT_CLEAR(n, b)			((n) & ~(1 << (b)))

int GetMin(const int nGame) {
	if (g_VecnGames[nGame] != GAME_UNINITIALIZED)
		return g_VecnGames[nGame];

	int nMinMoves = INT_MAX;
	int nNoBits = 0;

	bool bPrevBitSet = BIT_ISSET(nGame, 0), bCurrentBitSet = BIT_ISSET(nGame, 1), bNextBitSet;
	if (bPrevBitSet)
		nNoBits++;
	if (bCurrentBitSet)
		nNoBits++;

	for (int nBitLoop = 1; nBitLoop <= 10; nBitLoop++, bPrevBitSet = bCurrentBitSet, bCurrentBitSet = bNextBitSet) {
		if (bNextBitSet = BIT_ISSET(nGame, nBitLoop + 1))
			nNoBits++;

		if (bCurrentBitSet) {
			if (bPrevBitSet && !bNextBitSet) {
				int nNewPos = BIT_SET(nGame, nBitLoop + 1);
				nNewPos = BIT_CLEAR(nNewPos, nBitLoop);
				nNewPos = BIT_CLEAR(nNewPos, nBitLoop - 1);
				nMinMoves = min(nMinMoves, GetMin(nNewPos));
			}
			if (!bPrevBitSet && bNextBitSet) {
				int nNewPos = BIT_SET(nGame, nBitLoop - 1);
				nNewPos = BIT_CLEAR(nNewPos, nBitLoop);
				nNewPos = BIT_CLEAR(nNewPos, nBitLoop + 1);
				nMinMoves = min(nMinMoves, GetMin(nNewPos));
			}
		}
	}

	if (nMinMoves == INT_MAX)
		nMinMoves = nNoBits;

	return g_VecnGames[nGame] = nMinMoves;
}

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		string oGame;
		cin >> oGame;
		int nGame = GetIntFromString(oGame);
		cout << GetMin(nGame) << endl;
	}

	return 0;
}