/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 574 - Sum It Up                                                  */


#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<pair<int, int>> g_oVecNumbers;
stringstream g_oSol;
vector<pair<int, int>> g_oCurrentSol;

void bk(int nStep, int nSum, int nLastIndex) {
	for (int nLoop = nLastIndex + 1; nLoop < g_oVecNumbers.size(); nLoop++) {
		for (int nCount = g_oVecNumbers[nLoop].second; nCount; nCount--) {
			int nDiff = nSum - g_oVecNumbers[nLoop].first * nCount;
			if (nDiff > 0) {
				g_oCurrentSol[nStep].first = nLoop;
				g_oCurrentSol[nStep].second = nCount;
				bk(nStep + 1, nDiff, nLoop);
			} else if (nDiff == 0) {
				g_oCurrentSol[nStep].first = nLoop;
				g_oCurrentSol[nStep].second = nCount;
				for (int nLoop = 0; nLoop <= nStep; nLoop++)
					for (int nCount = 0; nCount < g_oCurrentSol[nLoop].second; nCount++)
						if (!nLoop && !nCount)
							g_oSol << g_oVecNumbers[g_oCurrentSol[nLoop].first].first;
						else
							g_oSol << "+" << g_oVecNumbers[g_oCurrentSol[nLoop].first].first;
				g_oSol << endl;
			}
		}
	}
}

int main() {

	for (int nSum, nNoNumbers; (cin >> nSum >> nNoNumbers) && nSum && nNoNumbers; ) {
		g_oVecNumbers.clear();
		g_oSol = stringstream();
		g_oCurrentSol.clear();

		int nLastNumber = -1;
		while (nNoNumbers--) {
			int nNumber;
			cin >> nNumber;
			if (nNumber != nLastNumber) {
				g_oVecNumbers.push_back(pair<int, int>(nNumber, 1));
				nLastNumber = nNumber;
			} else {
				(g_oVecNumbers.end() - 1)->second++;
			}
			g_oCurrentSol.push_back(pair<int, int>(0, 0));
		}

		bk(0, nSum, -1);
		string oSolString = g_oSol.str();
		cout << "Sums of " << nSum << ":" << endl;
		if (oSolString.size() == 0)
			cout << "NONE" << endl;
		else
			cout << oSolString;
	}

	return 0;
}