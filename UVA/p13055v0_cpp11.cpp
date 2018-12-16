/*******************************************************************************
*    Cristian Alexandrescu                                                     *
*    2163013577ba2bc237f22b3f4d006856                                          *
*    11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385          *
*    bc9a53289baf23d369484f5343ed5d6c                                          *
*******************************************************************************/

/*   Problem 13055 - Inception                                                */


#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	stack<string> oStack;
	int nNoQueries;
	for (cin >> nNoQueries; nNoQueries--; ) {
		string oWord;
		cin >> oWord;

		if (oWord == "Sleep") {
			cin >> oWord;
			oStack.emplace(oWord);
		} else if (oWord == "Test") {
			if (oStack.empty())
				cout << "Not in a dream" << endl;
			else
				cout << oStack.top() << endl;
		} else { // Kick
			if (!oStack.empty())
				oStack.pop();
		}

	}


	return 0;
}