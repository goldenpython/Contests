/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 11952 - Arithmetic                                               */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	const auto oNewTable = ctype<char>::classic_table();
	vector<ctype<char>::mask> oNewMask(oNewTable, oNewTable + ctype<char>::table_size);
	oNewMask['+'] |= ctype_base::space;
	oNewMask['='] |= ctype_base::space;
	cin.imbue(locale(cin.getloc(), new ctype<char>(oNewMask.data())));

	string oLine;
	cin >> oLine;
	for (int nN = stoi(oLine); nN--; ) {
		string oA, oB, oC;
		cin >> oA >> oB >> oC;

		if (
			oA.size() + oB.size() == oC.size() &&
			oA.find_first_not_of("1") == string::npos &&
			oB.find_first_not_of("1") == string::npos &&
			oC.find_first_not_of("1") == string::npos
		) {
			cout << 1 << endl;
			continue;
		}

		const int MAX_BASE = 25;
		int nSol = 0;
		for (int nBase = 2; nBase < MAX_BASE; nBase++) {
			try {
				int nA = stoi(oA, nullptr, nBase);
				int nB = stoi(oB, nullptr, nBase);
				int nC = stoi(oC, nullptr, nBase);
				if (nA + nB == nC) {
					nSol = nBase;
					break;
				}
			} catch (invalid_argument &oEx) {
				continue;
			} catch (out_of_range &oEx) {
				break;
			}
		}

		cout << nSol << endl;
	}

	return 0;
}
