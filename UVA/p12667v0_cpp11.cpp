/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12667 - Last Blood                                               */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CProblemStatus {
	public:
		CProblemStatus() : m_nTime(-1), m_nBitmapSolvers(0) { }

		void SetTime(int nTime) { m_nTime = nTime; };
		int GetTime() const  { return m_nTime; };

		void SetTeamID(int nTeamID) { m_nTeamID = nTeamID; };
		int GetTeamID() const  { return m_nTeamID; };

		bool TeamHasSolvedProblem(int nTeamID) const { return (m_nBitmapSolvers & (1 << nTeamID)) != 0; }
		void SetTeamHasSolvedProblem(int nTeamID) { m_nBitmapSolvers |= (1 << nTeamID); }
	private:
		int m_nTime, m_nTeamID, m_nBitmapSolvers;
};

int main() {
	int nNoProblems, nNoTeams, nNoSubmissions;
	cin >> nNoProblems >> nNoTeams >> nNoSubmissions;

	vector<CProblemStatus> oVecProblemStatuses(nNoProblems);

	while (nNoSubmissions--) {
		int nTime, nTeamID;
		char cProblemID;
		string oStatus;

		cin >> nTime >> nTeamID >> cProblemID >> oStatus;
		if (oStatus == "Yes") {
			unsigned int nProblemID = cProblemID - 'A';
			if (oVecProblemStatuses[nProblemID].GetTime() <= nTime && !oVecProblemStatuses[nProblemID].TeamHasSolvedProblem(nTeamID)) {
				oVecProblemStatuses[nProblemID].SetTime(nTime);
				oVecProblemStatuses[nProblemID].SetTeamID(nTeamID);
			}
			oVecProblemStatuses[nProblemID].SetTeamHasSolvedProblem(nTeamID);
		}
	}

	for (auto oItProblem = oVecProblemStatuses.cbegin(); oItProblem != oVecProblemStatuses.cend(); ++oItProblem) {
		cout << static_cast<char>('A' + (oItProblem - oVecProblemStatuses.cbegin())) << " ";
		if (oItProblem->GetTime() >= 0)
			cout << oItProblem->GetTime() << " " << oItProblem->GetTeamID() << endl;
		else
			cout << "- -" << endl;
	}

	return 0;
}