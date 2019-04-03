/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11239 - Open Source                                              */


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <memory>

using namespace std;

class CProject {
	public:
		CProject(string &&oProjectName) : m_oProjectName(move(oProjectName)), nNoStudents(0) {}
		void IncNoStudents() { nNoStudents++; }
		void DecNoStudents() { nNoStudents--; }

		static unordered_map<string, shared_ptr<CProject>> s_oMapStudentProject;

		bool operator > (const CProject &roRHS) const {
			if (this->nNoStudents > roRHS.nNoStudents)
				return true;
			else if (this->nNoStudents < roRHS.nNoStudents)
				return false;

			return this->m_oProjectName.compare(roRHS.m_oProjectName) < 0;
		}

	private:
		string m_oProjectName;
		int nNoStudents;

		friend ostream& operator << (ostream &roStream, const CProject &roProject);
};

unordered_map<string, shared_ptr<CProject>> CProject::s_oMapStudentProject;

ostream& operator << (ostream &roStream, const CProject &roProject) {
	roStream << roProject.m_oProjectName << ' ' << roProject.nNoStudents;
	return roStream;
}

ostream& operator << (ostream &roStream, const shared_ptr<CProject> &roProject) {
	roStream << *roProject;
	return roStream;
}

template<typename T>
void PrintCollection(const T &roCollection, const std::string &roDelim) {
	copy(roCollection.cbegin(), roCollection.cend(), std::ostream_iterator<typename T::value_type>(std::cout, roDelim.c_str()));
}

int main() {
	for (string oLine; getline(cin, oLine), oLine != "0"; ) {
		CProject::s_oMapStudentProject.clear();

		vector<shared_ptr<CProject>> oVecProjects;
		for (shared_ptr<CProject> oCurrentProject; oLine != "1"; getline(cin, oLine)) {
			if (isupper(oLine[0])) {
				oVecProjects.push_back(make_shared<CProject>(move(oLine)));
				oCurrentProject = *(oVecProjects.rbegin());
				continue;
			}
			auto oItProject = CProject::s_oMapStudentProject.find(oLine);
			if (oItProject == CProject::s_oMapStudentProject.end()) {
				oCurrentProject->IncNoStudents();
				CProject::s_oMapStudentProject.insert(make_pair(oLine, oCurrentProject));
			} else {
				if (oItProject->second == oCurrentProject)
					continue;

				if (oItProject->second) {
					oItProject->second->DecNoStudents();
					oItProject->second = nullptr;
				}
			}
		}

		sort(
			oVecProjects.begin(),
			oVecProjects.end(),
			[] (const shared_ptr<CProject> &roLHS, const shared_ptr<CProject> &roRHS) {
				return *roLHS > *roRHS;
			}
		);

		PrintCollection(oVecProjects, "\n");
	}
}