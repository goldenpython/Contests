/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12955 - Factorial                                                */


#include <iostream>
#include <vector>

using namespace std;

int main() {
	const int MAX = 100001;
	vector<int> oSol;
	oSol.reserve(MAX);

	vector<int> oFactorials;
	int nCurrentFact = 1;
	for (int nLoop = 1; ; nLoop++) {
		nCurrentFact *= nLoop;
		oFactorials.push_back(nCurrentFact);
		if (nCurrentFact >= MAX)
			break;
	}

	oSol.push_back(0); oSol.push_back(1);
	for (int nLoop = 2; nLoop < MAX; nLoop++) {
		int nCurrent = oSol[nLoop - 1] + 1;
		for (int nLoopFact = 1; ; nLoopFact++) {
			int nDiff = nLoop - oFactorials[nLoopFact];
			if (nDiff < 0)
				break;
			if (nCurrent > oSol[nDiff] + 1)
				nCurrent = oSol[nDiff] + 1;
		}

		oSol.push_back(nCurrent);
	}

	int nN;
	while (cin >> nN)
		cout << oSol[nN] << endl;

	return 0;
}