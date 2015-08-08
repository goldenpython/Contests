/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11577 - Letter Frequency                                         */


#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	for (int nNoCases = atoi(oLine.c_str()); nNoCases--; ) {
		getline(cin, oLine);
		map<char, int> oLetterFreq;
		set<char> oSol;
		int nMaxFreq = -1;

		for_each(
			oLine.begin(), 
			oLine.end(), 
			[&oLetterFreq, &oSol, &nMaxFreq](const char c) {
				const char cUpper = tolower(c);
				if (!isalpha(cUpper))
					return;
				int nFreq = ++oLetterFreq[cUpper];
				if (nMaxFreq < nFreq) {
					nMaxFreq = nFreq;
					oSol.clear();
					oSol.insert(cUpper);
				} else if (nMaxFreq == nFreq) {
					oSol.insert(cUpper);
				}
			}
		);

		for_each(oSol.begin(), oSol.end(), [](char c) { cout << c; });
		cout << endl;
	}

	return 0;
}