/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 1241 - Jollybee Tournament                                       */


#include <iostream>
#include <vector>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nN, nM;
		cin >> nN >> nM;
		vector<bool> oVecbPlayerPresent(1 << nN, true);
		while (nM--) {
			int nPlayerPos;
			cin >> nPlayerPos;
			oVecbPlayerPresent[nPlayerPos - 1] = false;
		}

		int nSol = 0;
		for (; nN; nN--) {
			auto oItEnd = next(oVecbPlayerPresent.cbegin(), 1 << nN);
			auto oItCurrentNextPhase = oVecbPlayerPresent.begin();
			for (auto oItCurrent = oVecbPlayerPresent.cbegin(); oItCurrent != oItEnd; ) {
				auto bFirst = *oItCurrent;
				auto bSecond = *++oItCurrent;
				++oItCurrent;
				*oItCurrentNextPhase++ = bFirst | bSecond;
				if (bFirst ^ bSecond)
					nSol++;
			}
		}

		cout << nSol << endl;
	}

	return 0;
}