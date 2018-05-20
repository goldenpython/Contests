/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10056 - What is the Probability ?                                */


/*
	Let	Pr1 = probability that player with index 1 wins at round 1, Pr2 probability that player with index 1 wins at round 2

	Pr1 = p
	Pr2 = p * (1 - p) ^ NoPlayers
	Pr3 = p * (1 - p) ^ (2 * NoPlayers)
	Pr3 = p * (1 - p) ^ (3 * NoPlayers)

	Probability that Player 1 wins is Pr = Pr1 + Pr2 + .... . Let A = (1 - p) ^ NoPlayers.
	Thus Pr = p * (1 + A^1 + A^2 + A^3 + ..... )
	Since A < 1 ==> Pr = p * (1 / (1 - A)), Pr = p / (1 - A).

	The probability that player with index I wins means that we have to "shift" Pr with I-1 unsuccessful dice rolls.
	Thus the answer is ((1 - p) ^ (I - 1)) * Pr
*/


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nNoPlayers, nTargetPlayerIndex;
		double lfEventPobability;
		cin >> nNoPlayers >> lfEventPobability >> nTargetPlayerIndex;
		auto lfA = pow(1 - lfEventPobability, nNoPlayers);
		auto lfPr = lfEventPobability / (1 - lfA);
		auto lfAnswer = pow(1 - lfEventPobability, nTargetPlayerIndex - 1) * lfPr;
		if (lfEventPobability < 1E-10)
			lfAnswer = 0;
		cout << setprecision(4) << fixed << lfAnswer << endl;
	}

	return 0;
}