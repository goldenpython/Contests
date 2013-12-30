/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 608 - Counterfeit Dollar                                         */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct WEIGHING {
	string oLeft, oRight;
	int nResult;
};

int GetWeigh(const string &roString, char cCandidate, int nDiff) {
	int nSum = 0;
	for (string::const_iterator oIt = roString.begin(); oIt != roString.end(); oIt++)
		if (*oIt == cCandidate)
			nSum += nDiff;

	return nSum;
}

bool CheckCandidate(const vector<WEIGHING> &roWeightings, char cCandidate, bool bUp) {
	for (int nLoop = 0; nLoop < roWeightings.size(); nLoop++) {
		int nWeighLeft = GetWeigh(roWeightings[nLoop].oLeft, cCandidate, bUp ? -1 : 1);
		int nWeighRight = GetWeigh(roWeightings[nLoop].oRight, cCandidate, bUp ? -1 : 1);
		if (roWeightings[nLoop].nResult != nWeighLeft - nWeighRight)
			return false;
	}

	return true;
}

int main() { 
	const char FIRST_COIN = 'A';
	const char LAST_COIN = 'L';
	const int NO_WEIGHINGS = 3;

	int nNoCases;
	vector<WEIGHING> oWeightings(NO_WEIGHINGS);

	for (cin >> nNoCases; nNoCases--; ) {
		for (int nLoop = 0; nLoop < NO_WEIGHINGS; nLoop++) {
			cin >> oWeightings[nLoop].oLeft >> oWeightings[nLoop].oRight;
			string oResult;
			cin >> oResult;
			if (oResult == "even")
				oWeightings[nLoop].nResult = 0;
			else if (oResult == "up")
				oWeightings[nLoop].nResult = 1;
			else
				oWeightings[nLoop].nResult = -1;
		}

		for (char cCandidate = FIRST_COIN; cCandidate <= LAST_COIN; cCandidate++) {
			if (CheckCandidate(oWeightings, cCandidate, false))
				cout << cCandidate << " is the counterfeit coin and it is heavy." << endl;
			if (CheckCandidate(oWeightings, cCandidate, true))
				cout << cCandidate << " is the counterfeit coin and it is light." << endl;
		}
		
	}

	return 0;
}