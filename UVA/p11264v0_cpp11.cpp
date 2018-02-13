/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11264 - Coin Collector                                           */


#include <vector>
#include <iostream>
#include <algorithm>

template<typename T>
void ReadArray(std::vector<T> &roNumbersArray) {
	int nN;
	std::cin >> nN;
	roNumbersArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roNumbersArray.push_back(oElement);
	}
}

int main() {
	int nNoTestCasesLeft;
	std::cin >> nNoTestCasesLeft;
	while (nNoTestCasesLeft--) {
		std::vector<int> oVecCoinValues;
		ReadArray(oVecCoinValues);

		int nSol = 2;

		do {
			if (oVecCoinValues.size() <= 2) {
				nSol = oVecCoinValues.size();
				break;
			}

			int nSum = 1;
			for (auto oItPrev = oVecCoinValues.cbegin() + 1, oIt = oItPrev + 1; oIt != oVecCoinValues.cend(); ++oIt, ++oItPrev)
				if (*oItPrev + nSum < *oIt) {
					nSum += *oItPrev;
					nSol++;
				}
		} while (0);

		std::cout << nSol << std::endl;
	}

	return 0;
}