/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1339 - Ancient Cipher                                            */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

	while (true) {
		string oLine1, oLine2;
		if (!getline(cin, oLine1) || !getline(cin, oLine2))
			break;
		
		vector<int> oVecFreq1(256), oVecFreq2(256);
		for (int nLoop = 0; nLoop < oLine1.size(); nLoop++) {
			oVecFreq1[oLine1[nLoop]]++;
			oVecFreq2[oLine2[nLoop]]++;
		}

		sort(oVecFreq1.begin() + 'A', oVecFreq1.begin() + 'Z' + 1);
		sort(oVecFreq2.begin() + 'A', oVecFreq2.begin() + 'Z' + 1);

		cout << (equal(oVecFreq1.begin() + 'A', oVecFreq1.begin() + 'Z' + 1, oVecFreq2.begin() + 'A') ? "YES" : "NO") << endl;
	}

	return 0;
}