/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13070 - Palm trees in the snow                                   */


#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int nNoCasesLeft;
	cin >> nNoCasesLeft;
	while (nNoCasesLeft--) {
		int nMaxWight, nNoTress;
		cin >> nMaxWight >> nNoTress;
		vector<int> oVecIndicesNotFallenTrees;
		oVecIndicesNotFallenTrees.push_back(0);
		for (int nLoop = 1; nLoop <= nNoTress; nLoop++) {
			int nWeight;
			cin >> nWeight;
			if (nWeight >= nMaxWight)
				oVecIndicesNotFallenTrees.push_back(nLoop);
		}


		do {
			oVecIndicesNotFallenTrees.push_back(nNoTress + 1);
		} while (oVecIndicesNotFallenTrees.size() < 7);

		transform(oVecIndicesNotFallenTrees.cbegin() + 6, oVecIndicesNotFallenTrees.cend(), oVecIndicesNotFallenTrees.cbegin(), oVecIndicesNotFallenTrees.begin(), [](int nLHS, int nRHS) { return nLHS - nRHS; });
		cout << *max_element(oVecIndicesNotFallenTrees.cbegin(), oVecIndicesNotFallenTrees.cend() - 6) - 1 << endl;
	}

	return 0;
}