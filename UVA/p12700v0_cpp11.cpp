/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12700 - Banglawash                                               */


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int nNoCases;
	cin >> nNoCases;
	
	for (int nCaseLoop = 1; nCaseLoop <= nNoCases; nCaseLoop++) {
		int nN;
		cin >> nN;

		string oMatches;
		cin >> oMatches;

		int nB = 0, nW = 0, nT = 0, nA = 0;
		for_each(
			oMatches.cbegin(), 
			oMatches.cend(), 
			[&nB, &nW, &nT, &nA] (const char c) {
				switch (c) {
					case 'B':
						nB++;
						break;
					case 'W':
						nW++;
						break;
					case 'T':
						nT++;
						break;
					case 'A':
						nA++;
						break;
				}
			}
		);

		cout << "Case " << nCaseLoop << ": ";

		if (nB > 0 && !nW && !nT) {
			cout << "BANGLAWASH" << endl;
		} else if (nW > 0 && !nB && !nT) {
			cout << "WHITEWASH" << endl;
		} else if (nA != nN) {
			if (nB == nW) {
				cout << "DRAW " << nB << " " << nT << endl;
			} else {
				if (nB > nW) {
					cout << "BANGLADESH " << nB << " - " << nW << endl;
				} else {
					cout << "WWW " << nW << " - " << nB << endl;
				}
			}
		} else {
			cout << "ABANDONED" << endl;
		}
	}

	return 0;
}