/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10508 - Word Morphing                                            */


#include <iostream>
#include <iterator>
#include <string>
#include <numeric>
#include <functional>
#include <vector>

template<typename T>
void PrintCollection(const T &roCollection, const std::string &roDelim) {
	copy(
		roCollection.cbegin(), 
		roCollection.cend(), 
		std::ostream_iterator<typename T::value_type>(std::cout, roDelim.c_str())
	);
}

template<typename T>
void ReadArray(int nNoNumbers, std::vector<T> &roVecNumbersArray) {
	roVecNumbersArray.reserve(nNoNumbers);
	while (nNoNumbers--) {
		T oElement;
		std::cin >> oElement;
		roVecNumbersArray.push_back(move(oElement));
	}
}

using namespace std;

int StringDistance(const string &roLHSString, const string &roRHSString) {
	auto nNoDiffs = inner_product(
		roLHSString.cbegin(),
		roLHSString.cend(),
		roRHSString.cbegin(),
		0,
		plus<int>(),
		not_equal_to<char>()
	);

	return nNoDiffs;
}

int main() {

	for (int nNoWords, nNoLetters; cin >> nNoWords >> nNoLetters; ) {
		vector<string> oVecoStrings, oVecoStringsSorted(nNoWords);
		ReadArray(nNoWords, oVecoStrings);
		for (auto oIt = next(oVecoStrings.begin()); oIt != oVecoStrings.end(); ++oIt) {
			auto nDist = StringDistance(oVecoStrings[0], *oIt);
			oVecoStringsSorted[nDist] = move(*oIt);
		}
		oVecoStringsSorted[0] = move(oVecoStrings[0]);
		PrintCollection(oVecoStringsSorted, "\n");
	}

	return 0;
}