/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13115 - Sudoku                                                   */


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
	int nNoTestCasesLeft;
	for (std::cin >> nNoTestCasesLeft; nNoTestCasesLeft--;) {
		int nGridSize;
		std::cin >> nGridSize;
		std::vector<std::vector<int>> arr2nGrid;
		const int nTargetValue = (1 << (nGridSize + 1)) - 2;
		const int nGridSizeSq = static_cast<int>(sqrt(nGridSize));
		std::vector<int> arrnRowMask(nGridSize, 0), arrnColumnMask(nGridSize, 0), arrnSquares(nGridSize, 0);
		//int nDiag1Mask = 0, nDiag2Mask = 0;
		for (int nLoopRow = 0; nLoopRow < nGridSize; nLoopRow++) {
			for (int nLoopColumn = 0; nLoopColumn < nGridSize; nLoopColumn++) {
				int nNumber;
				std::cin >> nNumber;
				arrnRowMask[nLoopRow] |= (1 << nNumber);
				arrnColumnMask[nLoopColumn] |= (1 << nNumber);
				arrnSquares[(nLoopRow / nGridSizeSq) * nGridSizeSq + nLoopColumn / nGridSizeSq] |= (1 << nNumber);

				//if (nLoopRow == nLoopColumn)
				//	nDiag1Mask |= (1 << nNumber);
				//else if (nLoopRow == nGridSize - nLoopColumn - 1)
				//	nDiag2Mask |= (1 << nNumber);
			}
		}

		bool bYes(
			//nDiag1Mask == nGridSize && nDiag2Mask == nGridSize &&
			std::count(arrnRowMask.cbegin(), arrnRowMask.cend(), nTargetValue) == nGridSize && 
			std::count(arrnColumnMask.cbegin(), arrnColumnMask.cend(), nTargetValue) == nGridSize &&
			std::count(arrnSquares.cbegin(), arrnSquares.cend(), nTargetValue) == nGridSize
		);
		std::cout << (bYes ? "yes\n" : "no\n");
	}

	return 0;
}