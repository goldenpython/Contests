/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 454 - Anagrams                                                   */


#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class String {
	public:
		String(const string &roString) : m_oStringOrig(roString) {
			for (auto oIt = roString.begin(); oIt != roString.end(); oIt++)
				if (*oIt != ' ')
					m_oStringAna += *oIt;
			sort(m_oStringAna.begin(), m_oStringAna.end());
		}

		bool operator < (const String &roRHS) const {
//			int nComp = m_oStringAna.compare(roRHS.m_oStringAna);
//			if (!nComp)
//				return m_oStringOrig.compare(roRHS.m_oStringOrig) < 0;
//			else
//				return nComp < 0;
			return m_oStringOrig.compare(roRHS.m_oStringOrig) < 0;
		}

		static bool AreAnagrams(const String &roLHS, const String &roRHS) {
			return roLHS.m_oStringAna == roRHS.m_oStringAna;
		}

		const string &GetString() const {
			return m_oStringOrig;
		}

	private:
		string m_oStringOrig, m_oStringAna;
};


int main() {
	string oLine;
	getline(cin, oLine);
	stringstream oStringStream(oLine);
	int nNoTestCases;
	oStringStream >> nNoTestCases;
	getline(cin, oLine);

	while (nNoTestCases--) {	
		vector<String> oVecStrings;

		do {
			getline(cin, oLine);
			if (!oLine.size())
				break;

			oVecStrings.push_back(String(oLine));
		} while (true);

		sort(oVecStrings.begin(), oVecStrings.end());

		for (auto oIt1 = oVecStrings.cbegin(); oIt1 != oVecStrings.cend(); oIt1++)
			for (auto oIt2 = oIt1 + 1; oIt2 != oVecStrings.cend(); oIt2++)
				if (String::AreAnagrams(*oIt1, *oIt2))
					cout << oIt1->GetString() << " = " << oIt2->GetString() << endl;

		if (nNoTestCases >= 1)
			cout << endl;
	}

	return 0;
}
