/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11450 - Wedding shopping                                         */


#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void ReadArray(std::vector<T> &roVectElementsArray) {
	int nN;
	std::cin >> nN;
	roVectElementsArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roVectElementsArray.emplace_back(oElement);
	}
}

template<typename T>
void RemoveDuplicatesFromArray(std::vector<T> &roVectElementsArray) {
	sort(roVectElementsArray.begin(), roVectElementsArray.end());
	roVectElementsArray.erase(unique(roVectElementsArray.begin(), roVectElementsArray.end()), roVectElementsArray.end());
}

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		int nMoneyAvailable, nNoGarmentsAvailable;
		vector<int> oVecnCurrentPossibleMoneySpent(1, 0);
		for (cin >> nMoneyAvailable >> nNoGarmentsAvailable; nNoGarmentsAvailable--; ) {
			vector<int> oVecnGarmentsPrices, oVecnNewPossibleMoneySpent;
			ReadArray(oVecnGarmentsPrices);
			RemoveDuplicatesFromArray(oVecnGarmentsPrices);

			for (auto oItCurrentPrice = oVecnCurrentPossibleMoneySpent.cbegin(); oItCurrentPrice != oVecnCurrentPossibleMoneySpent.cend(); ++oItCurrentPrice) {
				for (auto oItCurrentGarmentPrice = oVecnGarmentsPrices.cbegin(); oItCurrentGarmentPrice != oVecnGarmentsPrices.cend(); ++oItCurrentGarmentPrice) {
					int nValue = *oItCurrentPrice + *oItCurrentGarmentPrice;
					if (nValue <= nMoneyAvailable)
						oVecnNewPossibleMoneySpent.push_back(nValue);
				}
			}

			RemoveDuplicatesFromArray(oVecnNewPossibleMoneySpent);
			oVecnCurrentPossibleMoneySpent.swap(oVecnNewPossibleMoneySpent);
		}

		if (oVecnCurrentPossibleMoneySpent.size())
			cout << *oVecnCurrentPossibleMoneySpent.crbegin() << endl;
		else
			cout << "no solution" << endl;
			
	}

	return 0;
}