/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10093 - An Easy Problem!                                         */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void FromStringToDigits(const string &roNumberAsString, vector<int> &roVecnNumberAsDigitsVector) {
	roVecnNumberAsDigitsVector.resize(roNumberAsString.size());

	transform(
		roNumberAsString.crbegin(), 
		roNumberAsString.crend(), 
		roVecnNumberAsDigitsVector.begin(), 
		[] (char cChar) -> char {
			if (isdigit(cChar))
				return cChar - '0';
			if (cChar >= 'A' && cChar <= 'Z')
				return cChar - 'A' + 10;
			if (cChar >= 'a' && cChar <= 'z')
				return cChar - 'a' + 36;

			return 0;
		}
	);
}

int FromDigitsToNumber(const vector<int> &roVecnNumberAsDigitsVector, int nBase, int nMod) {
	int nN = 0;
	for (auto oIt = roVecnNumberAsDigitsVector.cbegin(); oIt != roVecnNumberAsDigitsVector.cend(); ++oIt)
		nN = (*oIt + nN * nBase) % nMod;
	return nN;
}

int main() {
	for (string oLine; getline(cin, oLine); ) {
		vector<int> oVecnNumberAsDigits;
		FromStringToDigits(oLine, oVecnNumberAsDigits);
		int nMinBase = 1 + *max_element(oVecnNumberAsDigits.cbegin(), oVecnNumberAsDigits.cend());
		bool bFoundSol = false;
		for (int nBaseLoop = max(2, nMinBase); nBaseLoop <= 62; nBaseLoop++)
			if (!(FromDigitsToNumber(oVecnNumberAsDigits, nBaseLoop, nBaseLoop - 1))) {
				cout << nBaseLoop << endl;
				bFoundSol = true;
				break;
			}
		
		if (!bFoundSol)
			cout << "such number is impossible!" << endl;
	}

	return 0;
}