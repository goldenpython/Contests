/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13107 - Royale With Cheese                                       */


#include <string>
#include <iostream>
#include <vector>

using namespace std;

int DigitToDigit(int nDigit) {
	switch (nDigit) {
		case 2:
			return 5;
		case 5:
			return 2;
		case 6:
			return 9;
		case 9:
			return 6;
		default:
			return nDigit;
	}
}

int NumberToNumber(int nNumber) {
	return DigitToDigit(nNumber / 10) * 10 + DigitToDigit(nNumber % 10);
}

int main() {
	string oLine;
	while (getline(cin, oLine)) {
		vector<int> oVecnCharMap(256, 0);
		int nUniqueChars = 0;

		for (auto oIt = oLine.cbegin(); oIt != oLine.cend(); oIt++) {
			if (!oVecnCharMap[*oIt])
				oVecnCharMap[*oIt] = NumberToNumber(++nUniqueChars);
			cout << oVecnCharMap[*oIt];
		}
		cout << endl;
	}

	return 0;
}