/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10905 - Children's Game                                          */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

template<typename T>
void ReadArray(std::vector<T> &roVectElementsArray) {
	int nN;
	std::cin >> nN;
	roVectElementsArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roVectElementsArray.push_back(std::move(oElement);
	}
}

using namespace std;

int main() {
	while(true) {
		vector<string> oVecoNumbers;
		ReadArray(oVecoNumbers);
		if (!oVecoNumbers.size())
			break;

		sort(
			oVecoNumbers.begin(),
			oVecoNumbers.end(),
			[] (const string &roLHS, const string &roRHS) -> bool {
				auto nMaxSize = roLHS.size() + roRHS.size();
				for (auto oItLHS = roLHS.cbegin(), oItRHS = roRHS.cbegin(); nMaxSize--; ++oItLHS, ++oItRHS) {
					if (oItLHS == roLHS.cend())
						oItLHS = roRHS.cbegin();
					if (oItRHS == roRHS.cend())
						oItRHS = roLHS.cbegin();

					const auto nDiff = *oItLHS - *oItRHS;
					if (!nDiff)
						continue;
					
					return nDiff > 0;
				}

				return false;
			}
		);

		cout << accumulate(oVecoNumbers.cbegin(), oVecoNumbers.cend(), string()) << endl;;
	}
	return 0;
}