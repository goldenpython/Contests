/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12798 - Handball                                                 */


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

	string oLine;

	while (getline(cin, oLine)) {
		stringstream oStream(oLine);
		int nNoPlayers, nNoMatches, nSol = 0;
		oStream >> nNoPlayers >> nNoMatches;
		while (nNoPlayers--) {
			getline(cin, oLine);
			oStream.clear();
			oStream.str(oLine);
			nSol++;
			for (int nMatchIndex = 0; nMatchIndex < nNoMatches; nMatchIndex++) {
				int nNoGoals;
				oStream >> nNoGoals;
				if (!nNoGoals) {
					nSol--;
					break;
				}
			}
		}

		cout << nSol << endl;
	}

	return 0;
}