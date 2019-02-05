/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10102 - The path in the colored field                            */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	for (string oLine; getline(cin, oLine) ; ) {
		const int nN = stoi(oLine);

		class CPosition {
			public:
				CPosition(int nRow, int nColumn) : m_nRow(nRow), m_nColumn(nColumn) {
				}

				int DistanceTo(const CPosition &roPosition) const {
					return abs(m_nRow - roPosition.m_nRow) + abs(m_nColumn - roPosition.m_nColumn);
				}

			private:
				int m_nRow, m_nColumn;
		};

		vector<CPosition> oVecoSources, oVecoDestinations;
		for (int nLoopRow = 0; nLoopRow < nN; nLoopRow++) {
			getline(cin, oLine);
			for (int nLoopColumn = 0; nLoopColumn < nN; nLoopColumn++) {
				switch (oLine[nLoopColumn]) {
					case '1':
						oVecoSources.push_back(CPosition(nLoopRow, nLoopColumn));
						break;
					case '3':
						oVecoDestinations.push_back(CPosition(nLoopRow, nLoopColumn));
						break;
				}
			}
		}

		int nMaxDist = 0;
		for (auto oItSource = oVecoSources.cbegin(); oItSource != oVecoSources.cend(); ++oItSource) {
			int nMinDist = 2 * nN;
			for (auto oItDestination = oVecoDestinations.cbegin(); oItDestination != oVecoDestinations.cend(); ++oItDestination) {
				auto nDist = oItSource->DistanceTo(*oItDestination);
				if (nMinDist > nDist)
					nMinDist = nDist;
			}

			if (nMaxDist < nMinDist)
				nMaxDist = nMinDist;
		}

		cout << nMaxDist << endl;
	}
	return 0;
}