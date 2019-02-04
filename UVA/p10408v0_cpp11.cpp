/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10408 - Farey sequences                                          */


#include <iostream>
#include <set>

using namespace std;

class CFraction {
	public:
		int nNumerator, nDenominator;

		bool operator < (const CFraction &roRHS) const {
			return nNumerator * roRHS.nDenominator < nDenominator * roRHS.nNumerator;
		}
};

int main() {
	int MAX = 1000;

	set<CFraction> oSet;
	for (int nDenominator = 1; nDenominator <= MAX; nDenominator++) {
		for (int nNumerator = 1; nNumerator <= nDenominator; nNumerator++) {
			CFraction oFraction{ nNumerator, nDenominator };
			oSet.insert(oFraction);
		}
	}

	for (int nN, nK; cin >> nN >> nK; ) {
		auto oIt = oSet.cbegin();
		while (true) {
			if (oIt->nDenominator <= nN && !--nK)
					break;
			++oIt;
		}

		cout << oIt->nNumerator << '/' << oIt->nDenominator << endl;
	}

	return 0;
}