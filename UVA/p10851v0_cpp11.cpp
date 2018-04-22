/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10851 - 2D Hieroglyphs decoder                                   */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	for (int nNoTestCases = stoi(oLine); nNoTestCases--; ) {
		const int NO_LINES = 10;
		getline(cin, oLine);
		vector<char> oVecRes(oLine.size());
		for (int nLoop = 0; nLoop < NO_LINES - 2; nLoop++) {
			getline(cin, oLine);
			transform(
				oVecRes.cbegin(),
				oVecRes.cend(),
				oLine.cbegin(),
				oVecRes.begin(),
				[nPower = 1 << nLoop] (char nCharDest, char nChar) { 
					return nCharDest + nPower * (nChar == '\\' ? 1 : 0); 
				}
			);
		}

		getline(cin, oLine); getline(cin, oLine);

		string oAnswer(oVecRes.cbegin() + 1, oVecRes.cend() - 1);
		cout << oAnswer << endl;
	}

	return 0;
}