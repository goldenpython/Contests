/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 10800 - Not That Kind of Graph                                   */


#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	string oLine;
	getline(cin, oLine);

	for (int nCaseLoop = 1, nNoTestCases = stoi(oLine); nCaseLoop <= nNoTestCases; nCaseLoop++) {
		cin >> oLine;
		map<int, string> oMapGraph;

		int nCurrentLine = 0, nCurrentColumn = 1;
		auto nLastChar = ' ';
		for (auto nChar : oLine) {
			switch (nChar) {
				case 'F':
					if (nLastChar == 'C' || nLastChar == 'F')
						nCurrentLine++;
					break;

				case 'R':
					if (nLastChar == 'R')
						nCurrentLine--;
					break;

				case 'C':
					if (nLastChar == 'R')
						nCurrentLine--;
					break;
			}

			auto oItCurrentLine = oMapGraph.find(nCurrentLine);
			if (oItCurrentLine == oMapGraph.end()) {
				auto oPairAfterInsert = oMapGraph.insert(make_pair(nCurrentLine, string(oLine.size() + 1, ' ')));
				oItCurrentLine = oPairAfterInsert.first;
			}

			string &roCurrentLine = oItCurrentLine->second;
			switch (nChar) {
				case 'F':
					roCurrentLine[nCurrentColumn] = '\\';
					break;

				case 'R':
					roCurrentLine[nCurrentColumn] = '/';
					break;

				case 'C':
					roCurrentLine[nCurrentColumn] = '_';
					break;
			}

			nLastChar = nChar;
			nCurrentColumn++;
		}

		cout << "Case #" << nCaseLoop << ":" << endl;
		for (auto &roPairLineString : oMapGraph) {
			auto &roString = roPairLineString.second;
			auto nPos = roString.find_last_not_of(" ");
			if (nPos != string::npos)
				roString.erase(nPos + 1);
			cout << '|' << roString << endl;
		}
		cout << '+' << string(oLine.size() + 2, '-') << endl << endl;
	}

	return 0;
}