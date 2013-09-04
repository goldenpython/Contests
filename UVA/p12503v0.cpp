/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 12503 - Robot Instructions                                       */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	const int MAX_INSTRUCTIONS = 100;

	int nNoCases;

	vector<int> oInstructions;
	oInstructions.reserve(MAX_INSTRUCTIONS);

	for (cin >> nNoCases; nNoCases--;) {
		int nNoInstructions, nPos = 0;

		oInstructions.clear();
		for (cin >> nNoInstructions; nNoInstructions--; ) {
			string oWord;
			cin >> oWord;
			if (oWord == "LEFT") {
				nPos--;
				oInstructions.push_back(-1);
			} else if (oWord == "RIGHT") {
				nPos++;
				oInstructions.push_back(+1);
			} else {
				int nInstructionIndex;
				cin >> oWord >> nInstructionIndex;
				int nInstr = oInstructions[nInstructionIndex - 1];
				nPos += nInstr;
				oInstructions.push_back(nInstr);
			}
		}

		cout  << nPos << endl;
	}

	return 0;
}