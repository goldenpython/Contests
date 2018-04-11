/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 865 - Substitution Cypher                                        */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	int nNoTestCases = stoi(oLine);
	getline(cin, oLine);
	while (nNoTestCases--) {
		string oPlaintext, oSubstitution;

		getline(cin, oPlaintext);
		getline(cin, oSubstitution);

		cout << oSubstitution << endl << oPlaintext << endl;

		vector<char> oVecSubstitutionMap(256, 0);
		for (int nLoop = 0; nLoop < oPlaintext.size(); nLoop++)
			oVecSubstitutionMap[oPlaintext[nLoop]] = oSubstitution[nLoop];

		for (string oText; getline(cin, oText) && oText.size() > 0; ) {
			transform(
				oText.cbegin(), 
				oText.cend(), 
				oText.begin(), 
				[&roVecSubstitutionMap = oVecSubstitutionMap] (char c) { 
					return roVecSubstitutionMap[c] ? roVecSubstitutionMap[c] : c;
				}
			);
			cout << oText << endl;
		}

		if (nNoTestCases)
			cout << endl;
	}

	return 0;
}
