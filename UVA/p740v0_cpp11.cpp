/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 740 - Baudot Data Communication Code                             */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	enum SHIFT_STATE {
		DOWN = 0,
		UP = 1
	};
	const int SHIFT_DOWN = 27;
	const int SHIFT_UP = 31;
	vector<string> oStringShiftUpDownCharacters(2);

	getline(cin, oStringShiftUpDownCharacters[SHIFT_STATE::DOWN]);
	getline(cin, oStringShiftUpDownCharacters[SHIFT_STATE::UP]);

	for (string oLine; getline(cin, oLine); ) {
		string oResult;
		SHIFT_STATE nShiftState = SHIFT_STATE::DOWN;
		for (auto oItChar = oLine.cbegin(); oItChar != oLine.cend(); oItChar += 5) {
			auto nTableIndex = ((*oItChar - '0') << 4);
			nTableIndex |= ((*(oItChar + 1) - '0') << 3);
			nTableIndex |= ((*(oItChar + 2) - '0') << 2);
			nTableIndex |= ((*(oItChar + 3) - '0') << 1);
			nTableIndex |= ((*(oItChar + 4) - '0') << 0);
			switch (nTableIndex) {
				case SHIFT_DOWN:
					nShiftState = SHIFT_STATE::DOWN;
					break;
				case SHIFT_UP:
					nShiftState = SHIFT_STATE::UP;
					break;
				default:
					oResult.push_back(oStringShiftUpDownCharacters[nShiftState][nTableIndex]);
			}
		}

		cout << oResult << endl;
	}

	return 0;
}