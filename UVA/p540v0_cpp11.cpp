/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 540 - Team Queue                                                 */


#include <iostream>
#include <deque>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <string>
#if defined(_MSC_VER) && (_MSC_VER <= 1600)
#include <functional>
#endif // defined(_MSC_VER) && (_MSC_VER <= 1600)

using namespace std;

class TeamQueueSimulator {
	public:
#if defined(_MSC_VER) && (_MSC_VER <= 1600)
		TeamQueueSimulator() : m_oMapMemberToTeam(), m_oTeamsQueue(), m_oTeamInTeamQueueSet(8, s_oHasher) { }
#endif // defined(_MSC_VER) && (_MSC_VER <= 1600)
		bool Read();
		void Enqueue(int nTeamMember);
		int Dequeue();

	private:
		typedef deque<int> TEAM_QUEUE_TYPE;
		typedef shared_ptr<TEAM_QUEUE_TYPE> TEAM_QUEUE_REF_TYPE;
		typedef unordered_map<int, TEAM_QUEUE_REF_TYPE> MEMBER_TO_TEAM_REF_MAP_TYPE;
		typedef deque<TEAM_QUEUE_REF_TYPE> TEAMS_QUEUE_TYPE;

#if defined(_MSC_VER) && (_MSC_VER <= 1600)
		typedef function<size_t(const TEAM_QUEUE_REF_TYPE &)> UNORDERED_SET_HASH_TYPE;
		static UNORDERED_SET_HASH_TYPE s_oHasher;
#endif // defined(_MSC_VER) && (_MSC_VER <= 1600)

		typedef unordered_set<		TEAM_QUEUE_REF_TYPE
#if defined(_MSC_VER) && (_MSC_VER <= 1600)
									,
									decltype(s_oHasher)
#endif // defined(_MSC_VER) && (_MSC_VER <= 1600)
		> TEAM_IN_TEAMS_QUEUE_SET_TYPE;

		MEMBER_TO_TEAM_REF_MAP_TYPE m_oMapMemberToTeam;
		TEAMS_QUEUE_TYPE m_oTeamsQueue;
		TEAM_IN_TEAMS_QUEUE_SET_TYPE m_oTeamInTeamQueueSet;
};

#if defined(_MSC_VER) && (_MSC_VER <= 1600)
	TeamQueueSimulator::UNORDERED_SET_HASH_TYPE TeamQueueSimulator::s_oHasher = [](const TEAM_QUEUE_REF_TYPE& roQ) { return (size_t)(roQ.get()); };
#endif // defined(_MSC_VER) && (_MSC_VER <= 1600)

bool TeamQueueSimulator::Read() {
	int nNoTeams;
	cin >> nNoTeams;
	if (!nNoTeams)
		return false;

	for (int nTeamLoop = 0; nTeamLoop < nNoTeams; nTeamLoop++) {
		auto oTeamQueueRef = make_shared<TEAM_QUEUE_TYPE>();

		int nTeamSize;
		cin >> nTeamSize;
		while (nTeamSize--) {
			int nTeamMember;
			cin >> nTeamMember;
			m_oMapMemberToTeam.insert(make_pair(nTeamMember, oTeamQueueRef));
		}
	}

	return true;
}

void TeamQueueSimulator::Enqueue(int nTeamMember) {
	auto oTeamQueueRefIt = m_oMapMemberToTeam.find(nTeamMember);
	if (oTeamQueueRefIt == m_oMapMemberToTeam.end())
		return;

	auto oTeamQueueRef = oTeamQueueRefIt->second;
	oTeamQueueRef->push_back(nTeamMember);
	if (oTeamQueueRef->size() == 1) {
		m_oTeamsQueue.push_back(oTeamQueueRef);
		m_oTeamInTeamQueueSet.insert(oTeamQueueRef);
	}
}

int TeamQueueSimulator::Dequeue() {
	auto oTeamQueueRef = m_oTeamsQueue.front();

	int nTeamMember = oTeamQueueRef->front();
	oTeamQueueRef->pop_front();

	if (!oTeamQueueRef->size()) {
		m_oTeamsQueue.pop_front();
		m_oTeamInTeamQueueSet.erase(oTeamQueueRef);
	}

	return nTeamMember;
}

int main() {

	for (int nCaseLoop = 1; ; nCaseLoop++) {
		TeamQueueSimulator oTeamQueueSimulator;
		if (!oTeamQueueSimulator.Read())
			break;

		cout << "Scenario #" << nCaseLoop << endl;
		while (true) {
			std::string oCommand;
			cin >> oCommand;
			if (oCommand[0] == 'E') {
				int nTeamMember;
				cin >> nTeamMember;
				oTeamQueueSimulator.Enqueue(nTeamMember);
			} else if (oCommand[0] == 'D') {
				cout << oTeamQueueSimulator.Dequeue() << endl;
			} else {
				break;
			}
		}

		cout << endl;
	}

	return 0;
}