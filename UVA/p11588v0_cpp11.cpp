/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11588 - Image Coding                                             */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nNoRows, nNoColumns, nNoBytesImportant, nNoBytesUnimportant;
		cin >> nNoRows >> nNoColumns >> nNoBytesImportant >> nNoBytesUnimportant;

		string oRow;
		vector<int> oVecnFreq('Z' - 'A' + 1);
		int nMaxFreq = 0, nMaxFreqCount = 0;
		for (int nRowLoop = 0; nRowLoop < nNoRows; nRowLoop++) {
			cin >> oRow;
			for_each(
				oRow.cbegin(), 
				oRow.cend(), 
				[&oVecnFreq, &nMaxFreq, &nMaxFreqCount](char cChar) {
					cChar -= 'A';
					int nNewCharFreq = ++oVecnFreq[cChar];
					if (nNewCharFreq > nMaxFreq) {
						nMaxFreq = nNewCharFreq;
						nMaxFreqCount = 1;
					} else if (nNewCharFreq == nMaxFreq) {
						nMaxFreqCount++;
					}
				}
			);
		}

		auto nSol = nMaxFreq * nMaxFreqCount * nNoBytesImportant + (nNoRows * nNoColumns - nMaxFreq * nMaxFreqCount) * nNoBytesUnimportant;
		cout << "Case " << nCaseLoop << ": " << nSol << endl;
	}

	return 0;
}