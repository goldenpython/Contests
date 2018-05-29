/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10491 - Cows and Cars                                            */


#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	for (int nNoCows, nNoCars, nNoShows; cin >> nNoCows >> nNoCars >> nNoShows; ) {
		int nTotalEvents = nNoCows + nNoCars;
		int nTotalEventsAfterShow = nTotalEvents - 1 - nNoShows;
		auto lfPrCowAtFirstTry = static_cast<double>(nNoCows) / nTotalEvents;
		auto lfPrCarAfterSecondTryIfCowAtFirst = static_cast<double>(nNoCars) / nTotalEventsAfterShow;

		auto lfPrCarAtFirstTry = static_cast<double>(nNoCars) / nTotalEvents;
		auto lfPrCarAfterSecondTryIfCarAtFirst = static_cast<double>(nNoCars - 1) / nTotalEventsAfterShow;

		auto lfAnswer = lfPrCowAtFirstTry * lfPrCarAfterSecondTryIfCowAtFirst + lfPrCarAtFirstTry * lfPrCarAfterSecondTryIfCarAtFirst;
		cout << setprecision(5) << fixed << lfAnswer << endl;
	}

	return 0;
}