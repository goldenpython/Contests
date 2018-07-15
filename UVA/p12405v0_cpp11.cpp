/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12405 - Scarecrow                                                */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nFieldLen;
		cin >> nFieldLen;

		string oField;
		cin >> oField;
		oField += '#';

		int nSol = 0, nSkipSteps = 0;
		bool bPrevIsFertile = (oField[0] == '.'), bSkipNext = false;
		for (auto oIt = next(oField.cbegin()); oIt != oField.cend(); ++oIt) {
			bool bCurrentIsFertile = (*oIt == '.');

			if (!nSkipSteps) {
				if (bPrevIsFertile)
					nSol++, nSkipSteps = 2;
			} else {
				nSkipSteps--;
			}

			bPrevIsFertile = bCurrentIsFertile;
		}

		cout << "Case " << nCaseLoop << ": " << nSol << endl;
	}

	return 0;
}