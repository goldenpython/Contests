/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10258 - Contest Scoreboard                                       */


#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class CContestantProblemStatus {
	public:
		CContestantProblemStatus() : m_nNoIncorrectSubmissions(0), m_nCorrectSubmissionTime(0) {}

		int GetProblemPenalty() const { 
			return ProblemSolved() ? m_nCorrectSubmissionTime + 20 * m_nNoIncorrectSubmissions : 0;
		}

		bool ProblemSolved() const { return m_nCorrectSubmissionTime != 0; }

		void SetCorrectSubmissionTime(int nCorrectSubmissionTime) { m_nCorrectSubmissionTime = nCorrectSubmissionTime;  }

		void IncrementNoIncorrectSubmissions() { m_nNoIncorrectSubmissions++; }

	private:
		int m_nNoIncorrectSubmissions, m_nCorrectSubmissionTime;
};

struct ContestantStats {
	int m_nContestantId, m_nNoProblemsSolved, m_nTotalPenalty;
};

template <typename MAP_TYPE>
class CContestant {
public:
	void ReactToSubmission(int nProblemId, int nTime, const string &roSubmissionType) {
		bool bCorrectSubmission = roSubmissionType == "C";
		bool bIncorrectSubmission = roSubmissionType == "I";

		if (!bCorrectSubmission && !bIncorrectSubmission)
			return;

		auto &roProblemStatus = m_oMap[nProblemId];
		if (bCorrectSubmission)
			if (roProblemStatus.ProblemSolved())
				return;
			else
				roProblemStatus.SetCorrectSubmissionTime(nTime);
		else
			if (roProblemStatus.ProblemSolved())
				return;
			else
				roProblemStatus.IncrementNoIncorrectSubmissions();
	}

	ContestantStats GetContestantStats() const {
		ContestantStats oStats = { 0 };
		for (auto oIt = m_oMap.cbegin(); oIt != m_oMap.cend(); ++oIt) {
			if (oIt->second.ProblemSolved()) {
				oStats.m_nNoProblemsSolved++;
				oStats.m_nTotalPenalty += oIt->second.GetProblemPenalty();
			}
		}

		return oStats;
	}

	private:
		MAP_TYPE m_oMap;
};

int main() {
	string oLine;
	getline(cin, oLine);
	int nNoTestCasesLeft = stoi(oLine);
	getline(cin, oLine);
	while (nNoTestCasesLeft--) {
		map<int, CContestant<map<int, CContestantProblemStatus>>> oMapContestants;
		while (getline(cin, oLine) && oLine.size()) {
			stringstream oStringStream(oLine);
			int nContestantId, nProblemId, nTime;
			oStringStream >> nContestantId >> nProblemId >> nTime;
			string oSubmissionType;
			oStringStream >> oSubmissionType;

			oMapContestants[nContestantId].ReactToSubmission(nProblemId, nTime, oSubmissionType);
		}

		vector<ContestantStats> oVecoContestantStats;
		for (auto oIt = oMapContestants.cbegin(); oIt != oMapContestants.cend(); ++oIt) {
			ContestantStats oStats = oIt->second.GetContestantStats();
			oStats.m_nContestantId = oIt->first;
			oVecoContestantStats.push_back(oStats);
		}

		sort(
			oVecoContestantStats.begin(), 
			oVecoContestantStats.end(), 
			[] (ContestantStats &roLHS, ContestantStats &roRHS) {
			return	roLHS.m_nNoProblemsSolved > roRHS.m_nNoProblemsSolved ||
					(
					roLHS.m_nNoProblemsSolved == roRHS.m_nNoProblemsSolved &&
					roLHS.m_nTotalPenalty < roRHS.m_nTotalPenalty
					);
			}
		);

		for (auto oIt = oVecoContestantStats.cbegin(); oIt != oVecoContestantStats.cend(); ++oIt)
			cout << oIt->m_nContestantId << ' ' << oIt->m_nNoProblemsSolved << ' ' << oIt->m_nTotalPenalty << endl;

		if (nNoTestCasesLeft > 0)
			cout << endl;
	}

	return 0;
}