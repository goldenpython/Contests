/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10611 - The Playboy Chimp                                        */


#include <iostream>
#include <vector>
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

using namespace std;

int main() {
	vector<int> oVecHeights;
	ReadArray(oVecHeights);

	int nNoQueries;
	for (cin >> nNoQueries; nNoQueries--; ) {
		int nCurrentHeight;
		cin >> nCurrentHeight;
		auto oItFirst = lower_bound(oVecHeights.cbegin(), oVecHeights.cend(), nCurrentHeight);
		if (oItFirst == oVecHeights.cbegin())
			cout << 'X';
		else
			cout << *(prev(oItFirst));

		cout << ' ';

		auto oItLast = upper_bound(oVecHeights.cbegin(), oVecHeights.cend(), nCurrentHeight);
		if (oItLast == oVecHeights.cend())
			cout << 'X';
		else
			cout << *oItLast;

		cout << endl;
	}

	return 0;
}