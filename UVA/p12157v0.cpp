/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12157 - Tariff Plan                                              */


#include <iostream>

using namespace std;

template <int SECONDS, int CENTS>
int GetCost(int nNoSeconds) {
	return (nNoSeconds / SECONDS + 1) * CENTS;
}

int main() {
	int nNoCases;

	cin >> nNoCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		int nNoCalls, nNoSeconds, nMile = 0, nJuice = 0;
		for (cin >> nNoCalls; nNoCalls--; ) {
			cin >> nNoSeconds;
			nMile += GetCost<30, 10>(nNoSeconds);
			nJuice += GetCost<60, 15>(nNoSeconds);
		}

		cout << "Case " << nCaseLoop << ": ";
		if (nMile < nJuice)
			cout << "Mile " << nMile;
		else if (nMile > nJuice)
			cout << "Juice " << nJuice;
		else
			cout << "Mile Juice " << nJuice;

		cout << endl;
	}

	return 0;
}