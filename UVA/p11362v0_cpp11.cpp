/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11362 - Phone List                                               */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

template<typename T>
void ReadArray(std::vector<T> &roVectElementsArray) {
	int nN;
	std::cin >> nN;
	roVectElementsArray.reserve(nN);
	while (nN--) {
		T oElement;
		std::cin >> oElement;
		roVectElementsArray.push_back(move(oElement));
	}
}

using namespace std;

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		vector<string> oVecoNumbers;
		ReadArray(oVecoNumbers);
		sort(oVecoNumbers.begin(), oVecoNumbers.end());
		auto oIt = adjacent_find(
			oVecoNumbers.cbegin(), 
			oVecoNumbers.cend(), 
			[] (const string &roLHS, const string &roRHS) { 
				return roRHS.compare(0, roLHS.size(), roLHS) == 0;
			}
		);

		cout << ((oIt == oVecoNumbers.cend()) ? "YES" : "NO") << endl;
	}

	return 0;
}