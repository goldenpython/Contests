/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 642 - Word Amalgamation                                          */





#if defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))
	#define COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
#endif // defined(ONLINE_JUDGE) || (!defined(_MSC_VER) || (_MSC_VER > 1600))





#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class AnagramDict {
	public:
		void Read() {
			string oLine;
			while (getline(cin, oLine), oLine[0] != 'X') {
				string oSorted(oLine);
				sort(oSorted.begin(), oSorted.end());
				m_oMap[oSorted].push_back(move(oLine));
			}

#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
			for (auto &roIt : m_oMap) {
#else
			for (auto roItMap = m_oMap.begin(); roItMap != m_oMap.end(); ++roItMap) {
				auto &roIt = *roItMap;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
				auto &roVec = roIt.second;
				sort(roVec.begin(), roVec.end());
			}
		}

		vector<string>& GetAnagramGroup(const string &roString) {
			return m_oMap[roString];
		}
	private:
		unordered_map<string, vector<string>> m_oMap;
};

int main() {
	AnagramDict oDict;
	oDict.Read();

	for (string oLine; getline(cin, oLine), oLine[0] != 'X'; ) {
		string oSorted(oLine);
		sort(oSorted.begin(), oSorted.end());

		auto &roVec = oDict.GetAnagramGroup(oSorted);
		if (roVec.size() == 0) {
			cout << "NOT A VALID WORD" << endl;
		} else {
#ifdef COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
			for (const auto &roString : roVec) {
#else
			for (auto roItString = roVec.cbegin(); roItString != roVec.cend(); ++roItString) {
				auto &roString = *roItString;
#endif // COMPILER_SUPPORTS_RANGE_BASED_FOR_LOOP
				cout << roString << endl;
			}
		}

		cout << "******" << endl;
	}

	return 0;
}