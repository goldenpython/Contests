/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10360 - Rat Attack                                               */


#include <iostream>
#include <vector>

using namespace std;

int clamp(int nValue, int nMin, int nMax) {
	if (nValue < nMin)
		nValue = nMin;
	if (nValue > nMax)
		nValue = nMax;

	return nValue;
}

int main() {
	int nNoTestCasesLeft;
	for (cin >> nNoTestCasesLeft; nNoTestCasesLeft--; ) {
		const int MAX_GRID_SIZE = 1025;
		vector<vector<int>> oVec2nMatrix(MAX_GRID_SIZE, vector<int>(MAX_GRID_SIZE));

		int nD, nNoPopulations, nSolX, nSolY, nSolMaxRats = 0;
		for (cin >> nD >> nNoPopulations; nNoPopulations--; ) {
			int nX, nY, nSize;
			cin >> nX >> nY >> nSize;

			const int nMinX = clamp(nX - nD, 0, MAX_GRID_SIZE - 1);
			const int nMaxX = clamp(nX + nD, 0, MAX_GRID_SIZE - 1);
			const int nMinY = clamp(nY - nD, 0, MAX_GRID_SIZE - 1);
			const int nMaxY = clamp(nY + nD, 0, MAX_GRID_SIZE - 1);

			for (nX = nMinX; nX <= nMaxX; nX++)
				for (nY = nMinY; nY <= nMaxY; nY++)
					if ((oVec2nMatrix[nX][nY] += nSize) > nSolMaxRats) {
						nSolMaxRats = oVec2nMatrix[nX][nY];
						nSolX = nX;
						nSolY = nY;
					}
		}

		cout << nSolX << ' ' << nSolY << ' ' << nSolMaxRats << endl;
	}

	return 0;
}
