/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10855 - Rotated square                                           */


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
void ReadArray(int nNoElements, std::vector<T> &roVecElementsArray) {
	roVecElementsArray.reserve(nNoElements);
	while (nNoElements--) {
		T oElement;
		std::cin >> oElement;
		roVecElementsArray.emplace_back(oElement);
	}
}

bool IsSubSubsquareAtPos(int nRow, int nColumn, const vector<string> &roVecoBigSquare, const vector<string> &roVecoSmallSquare) {
	for (
		auto oItRowSmallSquare = roVecoSmallSquare.cbegin() + 0, oItRowBigSquare = roVecoBigSquare.cbegin() + nRow;
		oItRowSmallSquare != roVecoSmallSquare.cend();
		++oItRowBigSquare, ++oItRowSmallSquare
	) {
		if (!equal(oItRowSmallSquare->cbegin(), oItRowSmallSquare->cend(), oItRowBigSquare->cbegin() + nColumn))
			return false;
	}

	return true;
}

int GetNumSubsqares(const vector<string> &roVecoBigSquare, const vector<string> &roVecoSmallSquare) {
	int nNoSubsqares = 0;

	int nLimit = roVecoBigSquare.size() - roVecoSmallSquare.size();
	for (int nRow = 0; nRow <= nLimit; nRow++)
		for (int nColumn = 0; nColumn <= nLimit; nColumn++) 
			if (IsSubSubsquareAtPos(nRow, nColumn, roVecoBigSquare, roVecoSmallSquare))
				nNoSubsqares++;

	return nNoSubsqares;
}

vector<string> RotateClockwise(vector<string> &roVecoSmallSquare) {
	vector<string> oVecoRotatedSquare(roVecoSmallSquare);
	int nSize = roVecoSmallSquare.size();
	for (int nRow = 0; nRow < nSize; nRow++)
		for (int nColumn = 0; nColumn < nSize; nColumn++)
			oVecoRotatedSquare[nRow][nColumn] = roVecoSmallSquare[nSize - nColumn - 1][nRow];

	return oVecoRotatedSquare;
}

int main() {
	for (int nSizeBig, nSizeSmall; (cin >> nSizeBig>> nSizeSmall), nSizeBig && nSizeSmall; ) {
		vector<string> oVecoBigSquare, oVecoSmallSquare;
		ReadArray(nSizeBig, oVecoBigSquare);
		ReadArray(nSizeSmall, oVecoSmallSquare);

		for (int nLoop = 0; nLoop < 4; nLoop++) {
			cout << (nLoop > 0 ? " " : "") << GetNumSubsqares(oVecoBigSquare, oVecoSmallSquare);
			oVecoSmallSquare = RotateClockwise(oVecoSmallSquare);
		}

		cout << endl;
	}

	return 0;
}