/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11958 - Coming Home                                              */


#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		const int MAX_TRAVELING_TIME_IN_SECONDS = 1000 * 60, SECONDS_IN_A_DAY = 24 * 60 * 60;
		int nNoBuses, nMinDuration = SECONDS_IN_A_DAY + MAX_TRAVELING_TIME_IN_SECONDS;
		struct tm oCurrentTime = { 0, 0, 0, 1, 0, 1982 - 1900 };
		cin >> nNoBuses >> get_time(&oCurrentTime, "%H:%M");
		for (auto oCurrentClock = mktime(&oCurrentTime); nNoBuses--; ) {
			struct tm oBusTime = { 0, 0, 0, 1, 0, 1982 - 1900 };
			int nTripDuration;
			cin >> get_time(&oBusTime, "%H:%M") >> nTripDuration;

			auto nDiffTime = static_cast<int>(difftime(mktime(&oBusTime), oCurrentClock));
			if (nDiffTime < 0)
				nDiffTime += SECONDS_IN_A_DAY;
			nDiffTime += nTripDuration * 60;
			if (nDiffTime < nMinDuration)
				nMinDuration = nDiffTime;
		}

		cout << "Case " << nCaseLoop << ": " << (nMinDuration / 60) << endl;
	}
	return 0;
}