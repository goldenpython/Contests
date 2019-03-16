/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 409 - Excuses, Excuses!                                          */


#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename T>
void PrintCollection(const T &roCollection, const std::string &roDelim) {
	copy(roCollection.cbegin(), roCollection.cend(), std::ostream_iterator<typename T::value_type>(std::cout, roDelim.c_str()));
}

using namespace std;

int main() {
	const auto oNewTable = ctype<char>::classic_table();
	vector<ctype<char>::mask> oNewMask(oNewTable, oNewTable + ctype<char>::table_size);
	for (auto cChar = 1; cChar <= 255; cChar++)
		if (!isalpha(cChar))
			oNewMask[cChar] |= ctype_base::space;

	string oLine;
	for (int nN, nK, nCaseIndex = 1; getline(cin, oLine); nCaseIndex++) {
		stringstream oStream(oLine);
		oStream >> nN >> nK;

		unordered_set<string> oSetExcuses;

		while (nN--) {
			getline(cin, oLine);
			oSetExcuses.insert(move(oLine));
		}

		int nMaxExcuseScore = -1;
		vector<string> oVecoSolution;
		while (nK--) {
			getline(cin, oLine);
			stringstream oStream(oLine);
			oStream.imbue(locale(oStream.getloc(), new ctype<char>(oNewMask.data())));

			int nExcuseScore = 0;
			for (string oWord; oStream >> oWord; ) {
				transform(oWord.cbegin(), oWord.cend(), oWord.begin(), ::tolower);
				if (oSetExcuses.find(oWord) != oSetExcuses.end())
					nExcuseScore++;
			}

			if (nMaxExcuseScore < nExcuseScore) {
				oVecoSolution.clear();
				nMaxExcuseScore = nExcuseScore;
			}
			if (nMaxExcuseScore == nExcuseScore)
				oVecoSolution.push_back(move(oLine));
		}

		cout << "Excuse Set #" << nCaseIndex << endl;
		PrintCollection(oVecoSolution, "\n");
		cout << endl;
	}

	return 0;
}