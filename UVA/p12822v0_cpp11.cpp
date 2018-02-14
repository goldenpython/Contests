/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12822 - Extraordinarily large LED                                */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ReadTime() {
	int nH, nM, nS;
	cin >> nH >> nM >> nS;
	return nS + nM * 60 + nH * 3600;
}

int ComputeScoreCost(int nScore, const vector<int> &roVecnDigitCost) {
	if (!nScore)
		return roVecnDigitCost[nScore];

	int nCost = 0;
	while (nScore) {
		nCost += roVecnDigitCost[nScore % 10];
		nScore /= 10;
	}

	return nCost;
}

int main() {
	const auto oNewTable = ctype<char>::classic_table();
	vector<ctype<char>::mask> bar(oNewTable, oNewTable + ctype<char>::table_size);

	bar[' '] |= ctype_base::space;
	bar['\t'] &= ~(ctype_base::space | ctype_base::cntrl);
	bar[':'] |= ctype_base::space;

	cin.imbue(locale(cin.getloc(), new ctype<char>(bar.data())));

	const vector<int> oVecnDigitCost = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

	int nStart;
	int nGuestScore, nHomeScore, nGuestCurrentCost, nHomeCurrentCost;
	int nTotalCost, nCurrentCase = 1;
	while (true) {
		string oCommand;
		if (!(cin >> oCommand) || oCommand.size() <= 1)
			break;

		if (oCommand == "START") {
			nTotalCost = 0;
			nGuestScore = nHomeScore = 0;
			nGuestCurrentCost = nHomeCurrentCost = oVecnDigitCost[0];

			nStart = ReadTime();
		} else if (oCommand == "SCORE") {
			int nTime = ReadTime(), nScoreAdd;
			nTotalCost += (nGuestCurrentCost + nHomeCurrentCost) * (nTime - nStart);
			nStart = nTime;

			string oTeam;
			cin >> oTeam >> nScoreAdd;

			if (oTeam == "home") {
				nHomeScore += nScoreAdd;
				nHomeCurrentCost = ComputeScoreCost(nHomeScore, oVecnDigitCost);
			} else {
				nGuestScore += nScoreAdd;
				nGuestCurrentCost = ComputeScoreCost(nGuestScore, oVecnDigitCost);
			}
		} else if (oCommand == "END") {
			int nTime = ReadTime();
			nTotalCost += (nGuestCurrentCost + nHomeCurrentCost) * (nTime - nStart);

			cout << "Case " << nCurrentCase++ << ": " << nTotalCost << endl;
		}
	}

	return 0;
}