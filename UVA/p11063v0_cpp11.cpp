/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11063 - B2-Sequence                                              */


#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roVecNumbersArray) {
	roVecNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roVecNumbersArray.push_back(std::move(oElement));
	}
}

int main() {
	const int MAX_NUMBERS = 100, MAX_VALUE = 10000;

	for (int nNoNumbers, nCaseNumber = 1; cin >> nNoNumbers; nCaseNumber++) {
		vector<int> oVecNumbers;
		ReadArray(nNoNumbers, oVecNumbers);
		vector<bool> oVecbSumAlreadyPresent(MAX_VALUE * 2 + 1);
		bool bIsB2Sequence = true;

		if (oVecNumbers[0] < 1 || oVecNumbers[0] > MAX_VALUE) {
			bIsB2Sequence = false;
		} else {
			for (auto oItCurrent = next(oVecNumbers.cbegin()), oItPrev = oVecNumbers.cbegin(); oItCurrent != oVecNumbers.cend(); ++oItCurrent)
				if (*oItCurrent < 1 || *oItCurrent > MAX_VALUE || *oItCurrent < *oItPrev) {
					bIsB2Sequence = false;
					break;
				}
		}

		if (bIsB2Sequence) {
			for (auto oIt1 = oVecNumbers.cbegin(); oIt1 != oVecNumbers.cend(); ++oIt1) {
				for (auto oIt2 = oIt1; oIt2 != oVecNumbers.cend(); ++oIt2) {
					int nCurrentSum = *oIt1 + *oIt2;
					if (oVecbSumAlreadyPresent[nCurrentSum]) {
						bIsB2Sequence = false;
						break;
					}
					oVecbSumAlreadyPresent[nCurrentSum] = true;
				}
			}
		}

		cout << "Case #" << nCaseNumber << ": It is " << (bIsB2Sequence ? "" : "not ") << "a B2-Sequence." << endl << endl;
	}

	return 0;
}