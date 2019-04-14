/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1056 - Degrees of Separation                                     */


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int GetIndexByName(unordered_map<string, int> &roMapNameId, const string &roName) {
	auto oIt = roMapNameId.find(roName);
	if (oIt != roMapNameId.cend())
		return oIt->second;

	int nNoNames = roMapNameId.size();
	roMapNameId[roName] = roMapNameId.size();
	return nNoNames;
}

template <typename ADJ_MATRIX_TYPE>
void WFI(ADJ_MATRIX_TYPE &roAdjMatrix, int nNoEdges) {
	for (int nK = 0; nK < nNoEdges; nK++)
		for (int nI = 0; nI < nNoEdges; nI++)
			for (int nJ = 0; nJ < nNoEdges; nJ++)
				if (roAdjMatrix[nI][nJ] > roAdjMatrix[nI][nK] + roAdjMatrix[nK][nJ])
					roAdjMatrix[nI][nJ] = roAdjMatrix[nI][nK] + roAdjMatrix[nK][nJ];
}

int main() {
	for (int nNoPeople, nNoEdges, nCaseLoop = 1; (cin >> nNoPeople >> nNoEdges), nNoPeople && nNoEdges; nCaseLoop++) {
		unordered_map<string, int> oMapNameId;
		vector<vector<int>> oVecn2AdjMatrix(nNoPeople, vector<int>(nNoPeople, nNoPeople));
		while (nNoEdges--) {
			string oName1, oName2;
			cin >> oName1 >> oName2;
			int nIndex1 = GetIndexByName(oMapNameId, oName1);
			int nIndex2 = GetIndexByName(oMapNameId, oName2);
			oVecn2AdjMatrix[nIndex1][nIndex2] = oVecn2AdjMatrix[nIndex2][nIndex1] = 1;
		}

		for (int nLoop = 0; nLoop < nNoPeople; nLoop++)
			oVecn2AdjMatrix[nLoop][nLoop] = oVecn2AdjMatrix.size();

		WFI(oVecn2AdjMatrix, nNoPeople);
		int nSol = 0;
		for (int nI = 1; nI < nNoPeople; nI++)
			nSol = max(nSol, *max_element(oVecn2AdjMatrix[nI].cbegin(), next(oVecn2AdjMatrix[nI].cbegin(), nI)));

		cout << "Network " << nCaseLoop << ": ";
		if (nSol == nNoPeople)
			cout << "DISCONNECTED" << endl;
		else
			cout << nSol << endl;

		cout << endl;
	}

	return 0;
}