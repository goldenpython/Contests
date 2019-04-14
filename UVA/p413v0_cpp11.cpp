/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 413 - Up and Down Sequences                                      */


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	for (int nPrev; (cin >> nPrev), nPrev; ) {
		enum STATE { UP, DOWN, UNINITIALIZED };
		STATE nState = UNINITIALIZED;

		int nNoUps = 0, nNoUpSequences = 0, nNoDowns = 0, nNoDownSequences = 0, nNoUninitialized = 0, nNoValues = 1;
		for (int nCurrent; (cin >> nCurrent), nCurrent; nNoValues++) {
			switch (nState) {
				case UNINITIALIZED:
					if (nCurrent > nPrev)
						nState = UP, nNoUps = nNoUninitialized + 1, nNoUpSequences = 1;
					else if (nCurrent < nPrev)
						nState = DOWN, nNoDowns = nNoUninitialized + 1, nNoDownSequences = 1;
					else
						nNoUninitialized++;
					break;

				case UP:
					if (nCurrent >= nPrev)
						nNoUps++;
					else if (nCurrent < nPrev)
						nState = DOWN, nNoDowns++, nNoDownSequences++;
					break;

				case DOWN:
					if (nCurrent > nPrev)
						nState = UP, nNoUps++, nNoUpSequences++;
					else if (nCurrent <= nPrev)
						nNoDowns++;
					break;
			}

			nPrev = nCurrent;
		}

		cout	<< "Nr values = " << nNoValues << ":  "
				<< setprecision(6) << fixed 
				<< (nNoUpSequences ? static_cast<float>(nNoUps) / nNoUpSequences : 0.0f)
				<< " "
				<< (nNoDownSequences ? static_cast<float>(nNoDowns) / nNoDownSequences : 0.0f)
				<< endl;
	}
	return 0;
}

