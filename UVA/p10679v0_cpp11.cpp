/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10679 - I Love Strings!!                                         */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// from https://www.ics.uci.edu/~eppstein/161/960227.html
vector<int> GetLongestSuffixPreffixTable(const string &roPattern) {
	const auto nLen = roPattern.size();

	vector<int> oVecnLSP(nLen + 1);
	oVecnLSP[0] = -1;
	for (int nLoop = 0; nLoop < nLen; nLoop++) {
		oVecnLSP[nLoop + 1] = oVecnLSP[nLoop] + 1;
		while (oVecnLSP[nLoop + 1] > 0 &&
			roPattern[nLoop] != roPattern[oVecnLSP[nLoop + 1] - 1])
			oVecnLSP[nLoop + 1] = oVecnLSP[oVecnLSP[nLoop + 1] - 1] + 1;
	}

	return oVecnLSP;
}

// from https://www.ics.uci.edu/~eppstein/161/960227.html
size_t KMP(const string &roText, const string &roPattern) {
	auto oVecnLSP = GetLongestSuffixPreffixTable(roPattern);
	const auto nTextLen = roText.size();
	const auto nPatternLen = roPattern.length();

	int nPatternIndex = 0;
	for (int nTextIndex = 0; nTextIndex < nTextLen; nTextIndex++) {
		for (; ; ) {
			if (roText[nTextIndex] == roPattern[nPatternIndex]) {
				nPatternIndex++;
				if (nPatternIndex == nPatternLen) {
					// nPatternIndex = oVecnLSP[nPatternIndex];
					return nTextIndex;
				}
				break;
			} else if (nPatternIndex == 0) {
				break;
			} else {
				nPatternIndex = oVecnLSP[nPatternIndex];
			}
		}
	}

	return string::npos;
}

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		string oText;
		cin >> oText;

		int nNoQueries;
		for (cin >> nNoQueries; nNoQueries--; ) {
			string oPattern;
			cin >> oPattern;

			cout << (KMP(oText, oPattern) != string::npos ? 'y' : 'n') << endl;
		}
	}
	return 0;
}
