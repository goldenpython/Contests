/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1636 - Headshot                                                  */


#include <iostream>
#include <string>

using namespace std;

int main() {
	for (string oLine; getline(cin, oLine); ) {
		auto cLastChar = '\0', cFirstChar = '\0';
		auto nNoCurrentZeroNextZero = 0, nNoZeroes = 0;
		for (auto cCurrent : oLine) {
			if (!cFirstChar)
				cFirstChar = cCurrent;
			if (cCurrent == '0') {
				nNoZeroes++;
				if (cLastChar == '0')
					nNoCurrentZeroNextZero++;
			}
			cLastChar = cCurrent;
		}

		if (cFirstChar == '0' && cLastChar == '0')
			nNoCurrentZeroNextZero++;

		auto nDiff = nNoZeroes * nNoZeroes - nNoCurrentZeroNextZero * static_cast<int>(oLine.size());
		if (nDiff > 0)
			cout << "ROTATE" << endl;
		else if (nDiff == 0)
			cout << "EQUAL" << endl;
		else
			cout << "SHOOT" << endl;

	}
	
	return 0;
}