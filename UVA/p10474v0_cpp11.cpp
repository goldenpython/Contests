/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10474 - Where is the Marble?                                     */


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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
	for (int nNoMarbles, nNoQueries, nCaseLoop = 1; (cin >> nNoMarbles >> nNoQueries), nNoMarbles && nNoQueries; nCaseLoop++) {
		vector<int> oVecMarbleNumbers;
		ReadArray(nNoMarbles, oVecMarbleNumbers);
		sort(oVecMarbleNumbers.begin(), oVecMarbleNumbers.end());

		cout << "CASE# " << nCaseLoop << ":" << endl;
		for (int nMarbleNumber; nNoQueries; nNoQueries--) {
			cin >> nMarbleNumber;

			auto oIt = lower_bound(oVecMarbleNumbers.cbegin(), oVecMarbleNumbers.cend(), nMarbleNumber);
			auto bNotFound = (oIt == oVecMarbleNumbers.cend() || *oIt != nMarbleNumber);
			if (bNotFound)
				cout << nMarbleNumber << " not found" << endl;
			else
				cout << nMarbleNumber << " found at " << distance(oVecMarbleNumbers.cbegin(), oIt) + 1 << endl;
		}
	}

	return 0;
}