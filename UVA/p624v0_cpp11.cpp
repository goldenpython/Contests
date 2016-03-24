/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 624 - CD                                                         */


#include <iostream>
#include <vector>

using namespace std;

int g_nN;
vector<int> g_oVectorTrackLengths;

int g_nBestSol;
vector<bool> g_oVectorCurrentSol, g_oVectorBestSol;

void bk(int nFromTrackIndex, int nCurrentSum) {
	if (nCurrentSum > g_nBestSol) {
		g_nBestSol = nCurrentSum;
		g_oVectorBestSol = g_oVectorCurrentSol;
	}

	if (nCurrentSum == g_nN)
		return;

	for (auto oTrackLengthIterator = g_oVectorTrackLengths.cbegin() + nFromTrackIndex; oTrackLengthIterator < g_oVectorTrackLengths.cend(); oTrackLengthIterator++) {
		if (nCurrentSum + *oTrackLengthIterator <= g_nN) {
			int nIndex = static_cast<int>(oTrackLengthIterator - g_oVectorTrackLengths.cbegin());
			g_oVectorCurrentSol[nIndex] = true;
			bk(nIndex + 1, nCurrentSum + *oTrackLengthIterator);
			g_oVectorCurrentSol[nIndex] = false;
		}
	}
}

int main() {
	while (cin >> g_nN) {
		int nNoTracks;
		cin >> nNoTracks;
		g_oVectorTrackLengths.clear();
		g_oVectorTrackLengths.reserve(nNoTracks);
		g_oVectorCurrentSol.clear();
		for (int nLoopTrack = 0; nLoopTrack < nNoTracks; nLoopTrack++) {
			int nTrackLength;
			cin >> nTrackLength;
			g_oVectorTrackLengths.push_back(nTrackLength);
			g_oVectorCurrentSol.push_back(false);
		}

		g_nBestSol = -1;
		bk(0, 0);
		for (auto oIt = g_oVectorBestSol.cbegin(); oIt < g_oVectorBestSol.cend(); oIt++)
			if (*oIt)
				cout << g_oVectorTrackLengths[oIt - g_oVectorBestSol.cbegin()] << " ";
		cout << "sum:" << g_nBestSol << endl;
	}
	return 0;
}