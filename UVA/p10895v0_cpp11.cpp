/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10895 - Matrix Transpose                                         */


#if defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))



#include <iostream>
#include <vector>
#include <map>

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

template<typename T>
void WriteArray(const std::vector<T> &roVecNumbersArray) {
	if (!roVecNumbersArray.size())
		return;

	auto oIt = roVecNumbersArray.cbegin();
	cout << *oIt;

	while (++oIt != roVecNumbersArray.cend())
		cout << ' ' << *oIt;
}

void ReadSparseRow(int nRowIndex, vector<int> &roVecnPositions, vector<int> &roVecnValues, map<int, map<int, int>> &roMap2RowColumnValue) {
	int nNoElementsInRow;
	cin >> nNoElementsInRow;
	ReadArray(nNoElementsInRow, roVecnPositions);
	ReadArray(nNoElementsInRow, roVecnValues);

	for (
		auto oItIndex = roVecnPositions.cbegin(), oItValue = roVecnValues.cbegin();
		oItIndex != roVecnPositions.cend();
		++oItIndex, ++oItValue
	) {
		roMap2RowColumnValue[*oItIndex][nRowIndex] = *oItValue;
	}
}

int main() {
	int nNoRows, nNoColumns;
	while (cin >> nNoRows >> nNoColumns) {
		map<int, map<int, int>> oMap2RowColumnValue;
		for (int nRowLoop = 1; nRowLoop <= nNoRows; nRowLoop++) {
			vector<int> oVecnPositions, oVecnValues;
			ReadSparseRow(nRowLoop, oVecnPositions, oVecnValues, oMap2RowColumnValue);
		}

		cout << nNoColumns << ' ' << nNoRows << endl;
		for (int nColumnLoop = 1; nColumnLoop <= nNoColumns; nColumnLoop++) {
			auto oIt = oMap2RowColumnValue.find(nColumnLoop);
			if (oIt == oMap2RowColumnValue.cend()) {
				cout << "0" << endl << endl;
			} else {
				vector<int> oVecnPositions, oVecnValues;

				auto nNoElements = oIt->second.size();
				cout << nNoElements << ' ';

				oVecnPositions.reserve(nNoElements);
				oVecnValues.reserve(nNoElements);

#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
				for (const auto &roPair : oIt->second) {
#else
				for (auto oItPair = oIt->second.cbegin(); oItPair != oIt->second.cend(); ++oItPair) {
					auto &roPair = *oItPair;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
					oVecnPositions.push_back(roPair.first);
					oVecnValues.push_back(roPair.second);
				}

				WriteArray(oVecnPositions); cout << endl;
				WriteArray(oVecnValues); cout << endl;
			}
		}
	}

	return 0;
}