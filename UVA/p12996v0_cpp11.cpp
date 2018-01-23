/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12996 - Ultimate Mango Challenge                                 */


#include <iostream>
#include <vector>
#include <numeric>

template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roVecNumbersArray) {
	roVecNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roVecNumbersArray.push_back(oElement);
	}
}

int main() {
	int nNoTestCases;
	std::cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		int nNoMangoTypes, nTotalMangosLimit;
		std::cin >> nNoMangoTypes >> nTotalMangosLimit;

		std::vector<int> oVecMangosQuantityPerType, oVecMangosLimitPerType;
		ReadArray(nNoMangoTypes, oVecMangosQuantityPerType);
		ReadArray(nNoMangoTypes, oVecMangosLimitPerType);

		int nTotalMangos = std::accumulate(oVecMangosQuantityPerType.cbegin(), oVecMangosQuantityPerType.cend(), 0);
		bool bCanWin = true;
		do {
			if (nTotalMangos > nTotalMangosLimit) {
				bCanWin = false;
				break;
			}

			for (
				auto oItMangoQuantity = oVecMangosQuantityPerType.cbegin(), oItMangoLimit = oVecMangosLimitPerType.cbegin();
				oItMangoQuantity != oVecMangosQuantityPerType.cend() && oItMangoLimit != oVecMangosLimitPerType.cend();
				++oItMangoQuantity, ++oItMangoLimit
			) {
				if (*oItMangoQuantity > *oItMangoLimit) {
					bCanWin = false;
					break;
				}
			}
		} while (0);

		std::cout << "Case " << nCaseLoop << ": " << (bCanWin ? "Yes" : "No") << std::endl;
	}
	return 0;
}