/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10020 - Minimal coverage                                         */


#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int nNoTestCases;
	for (cin >> nNoTestCases; nNoTestCases--; ) {
		int nM;
		cin >> nM;

		struct SEGMENT {
			int nLeft, nRight;
			SEGMENT(int nLeft, int nRight) : nLeft(nLeft), nRight(nRight) {}
		};

		vector<int> a;
		vector<SEGMENT> oVecSegments;

		while (true) {
			int nLeft, nRight;
			cin >> nLeft >> nRight;
			if (!nLeft && !nRight)
				break;
			if (nRight < 0 || nLeft > nM)
				continue;

			oVecSegments.push_back(SEGMENT(nLeft, nRight));
		}

		sort(
			oVecSegments.begin(), 
			oVecSegments.end(), 
			[] (const SEGMENT &roLHS, const SEGMENT &roRHS) { return roLHS.nLeft < roRHS.nLeft; }
		);

		int nStart = 0;
		vector<SEGMENT> oVecSol;
		if (oVecSegments.size()) {
			auto oIt = oVecSegments.cbegin(), oItMaxRight = oVecSegments.cbegin();
			while (true) {
				bool bEnd = (oIt == oVecSegments.cend());
				bool bFoundSol = (oItMaxRight->nRight >= nM);

				if (bEnd || bFoundSol || oIt->nLeft > nStart) {
					if (oItMaxRight->nLeft > nStart)
						break;

					oVecSol.push_back(*oItMaxRight);
					nStart = oItMaxRight->nRight;

					if (bEnd || bFoundSol)
						break;
				}

				if (oIt->nLeft <= nStart && oIt->nRight > oItMaxRight->nRight)
					oItMaxRight = oIt;

				++oIt;
			}
		}

		if (nStart >= nM) {
			cout << oVecSol.size() << endl;
			for_each(oVecSol.cbegin(), oVecSol.cend(), [] (const SEGMENT &roSegment) { cout << roSegment.nLeft << " " << roSegment.nRight << endl; });
		} else {
			cout << 0 << endl;
		}

		cout << endl;
	}

	return 0;
}