/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10361 - Automatic Poetry                                         */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);
	for (int nNoTestCasesLeft = stoi(oLine); nNoTestCasesLeft--; ) {
		getline(cin, oLine);
		auto nIndex1 = oLine.find('<');
		auto nIndex2 = oLine.find('>', nIndex1 + 1);
		auto nIndex3 = oLine.find('<', nIndex2 + 1);
		auto nIndex4 = oLine.find('>', nIndex3 + 1);

		auto oS1 = oLine.substr(0, nIndex1);
		auto oS2 = oLine.substr(nIndex1 + 1, nIndex2 - nIndex1 - 1);
		auto oS3 = oLine.substr(nIndex2 + 1, nIndex3 - nIndex2 - 1);
		auto oS4 = oLine.substr(nIndex3 + 1, nIndex4 - nIndex3 - 1);
		auto oS5 = oLine.substr(nIndex4 + 1);

		cout << oS1 << oS2 << oS3 << oS4 << oS5 << endl;	

		getline(cin, oLine);
		cout << oLine.substr(0, oLine.size() - 3) << oS4 << oS3 << oS2 << oS5 << endl;
	}

	return 0;
}