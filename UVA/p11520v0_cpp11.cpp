/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11520 - Fill the Square                                          */


#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <iterator>

template<typename T>
void ReadArray(std::vector<T> &roVecElementsArray) {
	int nNoElements;
	std::cin >> nNoElements;
	roVecElementsArray.reserve(nNoElements);
	while (nNoElements--) {
		T oElement;
		std::cin >> oElement;
		roVecElementsArray.push_back(std::move(oElement));
	}
}

using namespace std;

inline bool PosIsValid(int nRow, int nColumn, int nNoRows, int nNoColumns) {
	return nRow >= 0 && nRow < nNoRows && nColumn >= 0 && nColumn < nNoColumns;
}

inline char GetCharAtPos(int nRow, int nColumn, int nNoRows, int nNoColumns, const vector<string> &roVecoMatrix) {
	return PosIsValid(nRow, nColumn, nNoRows, nNoColumns) ? roVecoMatrix[nRow][nColumn] : '.';
}

int main() {
	int nNoTestCases;
	cin >> nNoTestCases;
	for (int nCaseLoop = 1; nCaseLoop <= nNoTestCases; nCaseLoop++) {
		vector<string> oVecoMatrix;
		ReadArray(oVecoMatrix);


		const int nNoRows = oVecoMatrix.size(), nNoColumns = oVecoMatrix[0].size();
		auto GetCharAt = std::bind(GetCharAtPos, placeholders::_1, placeholders::_2, nNoRows, nNoColumns, cref(oVecoMatrix));
		for (int nRowLoop = 0; nRowLoop < nNoRows; nRowLoop++)
			for (int nColumnLoop = 0; nColumnLoop < nNoColumns; nColumnLoop++)
				if (oVecoMatrix[nRowLoop][nColumnLoop] == '.')
					for (char nChar = 'A'; nChar <= 'Z'; nChar++) {
						if (
							GetCharAt(nRowLoop - 1, nColumnLoop + 0) == nChar || 
							GetCharAt(nRowLoop + 1, nColumnLoop + 0) == nChar ||
							GetCharAt(nRowLoop + 0, nColumnLoop - 1) == nChar ||
							GetCharAt(nRowLoop + 0, nColumnLoop + 1) == nChar
						) {
							continue;
						}

						oVecoMatrix[nRowLoop][nColumnLoop] = nChar;
						break;
					}

		cout << "Case " << nCaseLoop << ":" << endl;
		copy(oVecoMatrix.cbegin(), oVecoMatrix.cend(), ostream_iterator<string>(cout, "\n"));
	}

	return 0;
}