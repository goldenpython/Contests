/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10249 - The Grand Dinner                                         */


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	for (int nNoTeams, nNoTables; (cin >> nNoTeams >> nNoTables), nNoTeams && nNoTables; ) {
		struct TEAM {
			int nTeamIndex, nTeamMembers;
			TEAM(int nTeamIndex, int nTeamMembers) : nTeamIndex(nTeamIndex), nTeamMembers(nTeamMembers) {}
		};

		bool bHasSol = true;
		int nTotalTeamMembers = 0;
		vector<TEAM> oVecTeams;
		for (int nTeamLoop = 0; nTeamLoop < nNoTeams; nTeamLoop++) {
			int nNoTeamMembers;
			cin >> nNoTeamMembers;
			if (nNoTeamMembers > nNoTables)
				bHasSol = false;
			nTotalTeamMembers += nNoTeamMembers;
			oVecTeams.push_back(TEAM(nTeamLoop, nNoTeamMembers));
		}

		int nTotalSeats = 0;
		vector<int> oVecTableSize;
		for (int nTableLoop = 0; nTableLoop < nNoTables; nTableLoop++) {
			int nNoSeatsAtTable;
			cin >> nNoSeatsAtTable;
			nTotalSeats += nNoSeatsAtTable;
			oVecTableSize.push_back(nNoSeatsAtTable);
		}

		if (nTotalSeats < nTotalTeamMembers)
			bHasSol = false;

		if (!bHasSol) {
			cout << "0" << endl;
			continue;
		} 
		sort(oVecTeams.begin(), oVecTeams.end(), [] (const TEAM &roLHS, const TEAM &roRHS) { return roLHS.nTeamMembers > roRHS.nTeamMembers; } );
		vector<set<int>> oVec2TeamMemberTableArrangement(nNoTeams, set<int>());
		auto oItTeamArrangement = oVec2TeamMemberTableArrangement.begin();
		int nTableIndex = 0;
		for (auto oItTeam = oVecTeams.cbegin(); oItTeam < oVecTeams.cend() && bHasSol; ++oItTeam) {
			oItTeamArrangement = oVec2TeamMemberTableArrangement.begin() + oItTeam->nTeamIndex;
			for (int nTeamLoop = oItTeam->nTeamMembers; nTeamLoop; nTeamLoop--) {
				if (oItTeamArrangement->find(nTableIndex) != oItTeamArrangement->end()) {
					bHasSol = false;
					break;
				}
				oItTeamArrangement->insert(nTableIndex);
				oVecTableSize[nTableIndex]--;

				if (!--nTotalTeamMembers)
					break;

				do {
					nTableIndex = (nTableIndex + 1) % nNoTables;
				} while (!oVecTableSize[nTableIndex]);
			}
		}

		if (!bHasSol) {
			cout << "0" << endl;
			continue;
		}
			
		cout << "1" << endl;
		for (oItTeamArrangement = oVec2TeamMemberTableArrangement.begin(); oItTeamArrangement != oVec2TeamMemberTableArrangement.end(); ++oItTeamArrangement) {
			auto &roVecTeamArrangement = *oItTeamArrangement;
			cout << *roVecTeamArrangement.cbegin() + 1;
			for_each(next(roVecTeamArrangement.cbegin()) , roVecTeamArrangement.cend(), [] (const int nTableIndex) { cout << " " << nTableIndex + 1; });
			cout << endl;
		}
	}
	
	return 0;
}