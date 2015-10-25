/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 556 - Amazing                                                    */


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

	typedef struct DELTA_POS {
		DELTA_POS(int nDeltaRow, int nDeltaColumn) : nDeltaRow(nDeltaRow), nDeltaColumn(nDeltaColumn) {}
		int nDeltaRow, nDeltaColumn;
	} DELTA_POS_TYPE;

	vector<DELTA_POS_TYPE> oVecDeltas;
	oVecDeltas.push_back(DELTA_POS(+0, +1));
	oVecDeltas.push_back(DELTA_POS(-1, +0));
	oVecDeltas.push_back(DELTA_POS(+0, -1));
	oVecDeltas.push_back(DELTA_POS(+1, +0));

	while (true) {
		string oLine;
		getline(cin, oLine);
		stringstream oStringStream(oLine);
		int nR, nC;
		oStringStream >> nR >> nC;
		if (!nR && !nC)
			break;

		vector<string> oVecMap;

		oVecMap.push_back("");
		for (int nLoopRow = 0; nLoopRow < nR; nLoopRow++) {
			getline(cin, oLine);
			replace(oLine.begin(), oLine.end(), '1', 'x');
			oLine = 'x' + oLine + 'x';
			oVecMap.push_back(oLine);
		}
		oVecMap.push_back("");
		for (int nLoopColumn = 0; nLoopColumn <= nC + 1; nLoopColumn++) {
			oVecMap[0] = oVecMap[0] + 'x';
			oVecMap[nR + 1] = oVecMap[nR + 1] + 'x';
		}

		int nCurrentRow = nR, nCurrentCol = 1, nCurrentDir = 0;
//		oVecMap[nCurrentRow][nCurrentCol]++;
		do {
			int nDirNorm = (oVecDeltas.size() + nCurrentDir - 1) % oVecDeltas.size();
			int nRowRight = nCurrentRow + oVecDeltas[nDirNorm].nDeltaRow, nColumnRight = nCurrentCol + oVecDeltas[nDirNorm].nDeltaColumn;
			int nNewRow, nNewColumn, nNewDir = nCurrentDir;
			if (oVecMap[nRowRight][nColumnRight] != 'x') {
				nNewRow = nCurrentRow + oVecDeltas[nDirNorm].nDeltaRow;
				nNewColumn = nCurrentCol + oVecDeltas[nDirNorm].nDeltaColumn;
				nNewDir = nDirNorm;
			} else {
				do {
					nNewRow = nCurrentRow + oVecDeltas[nNewDir].nDeltaRow;
					nNewColumn = nCurrentCol + oVecDeltas[nNewDir].nDeltaColumn;
					if (oVecMap[nNewRow][nNewColumn] == 'x')
						nNewDir = (nNewDir + 1) % oVecDeltas.size();
					else
						break;
				} while (true);
			}

			oVecMap[nNewRow][nNewColumn]++;
			nCurrentRow = nNewRow; nCurrentCol = nNewColumn; nCurrentDir = nNewDir;
		} while (nCurrentRow != nR || nCurrentCol != 1);

		vector<int> oVecSol(5);
		for (int nLoopRow = 1; nLoopRow <= nR; nLoopRow++)
			for (int nLoopColumn = 1; nLoopColumn <= nC; nLoopColumn++)
				if (oVecMap[nLoopRow][nLoopColumn] != 'x')
					oVecSol[oVecMap[nLoopRow][nLoopColumn] - '0']++;

		cout << setw(3) << oVecSol[0] << setw(3) << oVecSol[1] << setw(3) << oVecSol[2] << setw(3) << oVecSol[3] << setw(3) << oVecSol[4] << endl;
	}

	return 0;
}