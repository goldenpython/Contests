/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10264 - The Most Potent Corner                                   */



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int nN;
	while (cin >> nN) {
		const int nNoEdges = 1 << nN;
		vector<int> oVecEdgeValues(nNoEdges), oVecEdgeSums(nNoEdges);

		for (int nEdgeLoop = 0; nEdgeLoop < nNoEdges; nEdgeLoop++) {
			int nValue;
			cin >> nValue;
			oVecEdgeValues[nEdgeLoop] = nValue;
		}

		for (int nEdgeLoop = 0; nEdgeLoop < nNoEdges; nEdgeLoop++)
			for (int nBitLoop = 0; nBitLoop < nN; nBitLoop++)
				oVecEdgeSums[nEdgeLoop] += oVecEdgeValues[nEdgeLoop ^ (1 << nBitLoop)];

		int nSol = 0;
		for (int nEdgeLoop = 0; nEdgeLoop < nNoEdges; nEdgeLoop++)
			for (int nBitLoop = 0; nBitLoop < nN; nBitLoop++) {
				int nSum = oVecEdgeSums[nEdgeLoop] + oVecEdgeSums[nEdgeLoop ^ (1 << nBitLoop)];
				if (nSol < nSum)
					nSol = nSum;
			}

		cout << nSol << endl;
	}
	return 0;
}